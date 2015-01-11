/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/

/*
https://www.hackerrank.com/challenges/runningtime

Can you modify your previous Insertion Sort implementation to keep track of the number of shifts it makes while sorting? The only thing you should print is the number of shifts made by the insertion sort algorithm to completely sort the array. A shift occurs when an element's position changes in the array. (Do not shift an element if it is not necessary.)

Input Format
The first line contains N, the number of elements to be sorted. The next line contains N integers a[1],a[2]...,a[N].

Output Format
Output the number of shifts it takes.

Constraints
1<=N<=1001
-10000 <= x <= 10000 , x ∈ a

Sample Input
5
2 1 3 1 2

Sample Output
4

Explanation
The first '1' is shifted once. The '3' stays where it is. The next '1' gets shifted twice. The final '2' gets shifted once. Hence, the total number of shifts is 4.

Task
For this problem, you can copy your code from the InsertionSort problem, and modify it to keep track of the number of shifts, instead of printing the array.
*/

#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <iostream>

using namespace std;

void insertionSort(int ar_size, int *  ar) {
    int len=ar_size;
    int i,k,temp=ar[len-1];
    int count=0;
    for(k=1;k<len;k++)
    {
        temp=ar[k];
        for (i=k-1;i>=0 && ar[i]>temp;i--)
        {
                ar[i+1]=ar[i];
                count++;
        }
        ar[i+1]=temp;
    }
    cout<<count<<endl;
    return;
}

int main(void) 
{   
    int _ar_size;
    cin >> _ar_size;

    int _ar[_ar_size], _ar_i;

    for(_ar_i = 0; _ar_i < _ar_size; _ar_i++)  
        cin >> _ar[_ar_i];

   insertionSort(_ar_size, _ar);
   
   return 0;
}
