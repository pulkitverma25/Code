/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
http://www.codechef.com/problems/DECSTR

 You need to find a string which has exactly K positions in it such that the character at that position comes alphabetically later than the character immediately after it. If there are many such strings, print the one which has the shortest length. If there is still a tie, print the string which comes the lexicographically earliest (would occur earlier in a dictionary).
Input

The first line contains the number of test cases T. Each test case contains an integer K (≤ 100).
Output

Output T lines, one for each test case, containing the required string. Use only lower-case letters a-z.
Sample Input

2
1
2

Sample Output

ba
cba
*/

#include <iostream>

using namespace std;
char a[26];

void printRemainingNos(int num)
{
	if (num==0)
		return;

	for(int i=num; i>=0; i--)
		cout<<a[i];
	
	return;
}

int main()
{
	for (int i=0; i<26; i++)
		a[i]=i+97;
	int t,remCount;
	cin >> t;

	while(t--)
	{
		int count;
		cin >> count;

		if (count>25)
		{
			int noOfTimes=count/25;
			remCount=count%25;
			printRemainingNos(remCount);
			
			for (int i=0; i<noOfTimes; i++)
				for(int j=25; j>=0; j--)
					cout<<a[j];									
		}
		else
			printRemainingNos(count);

		cout<<endl;
	}
	return 0;
}
