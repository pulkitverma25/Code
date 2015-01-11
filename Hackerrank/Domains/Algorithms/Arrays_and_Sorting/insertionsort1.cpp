/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/

/*
https://www.hackerrank.com/challenges/insertionsort1

Given a sorted list with an unsorted number V in the right-most cell, can you write some simple code to insert V into the array so it remains sorted?

Print the array every time a value is shifted in the array until the array is fully sorted. The goal of this challenge is to follow the correct order of insertion sort.

Guideline: You can copy the value of V to a variable, and consider its cell "empty". Since this leaves an extra cell empty on the right, you can shift everything over until V can be inserted. This will create a duplicate of each value, but when you reach the right spot, you can replace a value with V.

Input Format
There will be two lines of input:

    s - the size of the array
    ar - the sorted array of integers

Output Format
On each line, output the entire array every time an item is shifted in it.

Constraints
1<=s<=1000
-10000<=x<= 10000, x ∈ ar

Sample Input

5
2 4 6 8 3

Sample Output

2 4 6 8 8 
2 4 6 6 8 
2 4 4 6 8 
2 3 4 6 8 

Explanation

3 is removed from the end of the array.
In the 1st line 8 > 3, 8 is shifted one cell right.
In the 2nd line 6 > 3, 6 is shifted one cell right.
In the 3rd line 4 > 3, 4 is shifted one cell right.
In the 4th line 2 < 3, 3 is placed at position 2.

Task

Complete the method insertionSort which takes in 1 parameter:

    ar - an array with the value V in the right-most cell.
*/

#include <bits/stdc++.h>

using namespace std;

void insertionSort(vector <int>  ar) 
{
    int len=ar.size();
    int i,temp=ar[len-1];
    for (i=len-2;i>=0;i--)
    {
        if(ar[i]>temp)
            ar[i+1]=ar[i];
        else
            break;
        for(int j=0;j<len;j++)
            cout<<ar[j]<<" ";
        cout<<endl;
    }
    ar[i+1]=temp;
    for(int j=0;j<len;j++)
        cout<<ar[j]<<" ";
    cout<<endl;

    return;
}
int main(void) 
{
	vector <int>  _ar;
	int _ar_size;
	cin >> _ar_size;
	for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) 
	{
		int _ar_tmp;
		cin >> _ar_tmp;
		_ar.push_back(_ar_tmp); 
	}

	insertionSort(_ar);
   
   return 0;
}

