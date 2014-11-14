/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/

/*
Use of pointers
*/

#include <stdio.h>

int main(){
	system ("clear");
	int x,*p1,*p2;
	int y=sizeof(int);
	p1=&x;
	p2=p1;
	
	printf("Addr of x = %p \nAddress in decimals = %d\n",p2,&x);
	printf("Size of int = %d \n",y);
	
	p2++;
	printf("Addr of x++ = %p \nAddress in decimals=%d\n",p2,p2);

	return 0;
}

