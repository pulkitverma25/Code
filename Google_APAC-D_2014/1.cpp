/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/

/*
http://code.google.com/codejam/contest/6214486/dashboard

Problem
Vincenzo decides to make cube IV but only has the budget to make a square maze. Its a perfect maze, every room is in the form of a square and there are 4 doors (1 on each side of the room). There is a big number written in the room. A person can only move from one room to another if the number in the next room is larger than the number in his current room by 1. Now, Vincenzo assigns unique numbers to all the rooms (1, 2, 3, .... S2) and then places S2 people in the maze, 1 in each room where S is the side length of the maze. The person who can move maximum number of times will win. Figure out who will emerge as the winner and the number of rooms he will be able to move.

Input
The first line of the input gives the number of test cases, T. T test cases follow. Each test case consists of S which is the side length of the square maze. Then S2 numbers follow like a maze to give the numbers that have been assigned to the rooms.

1 2 9 
5 3 8 
4 6 7 

Output
For each test case, output one line containing "Case #x: r d", where x is the test case number (starting from 1), r is the room number of the person who will win and d is the number of rooms he could move. In case there are multiple such people, the person who is in the smallest room will win.
Limits

1 ≤ T ≤ 100.
Small dataset

1 ≤ S ≤ 10
Large dataset

1 ≤ S ≤ 103.

Sample

Input
2
2
3 4
1 2 
3
1 2 9 
5 3 8 
4 6 7 

Output
Case #1: 1 2
Case #2: 6 4
*/

#include <cstdio>
#include <iostream>

#define M 1000001
using namespace std;
typedef long long int ll;

struct point
{
    ll x;
    ll y;
};
typedef struct point p;

p loc[M];
ll count [M];

int main()
{

    ll t;
    scanf("%lld",&t);
    
    for(ll z=1;z<=t;z++)
    {
        for(ll i=0;i<M;i++)
        {
            loc[i].x=loc[i].y=-1;
            count[i]=1;
        }      
        ll s,num;
        scanf("%lld",&s);
        
        for(ll i=0;i<s;i++)
            for(ll j=0;j<s;j++)
            {
                scanf("%lld",&num);
                loc[num-1].x=i;
                loc[num-1].y=j;
            }
            
        ll s2=s*s;
        count[s2-1]=1;
        ll maxC=1,per=s2;
        for(ll i=s2-2;i>=0;i--)
        {
            if(loc[i].x==loc[i+1].x && loc[i].y==loc[i+1].y+1)
                count[i]=1+count[i+1];
            else if(loc[i].x==loc[i+1].x && loc[i].y==loc[i+1].y-1)
                count[i]=1+count[i+1];
            else if(loc[i].x==loc[i+1].x+1 && loc[i].y==loc[i+1].y)
                count[i]=1+count[i+1];
            else if(loc[i].x==loc[i+1].x-1 && loc[i].y==loc[i+1].y)
                count[i]=1+count[i+1];
            if(count[i]>=maxC)
            {
                maxC=count[i];
                per=i+1;
            }
        }
        
        printf("Case #%lld: %lld %lld\n",z,per,maxC);
    
    }
    return 0;
}
