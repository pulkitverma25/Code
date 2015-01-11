/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/

/*
https://www.hackerrank.com/challenges/countingsort1

Given a list of integers, can you count and output the number of times each value appears?

Hint: There is no need to sort the data, you just need to count it.

Input Format
There will be two lines of input:

    n - the size of the list
    ar - n space separated numbers that makes up the list

Output Format
Output the number of times every number from 0 to 99 (inclusive) appears in the list.

Constraints
100 <= n <= 106
0 <= x < 100 , x ∈ ar

Sample Input

100
63 25 73 1 98 73 56 84 86 57 16 83 8 25 81 56 9 53 98 67 99 12 83 89 80 91 39 86 76 85 74 39 25 90 59 10 94 32 44 3 89 30 27 79 46 96 27 32 18 21 92 69 81 40 40 34 68 78 24 87 42 69 23 41 78 22 6 90 99 89 50 30 20 1 43 3 70 95 33 46 44 9 69 48 33 60 65 16 82 67 61 32 21 79 75 75 13 87 70 33 

Sample Output

0 2 0 2 0 0 1 0 1 2 1 0 1 1 0 0 2 0 1 0 1 2 1 1 1 3 0 2 0 0 2 0 3 3 1 0 0 0 0 2 2 1 1 1 2 0 2 0 1 0 1 0 0 1 0 0 2 1 0 1 1 1 0 1 0 1 0 2 1 3 2 0 0 2 1 2 1 0 2 2 1 2 1 2 1 1 2 2 0 3 2 1 1 0 1 1 1 0 2 2 

Explanation

the output states that 0 appears 0 times.
1 appears 2 times.
2 appears 0 times.
and so on in the given input array
*/

#include <bits/stdc++.h>
using namespace std;
int arr[100];

int main() {
    int n,m;
    cin>>n;
    m=n;
    memset(arr,0,sizeof(arr));
    
    while(m--)
    {
        int num;
        cin>>num;
        arr[num]++;
    }
    for(int i=0;i<100;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    
    return 0;
}

