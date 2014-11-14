/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
# include <stdio.h>

int main()
{
	int c,i,j,wspace,others;
	int calphabet[26],salphabet[26],digit[10];

	wspace=others=0;
	for(i=0;i<26;i++)
	{
		calphabet[i] = salphabet[i] = 0;
		if(i<10)
			digit[i]=0;
	}

	while ((c=getchar()) != EOF)
		if (c>='0' && c<='9')
			++digit[c-'0'];
		else if (c>='a' && c<='z')
			++salphabet[c-'a'];
		else if (c>='A' && c<='Z')
			++calphabet[c-'A'];
		else if (c==' ' || c=='\t' || c=='\n')
			++wspace;
		else
			++others;

	for(i=0;i<26;i++)
	{
		if(salphabet[i]==0)
			continue;
		printf("%c   : ",i+'a');
		for(j=0;j<salphabet[i];++j)
			printf("-");
		printf("\n");
	}

	for(i=0;i<26;i++)
	{
		if(calphabet[i]==0)
			continue;
		printf("%c   : ",i+'A');
		for(j=0;j<calphabet[i];++j)
			printf("-");
		printf("\n");
	}

	for(i=0;i<10;i++)
	{
		if(digit[i]==0)
			continue;
		printf("%c   : ",i+'0');
		for(j=0;j<digit[i];++j)
			printf("-");
		printf("\n");
	}

	printf("ws  : ");
	for(i=0;i<wspace;++i)
		printf("-");
	printf("\n");

	printf("oth : ");
	for(i=0;i<others;++i)
		printf("-");
	printf("\n");

	return 0;
}
