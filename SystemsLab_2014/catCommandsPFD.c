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

void cat(char *fileName,int pfd) /*custom implementation of cat*/
{
	char buffer[BUFFER_SIZE];
	FILE *fp;
	if((fp=fopen(fileName,"r"))==NULL) /*open file in read mode*/
	{
		printf("\nNo file found\n");
		exit(-1);
	}
	
	while((fgets(buffer,sizeof(buffer),fp)) != NULL) /*read line by line from file into buffer*/
		write(pfd, buffer, sizeof(buffer)); /*write buffer on pipe*/

	fclose(fp); /*close file*/
}

void grep(char * pattern,int pfd,int pfd2) /*custom implementation of grep excluding regular expressions*/
{
	int i,j;
	char buffer[BUFFER_SIZE],*tempBuffer, *tempPattern;
	int stringSize=strlen(pattern);
	
	tempPattern=(char *)malloc(sizeof(char)*stringSize+1);
	
	while (read(pfd, buffer, sizeof(buffer)) > 0) 
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
				write(pfd2, buffer, strlen(buffer)); /*write on pipe if pattern found in line*/
				break;
			}

		}
		free(tempBuffer);
	}
	free(tempPattern);
	return;
}

void wc(int pfd) /*custom implementation of wc*/
{
	char tempChar;
	unsigned long int lineCount=0,wordCount=0,charCount=0;
	int isSpaceStart=0;

	while (read(pfd, &tempChar, 1) > 0) /*read from pipe character by character*/
	{
		charCount++;
		if(tempChar=='\n') /*if newline found then increment line count*/
			lineCount++;
			
		if(isspace(tempChar)) /*if any space character founr*/
		{		
			if(isSpaceStart) /*if continous space then no need to increment word count*/
				continue;
			
			isSpaceStart=1;
			wordCount++;
		}
		else
			isSpaceStart=0;
	}

	printf("%7lu %7lu %7lu\n",lineCount,wordCount,charCount);
	return;
}

