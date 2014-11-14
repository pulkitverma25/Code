/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/

/*
http://www.codechef.com/problems/HOTEL

A holiday weekend is coming up,
and Hotel Bytelandia needs to find out if it has enough rooms to accommodate all potential guests.
A number of guests have made reservations.
Each reservation consists of an arrival time, and a departure time.
The hotel management has hired you to calculate the maximum number of guests that will be at the hotel simultaneously.
Note that if one guest arrives at the same time another leaves, they are never considered to be at the hotel simultaneously
(see the second example).
Input

Input will begin with an integer T, the number of test cases.
Each test case begins with an integer N, the number of guests.
Two lines follow, each with exactly N positive integers.
The i-th integer of the first line is the arrival time of the i-th guest,
and the i-th integer of the second line is the departure time of the i-th guest
(which will be strictly greater than the arrival time).
Output

For each test case, print the maximum number of guests that are simultaneously at the hotel.
Sample Input

3
3
1 2 3
4 5 6
5
1 2 3 4 5
2 3 4 5 6
7
13 6 5 8 2 10 12
19 18 6 9 9 11 15

Sample Output

3
1
3

Constraints

    T≤100
    N≤100
    All arrival/departure times will be between 1 and 1000, inclusive

*/

#include "stdio.h"
#include <algorithm>

struct customerData
{
	int time;
	int event; //0=departure 1=arrival
};

bool sortPref(struct customerData data1,struct customerData data2)
{
	if(data1.time==data2.time)
		return data1.event<data2.event;
	return data1.time<data2.time;
}

int main()
{
	int i,k,t,custCount=0,maxCustCount=0,noOfCust;
	struct customerData tempValue;
	scanf("%d\n",&t);

	while(t--)
	{
		scanf("%d\n",&noOfCust);

		if(noOfCust==0)
		{
			printf("0\n");
			continue;
		}
		struct customerData *customerArray=(struct customerData*)malloc((sizeof(struct customerData))*2*noOfCust);
		
		for(i=0;i<2*noOfCust;i++)
		{
			scanf("%d ",&customerArray[i].time);
			if(i>=noOfCust)
				customerArray[i].event=0;
			else
				customerArray[i].event=1;
		}
		
		std::sort(customerArray,customerArray+(2*noOfCust),sortPref);
		
		maxCustCount=0;
		custCount=0;
		for(k=0;k<2*noOfCust;k++)
		{
			
			if(customerArray[k].event==0)
				custCount--;
			else
				custCount++;

			if(custCount>maxCustCount)
				maxCustCount=custCount;
		}
		printf("%d\n",maxCustCount);

		free(customerArray);
	}

	return 0;
}
