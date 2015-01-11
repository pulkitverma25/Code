/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
https://www.hackerrank.com/challenges/cavity-map

You are given a square n×n map. Each cell of the map has a value in it denoting the depth of the appropriate area. We will call a cell of the map a cavity if and only if this cell is not on the border of the map and each cell adjacent to it has strictly smaller depth. Two cells are adjacent if they have a common side.

You need to find all the cavities on the map and depict them with character X.

Input Format

The first line contains an integer n (1≤n≤100), denoting the size of the map. Each of the following n lines contains n positive digits without spaces. A digit (1-9) denotes the depth of the appropriate area.

Output Format

Output n lines, denoting the resulting map. Each cavity should be replaced with character X.

Sample Input

4
1112
1912
1892
1234

Sample Output

1112
1X12
18X2
1234
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int arr[100][100];

int main() 
{
    int n;
    string tempStr;
    cin>>n;
    
    for(int i=0;i<n;i++)
    {
        cin>>tempStr;
        for(int j=0;j<n;j++)
            arr[i][j]=tempStr[j]-'0';
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)    
        {
            if(i==0 || j==0 || i==n-1 || j==n-1)
                cout<<arr[i][j];
            else if(arr[i][j]>arr[i][j-1] && arr[i][j]>arr[i-1][j] && arr[i][j]>arr[i+1][j] && arr[i][j]>arr[i][j+1])
                cout<<'X';
            else
                cout<<arr[i][j];
        }
        cout<<endl;
    }
    return 0;
}

