/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
https://www.hackerrank.com/challenges/gem-stones

John has discovered various rocks. Each rock is composed of various elements, and each element is represented by a lowercase latin letter from 'a' to 'z'. An element can be present multiple times in a rock. An element is called a 'gem-element' if it occurs at least once in each of the rocks.

Given the list of N rocks with their compositions, display the number of gem-elements that exist in those rocks.

Input Format
The first line consists of N, the number of rocks.
Each of the next N lines contain rocks' composition. Each composition consists of lowercase letters of English alphabet.

Output Format
Print the number of gem-elements that are common in these rocks. If there are none, print 0.

Constraints
1 ≤ N ≤ 100
Each composition consists of only lowercase latin letters ('a'-'z').
1 ≤ Length of each composition ≤ 100

Sample Input

3
abcdde
baccd
eeabg

Sample Output

2

Explanation
Only "a", "b" are the two kind of gem-elements, since these are the only characters that occur in each of the rocks' composition.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int n,i,array[26],len,ans=0;
    char* string;
    scanf("%d\n",&n);
    
    if(n==1)
    {   
        string=(char*)malloc(sizeof(char)*101);
        scanf("%s\n",string);
        len=strlen(string);
     
        printf("%d\n",len);
        free(string);
        return 0;
    }

    for(i=0;i<26;i++)
        array[i]=0;
    
    for(i=0;i<n;i++)
    {
        int j;
        string=(char*)malloc(sizeof(char)*101);
        scanf("%s\n",string);
        
        len=strlen(string);
        
        for(j=0;j<len;j++)
        {
            if(array[string[j]-'a']==i)
                array[string[j]-'a']++;
        }
        
        free(string);
    }
    
    for(i=0;i<26;i++)
        if(array[i]==n)
            ans++;
    
    printf("%d\n",ans);
    return 0;
}

