/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/

/*
https://www.hackerrank.com/challenges/quicksort2

In Insertion Sort, you simply went through each element in order and inserted it into a sorted sub-array. In this challenge, you cannot focus on one element at a time, but instead must deal with whole sub-arrays, with a strategy known as "divide and conquer".

When partition is called on an array, two parts of the array get 'sorted' with respect to each other. If partition is then called on each sub-array, the array will now be split into 4 parts. This process can be repeated until the sub-arrays are small. Notice that when partition is called on just two numbers, they end up being sorted.

Can you repeatedly call partition so that the entire array ends up sorted?

Print Sub-Arrays
In this challenge, print your array every time your partitioning method finishes, i.e. print every sorted sub-array The first element in a sub-array should be used as a pivot. Partition the left side before partitioning the right side. The pivot should not be added to either side. Instead, put it back in the middle when combining the sub-arrays together.

Input Format
There will be two lines of input:

    n - the size of the array
    ar - the n numbers of the array

Output Format
Print every partitioned sub-array on a new line.

Constraints
1<=n<=1000
-1000<=x<= 1000 , x ∈ ar
There are no duplicate numbers.

Sample Input

7
5 8 1 3 7 9 2

Sample Output
2 3
1 2 3
7 8 9
1 2 3 5 7 8 9

Task
The method quickSort takes in a parameter, ar, an unsorted array. Use the QuickSort Algorithm to sort the entire array
*/

#include <bits/stdc++.h>

using namespace std;

int partition(vector <int> &ar, int low, int high) 
{
    vector<int>small;
    vector<int>large;
    
    int len=high-low+1;
    int p=ar[low];

    for(int i=low+1;i<=high;i++)
        if(ar[i]<p)
            small.push_back(ar[i]);
        else
            large.push_back(ar[i]);

    int smallLen=small.size();
    int bigLen=large.size();
    
    for(int i=0;i<smallLen;i++)
        ar[i+low]=small[i];
    ar[smallLen+low]=p;
    for(int j=0;j<bigLen;j++)
        ar[smallLen+j+low+1]=large[j];
    
    return smallLen+low;
}

void quickSort(vector <int> &ar, int low, int high) 
{
    if(low<high)
    {
        int p= partition(ar,low,high);
        
        quickSort(ar, low, p - 1);
        quickSort(ar, p + 1, high);
        for(int i=low;i<=high;i++)
            cout<<ar[i]<<" ";
        cout<<endl;
    }
}

int main(void) {
    vector <int>  _ar;
    
    int _ar_size;
    cin >> _ar_size;
    
    for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) 
    {
        int _ar_tmp;
        cin >> _ar_tmp;
        _ar.push_back(_ar_tmp); 
    }

    quickSort(_ar, 0,_ar_size-1);
    
   return 0;
}

