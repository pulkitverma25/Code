/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
https://www.hackerrank.com/contests/infinitum-sep14/challenges/sherlock-and-geometry

Watson gives a circle and a triangle in a 2-dimensional plane to Sherlock. Sherlock has to tell if they intersect/touch each other.
The circle is centered at (xc,yc) and has radius R.

Input Format
The first line contains T, the number of test cases.
Each test case consists of xc, yc and R in one line.
The next three lines each contains xi,yi denoting the vertices of the triangle.

Output Format
For each test case, print YES if the triangle touches or intersects the circle; otherwise, print NO.

Constraints
1≤T≤30000
1≤R≤2000
−2000≤xc,yc≤2000
−5000≤xi,yi≤5000
Note: There will be no degenerate triangles (i.e. triangles with area 0)

Sample Input

2
0 0 10
10 0
15 0
15 5
0 0 10
0 0
5 0
5 5

Sample Output

YES
NO
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

double findDistanceToSegment(double x1, double y1, double x2, double y2, double pointX, double pointY)
{
    double diffX = x2 - x1;
    float diffY = y2 - y1;
    if ((diffX == 0) && (diffY == 0))
    {
        diffX = pointX - x1;
        diffY = pointY - y1;
        return sqrt(diffX * diffX + diffY * diffY);
    }

    float t = ((pointX - x1) * diffX + (pointY - y1) * diffY) / (diffX * diffX + diffY * diffY);

    if (t < 0)
    {
        diffX = pointX - x1;
        diffY = pointY - y1;
    }
    else if (t > 1)
    {
        diffX = pointX - x2;
        diffY = pointY - y2;
    }
    else
    {
        diffX = pointX - (x1 + t * diffX);
        diffY = pointY - (y1 + t * diffY);
    }

    return sqrt(diffX * diffX + diffY * diffY);
}

float distance(float x1, float y1, float x2, float y2)
{
    float term1=x1-x2;
    float term2=y1-y2;
    
    return sqrt((term1*term1)+(term2*term2));
}

int main() {
    int t;
    cin>>t;
    
    while(t--)
    {   
        float xc,yc,r;
        float x1,y1,x2,y2,x3,y3;
        
        cin>>xc>>yc>>r;
        cin>>x1>>y1;
        cin>>x2>>y2;
        cin>>x3>>y3;
        
        float dist1=distance(x1,y1,xc,yc);
        float dist2=distance(x2,y2,xc,yc);
        float dist3=distance(x3,y3,xc,yc);
        float minDist=min(min(dist1,dist2),dist3);
        float maxDist=max(max(dist1,dist2),dist3);
        
        double lineDist1=findDistanceToSegment(x1, y1, x2, y2, xc, yc);       
        double lineDist2=findDistanceToSegment(x2, y2, x3, y3, xc, yc);   
        double lineDist3=findDistanceToSegment(x3, y3, x1, y1, xc, yc);  
        float minLineDist=min(min(lineDist1,lineDist2),lineDist3);    
     
        if(minDist<=r && maxDist>=r)
            cout<<"YES"<<endl;
        else if (minDist>r && minLineDist<=r)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
        
    }
    return 0;
}

