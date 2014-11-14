/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
#include <stdio.h>

#define MAXLINE 1000
//Newline character at the end of each line is included in these limits.

int getLine(char [] , int );
int removeBlanks(char [] , int );

int main()
{
	int len,newLen;     				   			
	char line[MAXLINE];	
	
	len=newLen=0;
	while( (len = getLine(line,MAXLINE)) > 0 )
		if((newLen = removeBlanks(line , len)) >1)
			printf("%s",line);

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

int removeBlanks (char s[], int len)
{
	int i;

	i=len-2; //First char to the left of '\n'

	if(s[len-1]=='\n') //sanity check
		while(s[i]==' ' || s[i]=='\t') 
		//if any space to the left of newline
			--i;

	s[i+1]='\n';
	s[i+2]='\0';

	return i+2; //new length
}
