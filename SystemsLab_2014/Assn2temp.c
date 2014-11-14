#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

struct thread_Param
{
	int currI;
	int currJ;
	int nC;
	int mC;
	int mA;
	int **matrixA;
	int **matrixB;
	int **matrixC;
};

void *calcCellValue(void *threadArg)
{
	struct thread_Param *threadData;
	int i;
	threadData=(struct thread_Param *)threadArg;
	threadData->matrixC[threadData->currI][threadData->currJ]=0;

	for(i=0;i<threadData->mA;i++)
		threadData->matrixC[threadData->currI][threadData->currJ]+=threadData->matrixA[threadData->currI][i]*threadData->matrixB[i][threadData->currJ];

	pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
   
	int i,j,t,nA,nB,mA,mB; /*matrix A (nA X mA)and B (nB X mB) such that mA=nB*/
	int **matrixA,**matrixB,**matrixC;


	scanf("%d %d\n",&nA,&mA);
	scanf("%d %d\n",&nB,&mB);

	if(mA!=nB)
	{
		printf("Matrix cannot be multiplied\nExiting Now...\n");
		exit(0);
	}		
	
	void* status;
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
	
	
	pthread_t *threads=(pthread_t*)malloc(sizeof(pthread_t)*(nA*mB));
	struct thread_Param *threadParamArray=(struct thread_Param*)malloc(sizeof(struct thread_Param)*(nA*mB));
	
  	for(i=0;i<nA;i++)
		for(j=0;j<mB;j++)
		{
			int rc;
			long t;
			threadParamArray[i*mB+j].nC=nA;
			threadParamArray[i*mB+j].mC=mB;
			threadParamArray[i*mB+j].mA=mA;
			threadParamArray[i*mB+j].currI=i;
			threadParamArray[i*mB+j].currJ=j;
			threadParamArray[i*mB+j].matrixA=matrixA;
			threadParamArray[i*mB+j].matrixB=matrixB;
			threadParamArray[i*mB+j].matrixC=matrixC;
			rc = pthread_create(&threads[i*mB+j], NULL, calcCellValue, (void *) &threadParamArray[i*mB+j]);
			if (rc)
			{
	  		     printf("ERROR; return code from pthread_create() is %d\n", rc);
	  		     exit(-1);
	       		}
		}

	for(i=0;i<nA*mB;i++) //To stop parent from terminiting before all threads being terminated
	{
		int thJoinStatus;
		thJoinStatus=pthread_join(threads[i],&status);
		if(thJoinStatus)
			fprintf(stderr,"Thread %d terminated with status %d\n",i,(int *)status);
	}
	printf("Matrix C:\n");
	for(i=0;i<nA;i++)
	{
		for(j=0;j<mB;j++)
			printf("%4d ",matrixC[i][j]);
		printf("\n");
	}

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

}

