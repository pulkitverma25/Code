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
	double x=100.1,y;
	printf("Addr of x1 = %d \n",&x);
	printf("Value at addr of x1 = %d \n",*(&x));	
	int *p;

	p=(int *)&x;

	y=*p;

	printf("y = %f \n",y);
	printf("Addr of p = %d \n",&p);	
	printf("Addr of x2 = %d \n",&x);
	printf("Value at addr of x2 = %d \n",*(&x));	


	return 0;
}

