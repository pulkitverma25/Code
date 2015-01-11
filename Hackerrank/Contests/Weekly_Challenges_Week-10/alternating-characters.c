/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
https://www.hackerrank.com/contests/w10/challenges/alternating-characters

Shashank likes strings in which consecutive characters are different. For example, he likes ABABA, while he doesn't like ABAA. Given a string containing characters A and B only, he wants to change it into a string he likes. To do this, he is allowed to delete the characters in the string.

Your task is to find the minimum number of required deletions.

Input Format
The first line contains an integer T i.e. the number of test cases.
Next T lines contain a string each.

Output Format
Print minimum number of required steps for each test case.

Constraints

1≤T≤10
1≤lengthofString≤105

Sample Input

5
AAAA
BBBBB
ABABABAB
BABABA
AAABBB

Sample Output

3
4
0
0
4

Explanation

AAAA⟹A, 3 deletions
BBBBB⟹B, 4 deletions
ABABABAB⟹ABABABAB, 0 deletions
BABABA⟹BABABA, 0 deletions
AAABBB⟹AB, 4 deletions
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int t;
    scanf("%d\n",&t);
        
    while(t--)
    {
        char c;
        char oldC=' ';
        int count=0;
        while((c=getchar())!='\n' && c!=EOF)
        {
            
            if(c==oldC)
                count++; 
			oldC=c;               
        }
        printf("%d\n",count);
    }
    return 0;
}

