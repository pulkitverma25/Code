/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/

/*
https://www.hackerrank.com/challenges/quicksort1

You're given an array ar and a number p. Partition the array, so that, all elements greater than p are to its right, and all elements smaller than p are to its left.

In the new sub-array, the relative positioning of elements should remain the same, i.e., if n1 was before n2 in the original array, it must remain before it in the sub-array. The only situation where this does not hold good is when p lies between n1 and n2

i.e., n1 > p > n2.

Guideline - In this challenge, you do not need to move around the numbers 'in-place'. This means you can create 2 lists and combine them at the end.

Input Format
You will be given an array of integers. The number p is the first element in ar.

There are 2 lines of input:

    n - the number of elements in the array ar
    the n elements of ar (including p at the beginning)

Output Format
Print out the numbers of the partitioned array on one line.

Constraints
1<=n<=1000
-1000<=x<= 1000 , x ∈ ar
All elements will be distinct

Sample Input

5
4 5 3 7 2

Sample Output

3 2 4 5 7

Explanation
p = 4. The 5 was moved to the right of the 4, 2 was moved to the left of 4 and the 3 is also moved to the left of 4. The numbers otherwise remained in the same order.

Task
Complete the method partition which takes an array ar. The first element in ar is the number p. 
*/

#include <bits/stdc++.h>

using namespace std;

void partition(vector <int>  ar) 
{
    int p=ar[0];
    vector<int>small;
    vector<int>large;
    
    int len=ar.size();
    
    for(int i=1;i<len;i++)
        if(ar[i]<p)
            small.push_back(ar[i]);
        else
            large.push_back(ar[i]);
        
    int smallLen=small.size();
    int bigLen=large.size();
    
    for(int i=0;i<smallLen;i++)
        cout<<small[i]<<" ";
    cout<<p<<" ";
    for(int j=0;j<bigLen;j++)
        cout<<large[j]<<" ";
    cout<<endl;

    return;
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

	partition(_ar);

	return 0;
}

