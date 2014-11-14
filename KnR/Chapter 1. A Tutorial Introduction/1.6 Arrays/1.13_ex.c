/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/***************************************************************
Note: It can work only if the file has less than the number of 
words mentioned in WORD_CAPACITY. It is the limitation of Array
implementation used. To remove this constraint, use file I/O.

Compile: gcc -o <executable> <.c file>
Usage: <executable> < <input_file>

***************************************************************/

#include <stdio.h>

#define IN 1
#define OUT 0
#define WORD_CAPACITY 10000

int main()
{
	int c, i, j, wc, wl, wlMax, state, wlength[WORD_CAPACITY];
	
	state=OUT;
	wc=wl=wlMax=0;
	for(i=0; i<WORD_CAPACITY; ++i)
		wlength[i]=0;

	while((c=getchar()) != EOF)
	{
		if(c==' ' || c== '\t' || c=='\n')
		{
			if(state==IN)
				wlength[wc-1]=wl;
			if(wl>wlMax)
				wlMax=wl;
			state=OUT;
		}
		else if(state == OUT)
		{
			++wc;
			if(wc>WORD_CAPACITY)
			{
				printf("\nMaximum word limit exceeded.\n");
				break;
			}
			wl=0;
			state=IN;
		}

		if(state==IN)
			++wl;
	}

	printf("\n\nHorizontal Histogram\n\n");	
	for(i=0;i<wc;++i)
	{
		for(j=0;j<wlength[i];++j)
			printf("-");
		printf("\n");
	}

	printf("\n\nVertical Histogram\n\n");
	for(i=0;i<wlMax;++i)
	{
		for(j=0;j<wc;++j)
			if(wlMax-wlength[j] <= i)
				printf("|");
			else
				printf(" ");
		printf("\n");
	}
	
	return 0;
}
