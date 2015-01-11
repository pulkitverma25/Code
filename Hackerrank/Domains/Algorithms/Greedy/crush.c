/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
https://www.hackerrank.com/challenges/crush

Devendra is on cloud nine after seeing his crush smiling at him in class. At that very moment his professor singles him out and asks him a question. Devendra's mind is all too fuzzy with his crush and her smile to concentrate on anything else. Help him solve the problem :

You are given a list of size N, initialized with zeroes. You have to perform M operations on the list and output the maximum of final values of all the N elements in the list. For every operation, you are given three integers a, b and k and you have to add value k to all the elements ranging from index a to b(both inclusive).

Input Format
First line will contain two integers N and M separated by a single space.
Next M lines will contain three integers a, b and k separated by a single space.
Numbers in list are numbered from 1 to N.

Output Format
A single line containing maximum value in the updated list.

Constraints
3 ≤ N ≤ 107
1 ≤ M ≤ 2 * 105
1 ≤ a ≤ b ≤ N
0 ≤ k ≤ 109

Sample Input #00

5 3
1 2 100
2 5 100
3 4 100

Sample Output #00

200

Explanation

After first update list will be 100 100 0 0 0.
After second update list will be 100 200 100 100 100.
After third update list will be 100 200 200 200 100.
So the required answer will be 200.

Note

The initial testcases are easy and naive solutions might pass. Only efficient solutions can pass the additional testcases. 
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    long int n,m,i,max,tempSum,*array;
    scanf("%ld %ld\n",&n,&m);
    
    array =(long int*)malloc(sizeof(long int)*(n+1));
    
    for(i=0;i<=n;i++)
        array[i]=0;    
    
    while(m--)
    {
        long int start,end,value;
        scanf("%ld %ld %ld\n",&start,&end,&value);
        
        array[start-1]+=((-1)*value);
        array[end]+=value;        
    }
    max=0;
    tempSum=0;
    for(i=n;i>=0;i--)
    {
        tempSum+=array[i];
        if(tempSum>max)
            max=tempSum;
    }
    printf("%ld\n",max);
    
    free(array);
    
    return 0;
}

