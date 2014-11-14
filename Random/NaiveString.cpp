/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/

/*
Given a text txt[0..n-1] and a pattern pat[0..m-1], write a function search(char pat[], char txt[]) that prints all occurrences of pat[] in txt[]. You may assume that n > m. 
*/

#include <stdio.h>
#include <cstring>

bool searchForString(char* pattern, char* text, int *index)
{
	char *temp;
	int sizeP=strlen(pattern);
	int sizeT=strlen(text);

	for(int i=0; i<sizeT-sizeP+1; i++)
	{
		int j;
		for(j=i; j<i+sizeP; j++)
		{
			if(text[j]!=pattern[j-i])
				break;
		}
		if(j==sizeP+i)
		{
			*index=i;
			return true;
		}
	}
	return false;
}

void findAllOccurance(char* pattern, char* text)
{
	char *temp;
	int sizeP=strlen(pattern);
	int sizeT=strlen(text);

	for(int i=0; i<sizeT-sizeP+1; i++)
	{
		int j;
		for(j=i; j<i+sizeP; j++)
		{
			if(text[j]!=pattern[j-i])
				break;
		}
		if(j==sizeP+i)
		{
			printf("String found at index %d\n",i);
		}
	}
	return ;
}

int main()
{
	char *txt = "AABAACAADAABAAABAA";
	char *pat = "AABA";
	int index=-1;
	
	bool isStringFound= searchForString(pat, txt,&index);
	if(isStringFound)
		printf("String found at index %d\n",index);
	else
		printf("String not found!!\n");
	
	findAllOccurance(pat, txt);
	return 0;
}
