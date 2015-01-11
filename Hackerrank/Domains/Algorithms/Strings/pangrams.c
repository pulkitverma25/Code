/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
https://www.hackerrank.com/challenges/pangrams

Roy wanted to increase his typing speed for programming contests. So, his friend advised him to type the sentence "The quick brown fox jumps over the lazy dog" repeatedly because it is a pangram. ( pangrams are sentences constructed by using every letter of the alphabet at least once. )

After typing the sentence several times, Roy became bored with it. So he started to look for other pangrams.

Given a sentence s, tell Roy if it is a pangram or not.

Input Format

Input consists of a line containing s.

Constraints
Length of s can be atmost 103 (1≤|s|≤103) and it may contain spaces, lowercase and uppercase letters. Lowercase and uppercase instances of a letter are considered same.

Output Format

Output a line containing pangram if s is a pangram, otherwise output not pangram.

Sample Input #1

We promptly judged antique ivory buckles for the next prize    

Sample Output #1

pangram

Sample Input #2

We promptly judged antique ivory buckles for the prize    

Sample Output #2

not pangram

Explanation

In the first testcase, the answer is pangram because the sentence contains all the letters.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    char string[1001];
    int i,alphabet[26];
    
    fgets(string,1001,stdin);
    
    if(strlen(string)<26)
        printf("not pangram\n");
    else
    {
        for(i=0;i<strlen(string);i++)
        {
            if(string[i]<='z' && string[i]>='a')
                alphabet[string[i]-'a']=1;
            else if (string[i]<='Z' && string[i]>='A')
                alphabet[string[i]-'A']=1;
        }
        for(i=0;i<26;i++)
            if(alphabet[i]!=1)
            {
                printf("not pangram\n");
                return 0;
            }
        printf("pangram\n");
    }
    
    return 0;
}

