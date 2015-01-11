/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
https://www.hackerrank.com/contests/iit-guwahati-placement-preparation-test-02/challenges/snape-and-dragons

Snape is stuck on a level of the MMORPG he is playing now. To move on in the game, he's got to defeat all n dragons that live on this level. Snape and the dragons have strength, which is represented by an integer. In the duel between two opponents the duel's outcome is determined by their strength. Initially, Snape's strength equals s.

If Snape starts duelling with the i-th (1 ≤ i ≤ n) dragon and Snape's strength is not greater than the dragon's strength xi, then Snape loses the duel and dies. But if Snape's strength is greater than the dragon's strength, then he defeats the dragon and gets a bonus strength increase by yi.

Snape can fight the dragons in any order. Determine whether he can move on to the next level of the game, that is, defeat all dragons without a single loss.

Input

The first line contains two space-separated integers s and n (1 ≤ s ≤ 10^13, 1 ≤ n ≤ 10^6). Then n lines follow: the i-th line contains space-separated integers xi and yi (1 ≤ xi ≤ 10^13, 0 ≤ yi ≤ 10^13) — the i-th dragon's strength and the bonus for defeating it.

Output

On a single line print "YES" (without the quotes), if Snape can move on to the next level and print "NO" (without the quotes), if he can't.

Sample Input

2 2
1 99
100 0

Sample Output

YES
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int ll;

struct xy
{
    ll x;
    ll y;
};
typedef struct xy sS;

bool compare(const sS a,const sS b)
{
    return a.x<b.x;
}

int main() {
    ll n,s;
    scanf("%lld %lld",&s,&n);
    
    vector <sS> v(n);
    for(ll i=0;i<n;i++)
        scanf("%lld %lld",&v[i].x,&v[i].y);
    
    sort(v.begin(),v.end(),compare);
    
    ll sum=s;
    bool isDone=true;
    for(ll i=0;i<n;i++)
    {
        if(v[i].x<s)
        {
            s+=v[i].y;
        }
        else
        {
            isDone=false;
            break;
        }
    }
    if(isDone)
        printf("YES\n");
    else
        printf("NO\n");
    
    return 0;
}

