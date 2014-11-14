/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 * @year	2014
 **********************************************************/

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "customCommands.h"

#define KEY1 5678
#define KEY2 5679

struct inpCommands
{
	char *str1;
	char *str2;
	int methodID;
	char *argv1;
	char *argv2;
};

int lock=0;

void *chooseFunction (void *threadArg)
{
	struct inpCommands *threadData;

	char s1[BUFFER_SIZE],s2[BUFFER_SIZE];

	threadData=(struct inpCommands *)threadArg;
	strcpy(s1,threadData->str1);
	
	strcpy(s2,threadData->str2);
	if(threadData->methodID==0 && lock==0)
	{
		cat(threadData->argv1,s1);
		
		lock=1;
	}
	else if(threadData->methodID==1)
	{
		printf("%s",s1);
		while(lock!=1);
		grep(threadData->argv2,s1,s2);
		printf("%s",s2);
		lock=2;
	}
	else if(threadData->methodID==2)
	{
		while(lock!=2);
		wc(s2);
	}

	pthread_exit(NULL);
}

int main(int argc, char* argv[])
{
	char c;
	int i;
	int shmid,shmid2;
	key_t key,key2;
	char *shm,*shm2, *s,*s2;
	key = KEY1;
	key2= KEY2;

	if ((shmid = shmget(key, BUFFER_SIZE, IPC_CREAT | 0666)) < 0) { //write data on 
		perror("shmget");
		exit(1);
	}
	if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
		perror("shmat");
		exit(1);
	}
	s = shm;

	if ((shmid2 = shmget(key2, BUFFER_SIZE, IPC_CREAT | 0666)) < 0) { //write data on 
		perror("shmget");
		exit(1);
	}
	if ((shm2 = shmat(shmid2, NULL, 0)) == (char *) -1) {
		perror("shmat");
		exit(1);
	}
	s2 = shm2;

	//Creates the thread array to store the threads to be created
	pthread_t *threads=(pthread_t*)malloc(sizeof(pthread_t)*3);
	struct inpCommands *threadParamArray=(struct inpCommands*)malloc(sizeof(struct inpCommands)*3);
	
	for(i=0;i<3;i++)
	{
		int thCreateStatus;
		threadParamArray[i].str1=s;
		threadParamArray[i].str2=s2;
		threadParamArray[i].methodID=i;
		threadParamArray[i].argv1=argv[1];
		threadParamArray[i].argv2=argv[2];
		thCreateStatus = pthread_create(&threads[i], NULL, chooseFunction, (void *) &threadParamArray[i]);
		if (thCreateStatus)
		{
  		     printf("ERROR; return code from pthread_create() is %d\n", thCreateStatus);
  		     exit(-1);
       		}
	}

	for(i=0;i<3;i++) 
	{
		int thJoinStatus;
		void* status;
		thJoinStatus=pthread_join(threads[i],&status);
		if(thJoinStatus)
			fprintf(stderr,"Thread %d terminated with status %d\n",i,thJoinStatus);
	}	

	return 0;
}
