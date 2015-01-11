/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/

/*
https://www.hackerrank.com/challenges/quicksort4

In practice, how much faster is Quicksort (in-place) than Insertion Sort? Compare the running time of the two algorithms by counting how many swaps or shifts each one takes to sort an array, and output the difference. You can modify your previous sorting code to keep track of the swaps. The number of swaps required by Quicksort to sort any given input have to be calculated. Keep in mind that the last element of a block is chosen as the pivot, and that the array is sorted in-place as demonstrated in the explanation below.

Any time a number is smaller than the partition, it should be "swapped", even if it doesn't actually move to a different location. Also ensure that you count the swap when the pivot is moved into place. The count for Insertion Sort should be the same as the previous challenge, where you just count the number of "shifts".

Note

Please use Lomuto Partition for this challenge.

Input Format
There will be two lines of input:

    n - the size of the array
    ar - n numbers that makes up the array

Output Format
Output one integer D, where D = (insertion sort shifts) - (quicksort swaps)

Constraints
1<=n<=1000
-1000<=x<= 1000 , x ∈ ar

Sample Input

7
1 3 9 8 2 7 5

Sample Output

1
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int qsCount,isCount,ar[1000],ar2[1000];

void insertionSort(int ar_size, int *  ar) 
{
    int len=ar_size;
    int i,k,temp=ar[len-1];
    int count=0;
    for(k=1;k<len;k++)
    {
        temp=ar[k];
        for (i=k-1;i>=0 && ar[i]>temp;i--)
        {
                ar[i+1]=ar[i];
                isCount++;
        }
        ar[i+1]=temp;
    }
    return;

}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int position(int *ar, int low, int high)
{
    int temp=ar[high];
    int fPoint=low-1;
    
    for(int i=low;i<=high-1;i++)
    {
        if(ar[i]<=temp)
        {
            fPoint++;
            swap(&ar[fPoint],&ar[i]);
            qsCount++;
        }
    }
    swap(&ar[fPoint+1],&ar[high]);
    qsCount++;
    
    return fPoint+1;
}

void quicksort(int* ar, int low, int high)
{
    if(low<high)
    {
        int p=position(ar,low,high);
        quicksort(ar,low,p-1);
        quicksort(ar,p+1,high);
    }
}


int main() {
    qsCount=isCount=0;
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
        ar2[i]=ar[i];
    }
    
    insertionSort(n,ar);
    quicksort(ar2,0,n-1);
    
    cout<<isCount-qsCount<<endl;
    
    return 0;
}

