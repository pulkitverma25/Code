/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
https://www.hackerrank.com/challenges/acm-icpc-team

You are given a list of N people who are attending ACM-ICPC World Finals. Each of them are either well versed in a topic or they are not. Find out the maximum number of topics a 2-person team can know. And also find out how many teams can know that maximum number of topics.

Input Format

The first line contains two integers N and M separated by a single space, where N represents the number of people, and M represents the number of topics. N lines follow.
Each line contains a binary string of length M. If the ith line's jth character is 1, then the ith person knows the jth topic and doesn't know the topic otherwise.

Output Format

On the first line, print the maximum number of topics a 2-person team can know.
On the second line, print the number of 2-person teams that can know the maximum number of topics.

Constraints
2 ≤ N ≤ 500
1 ≤ M ≤ 500

Sample Input

4 5
10101
11100
11010
00101

Sample Output

5
2

Explanation
(1, 3) and (3, 4) know all the 5 topics. So the maximal topics a 2-person team knows is 5, and only 2 teams can achieve this.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
string binaryArray[500];

int main() {
    int n,m;
    cin>>n>>m;
    
    for(int i=0;i<n;i++)
        cin>>binaryArray[i];
    int count=0;
    int maxMCount=0;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
        {
            int mCount=0;
            for(int k=0;k<m;k++)
                if(binaryArray[i][k]=='1' || binaryArray[j][k]=='1')
                    mCount++;
                
            if(mCount>maxMCount)
            {
                count=1;
                maxMCount=mCount;
            }
            else if (mCount==maxMCount)
                count++;
                
        }
    
    cout<<maxMCount<<endl<<count<<endl;
    return 0;
}

