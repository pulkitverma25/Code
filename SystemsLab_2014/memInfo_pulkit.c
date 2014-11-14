/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 * @year	2014
 **********************************************************/

#include <linux/kernel.h>
#include <linux/unistd.h>
#include <linux/syscalls.h>
#include <memInfo_struct.h>
#include <linux/slab.h>
#include <linux/string.h>
#include <linux/fs.h>
#include <asm/segment.h>
#include <asm/uaccess.h>
#include <linux/buffer_head.h>

struct file* file_open(const char* path, int flags, int rights) {
    struct file* filp = NULL;
    mm_segment_t oldfs;
    int err = 0;

    oldfs = get_fs();
    set_fs(get_ds());
    filp = filp_open(path, flags, rights);
    set_fs(oldfs);
    if(IS_ERR(filp)) {
        err = PTR_ERR(filp);
        return NULL;
    }
    return filp;
}

void file_close(struct file* file) {
    filp_close(file, NULL);
}

int file_read(struct file* file, unsigned long long offset, unsigned char* data, unsigned int size) {
    mm_segment_t oldfs;
    int ret;

    oldfs = get_fs();
    set_fs(get_ds());

    ret = vfs_read(file, data, size, &offset);

    set_fs(oldfs);
    return ret;
}
/*
void reverse(char str[], int length)
{
    int start = 0;
    int end = length -1;
    while (start < end)
    {
        swap(*(str+start), *(str+end));
        start++;
        end--;
    }
    return;
}

void intToString(long unsigned num, char* str)
{
	int i = 0;
	while (num != 0)
    {
        int rem = num % 10;
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        num = num/10;
    }
    str[i] = '\0';
    reverse(str, i);

    return ;
}
*/

asmlinkage struct memInfo_pulkit_struct* sys_memInfo_pulkit(void)
{
	int task_Count;

	//char tempValue[] = "/proc/";
	//char tempValue2[] = "/statm";

	struct task_struct *task;
	struct memInfo_pulkit_struct temp_memInfo;
	struct memInfo_pulkit_struct *memInfo;
	memInfo = (struct memInfo_pulkit_struct*) kmalloc(sizeof(struct memInfo_pulkit_struct),GFP_KERNEL);
	//struct memInfo_pulkit_struct *full_memInfo;
	task_Count = 0;
	
	for_each_process(task)
	{
		char pidInChar[50];
		//char src [20];
		char buf[50];
		struct file* filp;
		//pidInChar[0]=(char)'\0';
		temp_memInfo.comm[0] = (char)'\0';
		printk("System Call 1 \n");

		strcpy(temp_memInfo.comm,task->comm);
		printk("System Call 2 \n");
		temp_memInfo.pid=task_pid_nr(task);
		printk("System Call 3 \n PID = %d\n",temp_memInfo.pid);


		
		sprintf(pidInChar, "/proc/%d/statm",temp_memInfo.pid);

		//intToString(temp_memInfo.pid,pidInChar);
		//printk("System Call 3.25 \n");
		//strcat(tempValue,pidInChar);
		//printk("System Call 3.5 \n");
		//strcat(tempValue,tempValue2);
		//printk("System Call 4 \ntempValue= %s",tempValue);
		printk("System Call 4 pidInChar\ntempValue= %s",pidInChar);
		filp = file_open(pidInChar, O_RDONLY, 0);
		printk("System Call 4.25 \n");
		file_read(filp, 0, buf, 50);
		sscanf(buf, "%lu", &temp_memInfo.memSize);
		printk("System Call 4.5 \n");
        file_close(filp);
		/*
		struct mm_struct *tempMm = task -> mm;
		printk("System Call 3.25 \n");
		temp_memInfo.memSize= (tempMm->total_vm);
		printk("System Call 3.5 \n");
		temp_memInfo.memSize = temp_memInfo.memSize << PAGE_SHIFT;
		printk("System Call 4 \n");
		*/
		printk("System Call 4.75 \n");
		task_Count++;

		//printk("System Call  \n");
		printk("System Call 5 : %d \nCOMM = %s PID = %d SIZE=%lu",task_Count,temp_memInfo.comm, temp_memInfo.pid,temp_memInfo.memSize);
		//printk("System Call 5 : %d \nCOMM = %s PID = %d SIZE=%lu",task_Count,temp_memInfo.comm, temp_memInfo.pid);
		//full_memInfo  = (struct memInfo_pulkit_struct*) krealloc(memInfo,task_Count*sizeof(struct memInfo_pulkit_struct),GFP_KERNEL);
		memInfo  = (struct memInfo_pulkit_struct*) krealloc(memInfo,task_Count*sizeof(struct memInfo_pulkit_struct),GFP_KERNEL);

		printk("System Call 6 : %d \n",task_Count);

		if(memInfo !=NULL)
		{
			//memInfo = full_memInfo;
			printk("System Call 7 \n");
			memInfo[task_Count-1]=temp_memInfo;
			printk("System Call 8 \n");
		}
		else
		{
			printk("Error Reallocating Memory\n");
		}

		printk("System Call 9 : %d \n",task_Count);
		//printk("%s  - %d - %lu \n", task->comm, task-> pid, (task -> mm->total_vm)<< PAGE_SHIFT);		
		printk("System Call FINAL : %d \nCOMM = %s PID = %d SIZE=%lu \n",task_Count,temp_memInfo.comm, temp_memInfo.pid,temp_memInfo.memSize);
		//printk("System Call FINAL : %d \nCOMM = %s PID = %d SIZE=%lu \n",task_Count,temp_memInfo.comm, temp_memInfo.pid);
		printk("System Call 10 \n");
	}
	return memInfo;
}
