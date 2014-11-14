/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 * @year	2013
 **********************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "DynamicArray.h"

int main()
{
	int choice, exitButton, actualSize,size,currentSize=0,tempNumber,tempNumber2;
	char choice2;
	int *array;
	do
	{
		system("clear");
		printf("MENU\n");
		printf("1. Create Array\n");
		printf("2. Add Element at End\n");
		printf("3. Add Element at Random Position\n");		
		printf("4. Delete Element at End\n");
		printf("5. Delete Element at Random Position\n");
		printf("6. Search Element\n");
		printf("7. Exit\n");

		printf("\nEnter your choice: ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("Enter the initial size: ");
				scanf("%d",&actualSize);

				size=actualSize*2;
				array=(int*)malloc(size*sizeof(int));
				currentSize=0;
				break;

			case 2:
				printf("Enter the element you want to add: ");
				scanf("%d",&tempNumber);
				addElement(array, tempNumber, currentSize+1, &size, &actualSize, &currentSize);
				printArray(array,currentSize);				
				break;

			case 3:
				printf("Enter the position at which you want to add: ");
				scanf("%d",&tempNumber2);
				printf("Enter the element you want to add: ");
				scanf("%d",&tempNumber);
				addElement(array, tempNumber, tempNumber2, &size, &actualSize, &currentSize);
				printArray(array,currentSize);				
				break;

			case 4:
				deleteElement(array, currentSize, &size, &actualSize, &currentSize);
				printArray(array,currentSize);				
				break;

			case 5:
				printf("Enter the position at which you want to delete: ");
				scanf("%d",&tempNumber);
				deleteElement(array, tempNumber, &size, &actualSize, &currentSize);
				printArray(array,currentSize);				
				break;

			case 6: 
				printf("Enter the element you want to search: ");
				scanf("%d",&tempNumber);
				tempNumber2=searchArray(array,tempNumber,currentSize);
				printArray(array,currentSize);
				if(tempNumber2==-1)
					printf("\nElement Not Found.\n");
				else
					printf("\nElement found at location %d from the starting.\n",tempNumber2+1);
				break;

			case 7:
				exit(0);

		};
		
		printf("\nEnter any number to continue: ");
		scanf("%d",&exitButton);
	}while(choice!=7 || exitButton!=0);


}
