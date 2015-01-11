/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
https://www.hackerrank.com/challenges/game-of-thrones

King Robert has 7 kingdoms under his rule. He finds out from a raven that the Dothraki are soon going to wage a war against him. But, he knows the Dothraki need to cross the Narrow River to enter his realm. There is only one bridge that connects both banks of the river which is sealed by a huge door.

door

The king wants to lock the door so that the Dothraki can't enter. But, to lock the door he needs a key that is an anagram of a certain palindrome string.

The king has a string composed of lowercase English letters. Help him figure out if any anagram of the string can be a palindrome or not.

Input Format
A single line which contains the input string

Constraints
1<=length of string <= 10^5
Each character of the string is a lowercase English letter.

Output Format
A single line which contains YES or NO in uppercase.

Sample Input : 01

aaabbbb

Sample Output : 01

YES

Explanation
A palindrome permutation of the given string is bbaaabb.

Sample Input : 02

cdefghmnopqrstuvw

Sample Output : 02

NO

Explanation
You can verify that the given string has no palindrome permutation.

Sample Input : 03

cdcdcdcdeeeef

Sample Output : 03

YES

Explanation
A palindrome permutation of the given string is ddcceefeeccdd.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
 
int main() {

    char arr[100001];
    int i,array[26],oddCount=0,len=0;
    scanf("%s",arr);
    
    len=strlen(arr);
    for(i=0;i<26;i++)
        array[i]=0;
    
    for(i=0;i<len;i++)
        array[arr[i]-'a']++;
        
    for(i=0;i<26;i++)
        if(array[i]&1)
        {
            oddCount++;
            if(oddCount>1)
            {
                printf("NO\n");
                return 0;
            }    
        }
    
    printf("YES\n");  
    return 0;
}

