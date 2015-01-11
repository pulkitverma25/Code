/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
https://www.hackerrank.com/challenges/make-it-anagram

Alice recently started learning about cryptography and found that anagrams are very useful. Two strings are anagrams of each other if they have same character set. For example strings "bacdc" and "dcbac" are anagrams, while strings "bacdc" and "dcbad" are not.

Alice decides on an encryption scheme involving 2 large strings where encryption is dependent on the minimum number of character deletions required to make the two strings anagrams. She need your help in finding out this number.

Given two strings (they can be of same or different length) help her in finding out the minimum number of character deletions required to make two strings anagrams. Any characters can be deleted from any of the strings.

Input Format
Two lines each containing a string.

Constraints
1 <= Length of A,B <= 10000
A and B will only consist of lowercase latin letter.

Output Format
A single integer which is the number of character deletions.

Sample Input #00:

cde
abc

Sample Output #00:

4

Explanation #00:
We need to delete 4 characters to make both strings anagram i.e. 'd' and 'e' from first string and 'b' and 'a' from second string. 
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int arr[26];

int main() 
{
    string string1,string2;
    cin>>string1>>string2;
    
    int len1=(int)string1.size();
    int len2=(int)string2.size();
    
    for(int i=0;i<len1;i++)
        arr[string1[i]-'a']++;
    for(int i=0;i<len2;i++)
        arr[string2[i]-'a']--;
    
    int sum=0;
    for(int i=0;i<26;i++)
        sum+=abs(arr[i]);
    
    cout<<sum<<endl;
    return 0;
}

