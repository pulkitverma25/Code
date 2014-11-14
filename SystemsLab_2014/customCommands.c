/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 * @year	2014
 **********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include "customCommands.h"

void cat(char *fileName,char *shm) /*custom implementation of cat*/
{
	FILE *fp;
	char buffer[BUFFER_SIZE];
	if((fp=fopen(fileName,"r"))==NULL) /*open file in read mode*/
	{
		printf("\nNo file found\n");
		exit(-1);
	}
	
	shm[0]='\0';
	while((fgets(buffer,sizeof(buffer),fp)) != NULL) /*read line by line from file into buffer*/
		strcat(shm,buffer);	

	fclose(fp); /*close file*/
	return;
}

void grep(char * pattern,char *shm1,char *shm2) /*custom implementation of grep excluding regular expressions*/
{
	int i,j;

	char *buffer,*tempBuffer, *tempPattern;
	int stringSize=strlen(pattern);

	tempPattern=(char *)malloc(sizeof(char)*stringSize+1);

	buffer = strtok (shm1,"\n");
	shm2[0]='\0';
	while (buffer != NULL) 
	{

		tempBuffer=(char *)malloc((strlen(buffer)+1)*sizeof(char));
		for(i=0;i<strlen(buffer);i++)
		{
			j=0;
			strcpy(tempPattern,pattern); /*copy pattern into temp variable*/
			strcpy(tempBuffer,buffer+i); /*increment the position of starting point by i*/
			
			if(*tempPattern!='\0' && *tempPattern==*tempBuffer) /*if 1st character of patten occurs in buffer*/
			{
				for(j=0;j<stringSize;)
				{
					if(*tempPattern != *tempBuffer) /*if mismatch found the break*/
						break;
					tempPattern++;

					tempBuffer++;	
					j++;
				}
			}
			
			tempBuffer-=j;
			tempPattern-=j;
			if(j==stringSize)
			{
				strcat(shm2,buffer);
				strcat(shm2,"\n");
				break;
			}

		}
		
		free(tempBuffer);
		buffer=strtok (NULL,"\n");
	}
	free(tempPattern);
	return;
}

void wc(char *shm) /*custom implementation of wc*/
{
	char tempChar=shm[0];
	int i=0;
	unsigned long int lineCount=0,wordCount=0,charCount=0;
	int isSpaceStart=0;

	if(isspace(shm[0]))
		isSpaceStart=1;
	while ((tempChar!='\0' || tempChar!=EOF) && i<strlen(shm)) /*read from pipe character by character*/
	{
		charCount++;
		if(tempChar=='\n') /*if newline found then increment line count*/
			lineCount++;
			
		if(isspace(tempChar)) /*if any space character found*/
		{		
			if(isSpaceStart) /*if continous space then no need to increment word count*/
			{
				i++;
				tempChar=shm[i];
				continue;
			}
			
			isSpaceStart=1;
			wordCount++;
		}
		else
			isSpaceStart=0;

		i++;
		tempChar=shm[i];
	}

	printf("%7lu %7lu %7lu\n",lineCount,wordCount,charCount);
	return;
}

