/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
https://www.hackerrank.com/contests/fun-3-0/challenges/cakewalk

A positive integer is called a palindrome if its representation in the decimal system is the same when read from left to right and from right to left. For a given positive integer K of not more than 1000000 digits, write the value of the smallest palindrome larger than K to output. Numbers are always displayed without leading zeros.

Input Format

The first line contains integer t, the number of test cases. Followed by t lines containing integers K.

Output Format

For each K, output the smallest palindrome larger than K.

Sample Input

2
808
2133

Sample Output

818
2222
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    string a;
    int i,l,m,k,t;
	bool isAllNine,isChecked;
    cin>>t;

    while(t--)
    {
        isAllNine=true;
        cin>>a;
        l=a.size();

        k=l>>1;

        for(i=0;i<l;i++)
            if(a[i]!='9')
            {
                isAllNine=false;
                break;
            }

        if(isAllNine)
        {
            a[0]='1';
            for(i=1;i<l;i++)
            	a[i]='0';
            a+="1";
			cout<<a<<endl;
            continue;
        }

        bool isMidSmaller=false;

		for(i=0;i<k;i++)
		{
			if(a[i]<a[l-1-i])
				isMidSmaller=false;
			else if(a[i]>a[l-1-i])
				isMidSmaller=true;		
		    a[l-1-i]=a[i];
		}

		m= (!(l&1))?	k-1 : k;

		if(!isMidSmaller)
		{
		    i=0;
		    while(a[m-i]=='9')
		    {
		        a[m-i]='0';
		        a[l-1-m+i]='0';
		        i++;
		    }

		    a[m-i]++;
		    a[l-1-m+i]=a[m-i];
		}
		cout<<a<<endl;
    }

    return 0;
}

