/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
https://www.hackerrank.com/challenges/mark-and-toys

Mark and Jane are very happy after having their first kid. Their son is very fond of toys, so Mark wants to buy some. There are N different toys lying in front of him, tagged with their prices, but he has only $K. He wants to maximize the number of toys he buys with this money.

Now, you are Mark's best friend and have to help him buy as many toys as possible.

Input Format
The first line contains two integers, N and K, followed by a line containing N space separated integers indicating the products' prices.

Output Format
An integer that denotes maximum number of toys Mark can buy for his son.

Constraints
1<=N<=105
1<=K<=109
1<=price of any toy<=109
A toy can't be bought multiple times.

Sample Input

7 50
1 12 5 111 200 1000 10

Sample Output

4

Explanation

He can buy only 4 toys at most. These toys have the following prices: 1,12,5,10.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(const int a, const int b)
{
    return a<b;    
}

int main() 
{
    long long n, k; cin >> n >> k;
    vector<int> prices;
    for(int i = 0; i < n; i++)
    {
        int p; cin >> p;
        prices.push_back(p);
    }
    sort(prices.begin(), prices.end(),compare);
    
    int answer = 0;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=prices[i];
        if(sum<=k)
            answer++;
        else
            break;
    }
    
    cout << answer << endl;
    
    return 0;
}

