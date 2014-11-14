/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
#include <stdio.h>

#define MAXLINE 1000

int getLine(char [] , int );
void copy(char [] , char [] );

int main()
{
	int len,max;
	char line[MAXLINE],longest[MAXLINE];	
	
	max=len=0;
	while( (len = getLine(line,MAXLINE)) > 0 )
		if(len>max)
		{
			max=len;
			copy(longest,line);
		}

	if (max>0)
		printf("%s\n",longest);

	return 0;
}

int getLine (char s[], int lim)
{
	int c,i;

	for(i=0;i<lim-1 && (c=getchar())!= EOF && c!='\n'; ++i)
		s[i]=c;

	if(c=='\n')
	{
		s[i]=c;
		++i;
	}
	
	s[i]='\0';

	return i;	
}

void copy(char to[], char from[])
{
	int i;

	i=0;
	while((to[i]=from[i]) != '\0')
		++i;

	return;
}