/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
https://www.hackerrank.com/contests/fun-3-0/challenges/judgement-day

This is year 2029 AD. Science has progressed a lot. 2029AD is mentioned here because this problem is being sent back to 1995 AD with reprogrammed T-800 Terminator. Now (in 2029 AD) it is possible to establish direct connection between man and computer CPU. People can watch other people’s dream on 3D displayer (that is the monitor in 1995) as if they were watching a movie. One problem in this century is that people have become so dependent on computers that their analytical ability is approaching zero. Computers can now read problems and solve them automatically. But they can solve only difficult problems. There are no easy problems now.

John Connor is in great trouble as he has forgotten the number of his combination lock which is very crucial for saving his younger self from Skynet's T-1000 Terminator. For security reasons computers today cannot solve combination lock related problems. On one night John Connor has a dream where he sees a lot of unsigned integer numbers flying around. He records them with the help of his computer, then he has a clue that if the numbers are (X1,X2,…,Xn) he will have to find an integer number A (This A is the combination lock code) such that

(|X1−A|+|X2−A|+……+|Xn−A|) is minimum.

Help John Connor and T-800 to save humanity on Judgement Day.

Input

Input will contain t test cases. First line will contain value of t. Each test case will have 2 lines. First line will contain a number n indicating how many numbers John Connor saw in his dream. In next line there will be n numbers. All the numbers will be less than 65536.

Output

For each set of input there will be one line of output. That line will contain the minimum possible value for A. And also you have to print how many possible different integer values are there for A (these values need not be present in the input). These numbers will be separated by single space.

Constraints

1<=t<=1000

0<n<=106

0<=X1,X2,…,Xn<65536

Sample Input

2
2
10 10
4
1 2 2 4

Sample Output

10 1
2 1
*/

#include <bits/stdc++.h>

using namespace std;

const int nr_max = 65536;
int arr [1000000];

int main()
{
  	int n,t;
	cin>>t;
  	while (t--) 
	{
		cin>>n;
		memset(arr, 0, sizeof(arr));
		for (int i = 0; i < n; i++) 
			cin >>  arr[i];

		sort(arr, arr+n);

		if (n & 1) // median is unique
			cout << arr[n/2 ] << ' ' << 1 << endl;
		else
			cout << arr[n/2 -1] << ' ' << arr[n/2 ] - arr[n/2 - 1] + 1 << endl;
  	}
	return 0;
}
