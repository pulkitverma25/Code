/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
http://www.codechef.com/LTIME17/problems/HEADBOB/

Tanu has got interested in signs and gestures that we use for communication. One such gesture is the head-bob.
When we want to signal "Yes" to someone, we move the head up-and-down. For "No", the head is moved left-and-right, rotating about the vertical axis.
There is a peculiar way of gesturing "Yes", commonly seen in India, by moving head sideways (rotating about the forward-back axis). This is called the Indian head-bob.

Tanu observed many people on the railways station, and made a list of gestures that they made. Usual "Yes" gesture is recorded as "Y", no as "N" and Indian "Yes" gesture as "I". (Assume no foreigner uses the Indian "Yes" gesture and vice-versa). Identify which of them were Indians, which were not Indian, and which one you cannot be sure about.
Input

First line contains T, number of people observed by Tanu.
Each person is described in two lines. First line of the description contains a single integer N, the number of gestures recorded for this person. Next line contains a string of N characters, each character can be "Y", "N" or "I".
Output

For each person, print "INDIAN" if he/she is from India, "NOT INDIAN" if not from India, and "NOT SURE" if the information is insufficient to make a decision.
Constraints

    For 30 points: 1 ≤ T,N ≤ 100
    For 70 points: 1 ≤ T,N ≤ 1000

Example

Input:

3
5
NNNYY
6
NNINNI
4
NNNN


Output:

NOT INDIAN
INDIAN
NOT SURE
*/

#include <cstdio>

using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		char c;
		bool isN=true;
		bool isI=false;
		bool isY=false;
		for(int i=0;i<n;i++)
		{
			scanf(" %c",&c);
			if(!isN && c=='N')
				isN=true;
			if(!isY && c=='Y')
				isY=true;
			if(!isI && c=='I')
				isI=true;
		}
		if(isI)
			printf("INDIAN\n");
		else if(isY)
			printf("NOT INDIAN\n");
		else if (isN)
			printf("NOT SURE\n");
	}
	return 0;
}
