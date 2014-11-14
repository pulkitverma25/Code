#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/wait.h>
#include <unistd.h>

#include "customCommands.h"


int main(int argc, char *argv[])
{
	int pfd[2],pfd1[2]; 
        pid_t c_pid,c_pid1;  /* child process id */ 
       
	if (pipe(pfd) == -1) 
	 	exit(1);

  	c_pid = fork();
	if (c_pid == -1) 
	 	exit(1);

        /* following program segment will be executed by child process */
	if (c_pid == 0) 
	{  
		if (pipe(pfd1) == -1) 
		 	exit(1);

	  	c_pid1 = fork();
		if (c_pid1 == -1) 
		 	exit(1);

	        /* following program segment will be executed by child process */
		if (c_pid1 == 0) 
		{  
			close(pfd[0]);
			close(pfd[1]);
			close(pfd1[1]);
			wc(pfd1[0]);
			close(pfd1[0]);
			exit(1);

		} 
	        /*  following will be executed by parent process  */
		else {  
			close(pfd[1]);
			close(pfd1[0]);
			grep(argv[2],pfd[0],pfd1[1]);
			close(pfd[0]);
			close(pfd1[1]);
			wait(NULL); /* Wait for child */ 
			exit(1); 
		} 
	} 
        /*  following will be executed by parent process  */
	else {  
		close(pfd[0]);
		close(pfd1[0]);
		close(pfd1[1]);
 		cat(argv[1],pfd[1]);
		close(pfd[1]);
		wait(NULL); 
		exit(EXIT_SUCCESS); 
	}
	
	return 0;
}





