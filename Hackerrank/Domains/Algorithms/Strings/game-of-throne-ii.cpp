/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
https://www.hackerrank.com/challenges/game-of-throne-ii

Now that the king knows how to find out whether a given word has an anagram which is a palindrome or not, he encounters another challenge. He realizes that there can be more than one palindrome anagrams for a given word. Can you help him find out how many palindrome anagrams are possible for a given word ?

The king has many words. For each given word, he needs to find out the number of palindrome anagrams of the string. As the number of anagrams can be large, the king needs the number of anagrams % (109+ 7).

Input format :
A single line which contains the input string

Output format :
A single line which contains the number of anagram strings which are palindrome % (109 + 7).

Constraints :
1<=length of string <= 10^5
Each character of the string is a lowercase alphabet.
Each test case has at least 1 anagram which is a palindrome.

Sample Input 01 :

aaabbbb

Sample Output 01 :

3 

Explanation :
Three palindrome permutations of the given string are abbabba , bbaaabb and bababab.

Sample Input 02 :

cdcdcdcdeeeef

Sample Output 02 :

90
*/

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

#define MOD 1000000007
#define RANGE 50000

long long int fact[RANGE], invfact[RANGE];
 
long long int powmod(long long int base, long long int expo)
{
	if(expo==0)
		return 1;
	else if(expo&1)
		return (long long)base*powmod(base, expo-1)%MOD;
	else{
		long long int root=powmod(base, expo>>1);
		return (long long)root*root%MOD;
	}
}
 
long long int inverse(long long int x)
{
	return powmod(x, MOD-2);
}
 
void init()
{
	fact[0]=1;
	for(long long int i=1; i<=RANGE; i++)
		fact[i]=(long long)i*fact[i-1]%MOD;
	invfact[RANGE]=inverse(fact[RANGE]);
	for(long long int i=RANGE; i>0; i--)
		invfact[i-1]=(long long)i*invfact[i]%MOD;
}
 
int main() 
{
    init();

    char arr[100001];
    int i,array[26],oddCount=0,len=0;
    scanf("%s",arr);
    
    len=strlen(arr);
    for(i=0;i<26;i++)
        array[i]=0;
    
    for(i=0;i<len;i++)
        array[arr[i]-'a']++;

    long long int noOfWays=fact[(len/2)]%MOD;
    for(int i=0;i<26;i++)
        if(array[i]>2)
            noOfWays =(noOfWays*(invfact[(array[i]/2)]%MOD))%MOD;

    cout<<noOfWays<<endl;
    
    return 0;
}

