/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
https://www.hackerrank.com/contests/iit-guwahati-placement-preparation-test-1/challenges/lazy-mainak

Mainak is a very intelligent senior. So a first year comes to him and asks him a question

Given two number a and b, you need to find the largest integer x which divides both a and b. Also you need to find the smallest integer y which is divided by both a and b .

Now mainak is feeling very lazy ( as usual), so he asks you to solve the question :
Input:

First line contains a single integer T - denoting no. of test cases . T lines follow. Each line contain two integers a and b
Output:

For each test cases, print x and y seperated by a (see sample output)
Constraints:

1 <= T <= 200
1 <= a,b <= 10^4
Sample Input:

3  
1 3  
2 4  
3 2

Sample Output:

1 - 3  
2 - 4  
1 - 6
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int ll;


int main() {
    int t;
    scanf("%d\n",&t);
    
    while(t--)
    {
        ll num1,num2;
        scanf("%lld %lld\n",&num1,&num2);
        
        ll maxVal=num1*num2;
        while(num1!=num2)
        {
            if(num1>num2)
                num1-=num2;
            else
                num2-=num1;
        }
        
        printf("%lld - %lld\n",num1,maxVal/num1);       
    }
    return 0;
}

