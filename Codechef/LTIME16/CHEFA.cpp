/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
http://www.codechef.com/LTIME16/problems/CHEFA/

Chef and Roma are playing a game. Rules of the game are quite simple.
Initially there are N piles of stones on the table.
In each turn, a player can choose one pile and remove it from the table.
Each player want to maximize the total number of stones removed by him.
Chef takes the first turn.

Please tell Chef the maximum number of stones he can remove assuming that both players play optimally.
Input

The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.

The first line of each test case contains a single integer N denoting the number of piles.

The second line contains N space separated integers A1, A2, ..., AN denoting the number of stones in each pile.
Output

For each test case, output a single line containg the maximum number of stones that Chef can remove.
Constraints

    1 ≤ Ai ≤ 109
    Subtask 1 (35 points): T = 10, 1 ≤ N ≤ 1000
    Subtask 2 (65 points): T = 10, 1 ≤ N ≤ 105

Example

Input:
2
3
1 2 3
3
1 2 1

Output:
4
3
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
vector <ll>v(100001);

bool compare (ll a, ll b)
{
  return a>b;
}

int main()
{
  ll t;
  cin>>t;
  
  while(t--)
  {
    ll n;
    cin>>n;

    for(int i=0;i<n;i++)
      cin>>v[i];
      
    sort(v.begin(),v.begin()+n,compare);
    ll ans=0;
    for(int i=0;i<n;i++)
      if(!(i&1))
        ans+=v[i];
        
    cout<<ans<<endl;   
  }
}
