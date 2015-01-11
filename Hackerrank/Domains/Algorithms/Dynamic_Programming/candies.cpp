/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
https://www.hackerrank.com/challenges/candies

Alice is a kindergarden teacher. She wants to give some candies to the children in her class.  All the children sit in a line, and each  of them has a rating score according to his or her performance in the class.  Alice wants to give at least 1 candy to each child. If two children sit next to each other, then the one with the higher rating must get more candies. Alice wants to save money, so she needs to minimize the total number of candies.

Input
The first line of the input is an integer N, the number of children in Alice's class. Each of the following N lines contains an integer that indicates the rating of each child.

Ouput
Output a single line containing the minimum number of candies Alice must buy.

Constraints
1 <= N <= 105
1 <= ratingi <= 105

Sample Input

3  
1  
2  
2

Sample Ouput

4

Explanation
Here 1, 2, 2 is the rating. Note that when two children have equal rating, they are allowed to have different number of candies. Hence optimal distribution will be 1, 2, 1.
*/

#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long int ll;
ll arr[100000];
ll choc[100000];

int main() 
{
    ll n;
    cin>>n;
    
    ll count=1;
    ll maxCount=0;
       
    memset(arr,0,sizeof(arr));
    scanf("%lld\n",&arr[0]);
    ll maxVal=arr[0];
    for(ll i=1;i<n;i++)
        cin>>arr[i], maxVal=max(maxVal,arr[i]);
    
    choc[0]=1;
    for(ll i=1;i<n;i++)
    {
        if(arr[i]==arr[i-1])
            choc[i]=1;
        else if(arr[i]>arr[i-1])
            choc[i]=choc[i-1]+1;
        else
        {
            ll tempC=0;
            ll j=i;
            while(j<n && arr[j]<arr[j-1])
            {
                tempC++;
                j++;
            }
            if(i>1 && choc[i-2]<choc[i-1])
                choc[i-1]=max(choc[i-2]+1,tempC+1);
            else if (i>1 && choc[i-2]==choc[i-1])
            	choc[i-1]=max(1LL,tempC+1);
            else
                choc[i-1]=tempC+1;
            while(i<j)
            {
               choc[i]=tempC;
               tempC--;
               i++;
            }
            i--;
        }
        
    }
    
    printf("%lld\n",accumulate(choc, choc+n, 0));
    return 0;
}

