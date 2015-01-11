/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
https://www.hackerrank.com/challenges/is-fibo

You are given an integer, N. Write a program to determine if N is an element of the Fibonacci Sequence.

The first few elements of fibonacci sequence are 0,1,1,2,3,5,8,13,⋯ A fibonacci sequence is one where every element is a sum of the previous two elements in the sequence. The first two elements are 0 and 1.

Formally:
fib0fib1⋮fibn=0=1=fibn−1+fibn−2∀n>1

Input Format
The first line contains T, number of test cases.
T lines follows. Each line contains an integer N.

Output Format
Display IsFibo if N is a fibonacci number and IsNotFibo if it is not a fibonacci number. The output for each test case should be displayed in a new line.

Constraints
1≤T≤105
1≤N≤1010

Sample Input

3
5
7
8

Sample Output

IsFibo
IsNotFibo
IsFibo

Explanation
5 is a Fibonacci number given by fib5=3+2
7 is not a Fibonacci number
8 is a Fibonacci number given by fib6=5+3
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define RANGE 51
vector <long long int> fib(RANGE);

void generateFibNos()
{
    fib[0]=1;
    fib[1]=1;
    for(long long int i=2;i<RANGE;i++)     
        fib[i]=fib[i-1]+fib[i-2];
}

int main() 
{
    generateFibNos();   
    
    int t;
    cin>>t;
    
    while(t--)
    {
        long long int num;
        cin>>num;

        if(binary_search(fib.begin(), fib.end(), num))
 		cout << "IsFibo" << '\n';
	else 
		cout << "IsNotFibo" << '\n';
          
    }
    
    return 0;
}
