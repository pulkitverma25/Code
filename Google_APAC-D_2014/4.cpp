/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
http://code.google.com/codejam/contest/6214486/dashboard#s=p3

 Given an arranged chess board with pieces, figure out the total number of different ways in which any piece can be killed in one move. Note: in this problem, the pieces can be killed despite of the color.

http://code.google.com/codejam/contest/images/?image=chess.png&p=5681224764882944&c=6214486

For example, if there are 3 pieces King is at B2, Pawn at A1 and Queen at H8 then the total number of pieces that an be killed is 3. H8-Q can kill B2-K, A1-P can kill B2-K, B2-K can kill A1-P

A position on the chess board is represented as A1, A2... A8,B1.. H8

Pieces are represented as

    (K) King can move in 8 direction by one place.
    (Q) Queen can move in 8 direction by any number of places, but can't overtake another piece.
    (R) Rook can only move vertically or horitonzally, but can't overtake another piece.
    (B) Bishop can only move diagonally, but can't overtake another piece.
    (N) Knights can move to a square that is two squares horizontally and one square vertically OR one squares horizontally and two square vertically.
    (P) Pawn can only kill by moving diagonally upwards (towards higher number i.e. A -> B, B->C and so on). 

Input
The first line of the input gives the number of test cases, T. T Test cases follow. Each test case consists of the number of pieces , N. N lines follow, each line mentions where a piece is present followed by - with the piece type

Output
For each test case, output one line containing "Case #x: y", where x is the test case number (starting from 1) and y is the the total number of different ways in which any piece can be killed.
Limits

1 ≤ T ≤ 100.
Small dataset

1 ≤ N ≤ 10.
Pieces can include K, P
Large dataset

1 ≤ N ≤ 64.
Sample

Input
2
2
A1-K
A8-Q

3
B2-K
A1-P
H8-Q

Output 
Case #1: 1
Case #2: 3
*/

#include <cstdio>
#include <map>
#include <cstring>
#include <cmath>
#include <iostream>

using namespace std;
typedef long long int ll;

struct chess
{
    int x;
    int y;
    char p;
};
typedef struct chess ch;
ch arr[64];
bool chess[8][8];

bool canKill(int i,int j)
{
    if(arr[i].p=='P')
    {
        if(arr[i].x+1==arr[j].x && (arr[i].y+1==arr[j].y || arr[i].y-1==arr[j].y))
            return true;
        return false;
    }
    if(arr[i].p=='K')
    {
        if(arr[i].x-1 == arr[j].x && arr[i].y-1==arr[j].y)
            return true;
        else if(arr[i].x-1 == arr[j].x && arr[i].y==arr[j].y)
            return true;
        else if(arr[i].x-1 == arr[j].x && arr[i].y+1==arr[j].y)
            return true; 
        else if(arr[i].x+1 == arr[j].x && arr[i].y-1==arr[j].y)
            return true;
        else if(arr[i].x+1 == arr[j].x && arr[i].y==arr[j].y)
            return true;
        else if(arr[i].x+1 == arr[j].x && arr[i].y+1==arr[j].y)
            return true;   
            
        else if(arr[i].x == arr[j].x && arr[i].y-1==arr[j].y)
            return true;
        else if(arr[i].x == arr[j].x && arr[i].y+1==arr[j].y)
            return true;          
        return false;
    }
    
    if(arr[i].p=='B')
    {
        if((abs(arr[i].x-arr[j].x)) == (abs(arr[i].y-arr[j].y)))
        {
            int xDir=1;
            if((arr[j].x-arr[i].x)<0)
                xDir=-1;
            int yDir=1;
            if((arr[j].y-arr[i].y)<0)
                yDir=-1;
                
            int tX=arr[i].x;
            int tY=arr[i].y;
            while(!(tX ==arr[j].x && tY ==arr[j].y))
            {
                tX+=xDir;
                tY+=yDir;
                if(tX==arr[j].x && tY==arr[j].y)
                    return true;
                if(chess[tX][tY]==true)
                    return false;
            }
            return true;
        }
            return false;
    }
    
    if(arr[i].p=='R')
    {
        if((arr[i].x==arr[j].x) || (arr[i].y== arr[j].y))
        {
            int dir;
            int xDir=1,yDir=1;
            if(arr[j].x==arr[i].x)
            {
            	xDir=0;
                dir=-1;
           		if((arr[j].y-arr[i].y)<0)
                	yDir=-1;
			}
			else
			{
            	yDir=0;
                dir=1;
           		if((arr[j].x-arr[i].x)<0)
                	xDir=-1;			
			}

            int tX=arr[i].x;
            int tY=arr[i].y;

            while(!(tX ==arr[j].x && tY ==arr[j].y))
            {
                tX+=xDir;
                tY+=yDir;
                if(tX==arr[j].x && tY==arr[j].y)
                    return true;
                
                if(chess[tX][tY]==true)
                    return false;
                
            }
            return true;
        }
        else
            return false;
    }
    if(arr[i].p=='Q')
    {
        arr[i].p='R';
        bool b1=canKill(i,j),b2;
        if(b1)
        {
            arr[i].p='Q';
            return true;
        }
        else
        {
            arr[i].p='B';
            b2=canKill(i,j);
            if(b2)
            {
                arr[i].p='Q';
                return true;
            }
        }
        arr[i].p='Q';
        return false;
    }
    
    if(arr[i].p=='N')
    {
        if(arr[i].x-1 == arr[j].x && arr[i].y+2==arr[j].y)
            return true;
        else if(arr[i].x-1 == arr[j].x && arr[i].y-2==arr[j].y)
            return true;
        else if(arr[i].x+1 == arr[j].x && arr[i].y+2==arr[j].y)
            return true;
        else if(arr[i].x+1 == arr[j].x && arr[i].y-2==arr[j].y)
            return true;
               
        else if(arr[i].y-1 == arr[j].y && arr[i].x+2==arr[j].x)
            return true;
        else if(arr[i].y-1 == arr[j].y && arr[i].x-2==arr[j].x)
            return true;
        else if(arr[i].y+1 == arr[j].y && arr[i].x+2==arr[j].x)
            return true;
        else if(arr[i].y+1 == arr[j].y && arr[i].x-2==arr[j].x)
            return true;  
        else
            return false;
    }

    return false;

}

int main() 
{
    ll t;
    scanf("%lld",&t);
    
    for(ll z=1;z<=t;z++)
    {
        memset(chess,0,sizeof(chess));
        memset(arr,0,sizeof(arr));
        ll n;
        scanf("%lld",&n);
        char c1,c2,c3;
        for(ll i=0;i<n;i++)
        {
            scanf(" %c%c - %c",&c1,&c2,&c3);
            arr[i].x=(int)(c1-'A');
            arr[i].y=(int)(c2-'0');
            arr[i].p=c3;
            chess[arr[i].x][arr[i].y]=true;
        }
        
        ll count=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {   
                if(i!=j && canKill(i,j))
                    count++;
            }
        printf("Case #%lld: %lld\n",z,count);     
    }
    return 0;
}
