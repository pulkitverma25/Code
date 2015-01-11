/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
https://www.hackerrank.com/contests/fun1/challenges/macntoss

Mac is a BIG time gambler and also he likes to cheat by counting sequences, he mostly gambles on dice and toss games. But today he is in big trouble, he has put all his money on a game. You can help him by solving this problem:

Given a sequence of toss outcomes {H,T} of lenght n, and a value b you have to count occurrances of every possible sequence of length b (as there are 2^b possible sequences of length b, and they may be overlapping in input sequence). You have to consider T to be smaller than H, i.e sequence for b = 3 will {TTT, TTH,...,HHH}.

Input : First line contains t, i.e number of test cases. Next there are 2t lines, and for each test case first line is b and next line is the sequence n.

You can assume that every line of sequence n ends with new line character ('\n').

Output : For each test case print the number of occurrances for each sequence of length b.

Constraints : 1<= t <= 200, 2 <= b <= 15 , b <= |n| <= 1000

Sample Input


4
3
HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
3
TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT
2
HHTTTHHTTTHTHHTHHTTHTTTHHHTHTTHTTHTTTHTH
3
HTHTHHHTHHHTHTHHHHTTTHTTTTTHHTTTTHTHHHHT

Sample Output


0 0 0 0 0 0 0 38 
38 0 0 0 0 0 0 0 
11 11 11 6 
6 3 4 5 3 6 5 6 

Explanation for case 1: There are 38 occurrances of HHH (as b=3), and no other sequences of lenght 3 exists, so all 0's.

Explanation for case 2: As there are 11 occurrances of TT, 11 of TH, 11 of TH, and 6 of HH.
*/

#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long int ull;

ull arr[32768];

int main() {
    ull t;
    cin>>t;
    
    while(t--)
    {
        memset(arr,0,sizeof(arr));
        ull b;
        cin>>b;
        
        string s;
        cin>>s;
        ull len=s.size();
        ull num=0;
        for(ull i=0;i<b;i++)
            if(s[i]=='H')
                num+=(1<<(b-i-1));
        ull toSub=(1<<(b-1));
        arr[num]++;
        for(ull i=b;i<len;i++)
        {
            if(s[i-b]=='H')
                num-=toSub;
            num<<=1;
            if(s[i]=='H')
                num+=1;
            arr[num]++;
        }
        
        for(ull i=0;i<(1<<b);i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
    
    return 0;
}

