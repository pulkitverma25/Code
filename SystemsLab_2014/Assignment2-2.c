/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 * @year	2014
 **********************************************************/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

//Shared among all threads
int **matrixA,**matrixB,**matrixC;

struct thread_Param
{
	int currI;
	int currJ;
	int mA;
};

//Called by every thread
void *calcCellValue(void *threadArg)
{
	struct thread_Param *threadData;
	int i;
	threadData=(struct thread_Param *)threadArg;
	matrixC[threadData->currI][threadData->currJ]=0;

	//Calculates the value for each position in the matrix
	for(i=0;i<threadData->mA;i++)
		matrixC[threadData->currI][threadData->currJ]+=matrixA[threadData->currI][i]*matrixB[i][threadData->currJ];

	pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
   	//matrix A (nA X mA)and B (nB X mB) such that mA=nB
	int i,j,nA,nB,mA,mB; 

	scanf("%d %d\n",&nA,&mA);
	scanf("%d %d\n",&nB,&mB);

	if(mA!=nB)
	{
		printf("Matrix cannot be multiplied\nExiting Now...\n");
		exit(0);
	}		
	
	//Allocates memory to matrices A, B and C depending upon input values
	matrixA=(int**)malloc(sizeof(int*)*nA);
	for(i=0;i<nA;i++)
		matrixA[i]=(int*)malloc(sizeof(int)*mA);

	for(i=0;i<nA;i++)
		for(j=0;j<mA;j++)
			scanf("%d ",&matrixA[i][j]);
	
	
	matrixB=(int**)malloc(sizeof(int*)*nB);
	for(i=0;i<nB;i++)
		matrixB[i]=(int*)malloc(sizeof(int)*mB);

	for(i=0;i<nB;i++)
		for(j=0;j<mB;j++)
			scanf("%d ",&matrixB[i][j]);

	matrixC=(int**)malloc(sizeof(int*)*nA);
	for(i=0;i<nA;i++)
		matrixC[i]=(int*)malloc(sizeof(int)*mB);
	
	
	//Creates the thread array to store the threads to be created
	pthread_t *threads=(pthread_t*)malloc(sizeof(pthread_t)*(nA*mB));
	struct thread_Param *threadParamArray=(struct thread_Param*)malloc(sizeof(struct thread_Param)*(nA*mB));
	
  	for(i=0;i<nA;i++)
		for(j=0;j<mB;j++)
		{
			int thCreateStatus;
			//setting parameters to be passed in thread
			threadParamArray[i*mB+j].mA=mA;
			threadParamArray[i*mB+j].currI=i;
			threadParamArray[i*mB+j].currJ=j;

			//Creates the thread and passes values.
			thCreateStatus = pthread_create(&threads[i*mB+j], NULL, calcCellValue, (void *) &threadParamArray[i*mB+j]);
			if (thCreateStatus)
			{
	  		     printf("ERROR; return code from pthread_create() is %d\n", thCreateStatus);
	  		     exit(-1);
	       		}
		}

	//To stop parent from terminiting before all threads being terminated
	for(i=0;i<nA*mB;i++) 
	{
		int thJoinStatus;
		void* status;
		thJoinStatus=pthread_join(threads[i],&status);
		if(thJoinStatus)
			fprintf(stderr,"Thread %d terminated with status %d\n",i,thJoinStatus);
	}

	//Prints the Matrix C
	printf("Matrix C:\n");
	for(i=0;i<nA;i++)
	{
		for(j=0;j<mB;j++)
			printf("%4d ",matrixC[i][j]);
		printf("\n");
	}

	//frees the memory allocated in the program
	free(threadParamArray);
	free(threads);
	for(i=0;i<nB;i++)
		free(matrixB[i]);
	free(matrixB);
	for(i=0;i<nA;i++)
	{
		free(matrixA[i]);
		free(matrixC[i]);
	}
	free(matrixA);
	free(matrixC);

	return 0;
}

