/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
// KMP algorithm implementation

#include <stdio.h>
#include <cstring>
#include <stdlib.h>

void computeLPSArray(char *pattern, int m, int *lpsArray);
void kmp(char *pattern, char* text);
	
int main()
{
	char *txt = "fdfsfdfdf";
	char *pat = "fsf";

	kmp(pat, txt);
	return 0;
}

void computeLPSArray(char *pattern, int m, int *lpsArray)
{
	int len,i;
	len=0;
	i=1;
	lpsArray[0]=0;

	while(i<m)
	{
		if(pattern[i]==pattern[len])
		{
			len++;
			lpsArray[i]=len;
			i++;
		}
		else if (pattern[i]!=pattern[len])
		{
			if(len==0)
			{
				lpsArray[i]=len;
				i++;
			}
			else if (len !=0)
			{
				len=lpsArray[len-1];
			}
		}
	}
	return;
}

void kmp(char *pattern, char* text)
{
	int sizeP=strlen(pattern);
	int sizeT=strlen(text);
	int *lpsArray=(int*)malloc(sizeof(int)*sizeP);

	computeLPSArray(pattern, sizeP, lpsArray);

	for(int i=0;i<sizeP;i++)
		printf("%d ",lpsArray[i]);
	printf("\n");	
	int j=0;
	int i=0;


	while(i<sizeT)
	{
		if(pattern[j]==text[i])
		{
			i++; j++;
		}

		if(j==sizeP)
		{
			printf("String found at index %d\n",i-j);
			j=lpsArray[j-1];
		}

		else if (pattern[j]!=text[i])
		{
			if(j!=0)
				j=lpsArray[j-1];
			else
				i++;
		}
	}
	free(lpsArray);
}
