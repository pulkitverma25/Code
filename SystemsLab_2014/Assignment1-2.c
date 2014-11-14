/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 * @year	2014
 **********************************************************/

#include <sys/wait.h>
#include <stdlib.h> 
#include <unistd.h> 


int main(int argc, char *argv[])
{
	int pfd[2],pfd1[2],status; 
        pid_t c_pid,c_pid1;  /* child process id */ 
       
	if (pipe(pfd1) == -1) 
	 	exit(1);

  	c_pid = fork(); /*create new process*/
	if (c_pid == -1) 
	 	exit(1);

        /* following program segment will be executed by child process */
	if (c_pid == 0) 
	{  
		if (pipe(pfd) == -1) 
		 	exit(1);

	  	c_pid1 = fork(); /*create new process*/
		if (c_pid1 == -1) 
		 	exit(1);

	        /* following program segment will be executed by child process */
		if (c_pid1 == 0) 
		{  
			dup2(pfd[1],STDOUT_FILENO); /*write output on stdout*/
			close(pfd1[0]);
			close(pfd1[1]);
			close(pfd[0]); 
			execlp("cat","cat",argv[1],NULL);
		} 
	        /*  following will be executed by parent process*/
		else {  
			c_pid1=wait(&status); /*wait till child terminates*/
			dup2(pfd[0],STDIN_FILENO); /*read the input from stdin*/
			dup2(pfd1[1],STDOUT_FILENO); /*write thw output on stdout*/
			close(pfd[1]);
			close(pfd1[0]);
			execlp("grep","grep",argv[2],NULL);
		} 
	} 
        /*  following will be executed by parent process  */
	else {  
		c_pid=wait(&status); /*wait till child terminates*/
		dup2(pfd1[0],STDIN_FILENO); /*read the input from stdin*/
		close(pfd[0]);
		close(pfd[1]);
		close(pfd1[1]);
		execlp("wc","wc",NULL);
	}
	
	return 0;
}
