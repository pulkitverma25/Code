/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
https://www.hackerrank.com/challenges/angry-children

Bill Gates is on one of his philanthropic journeys to a village in Utopia. He has N packets of candies and would like to distribute one packet to each of the K children in the village (each packet may contain different number of candies). To avoid any fighting among the children, he would like to pick K out of N packets, such that unfairness is minimized.

Suppose the K packets have (x1, x2, x3,....xk) candies in them, where xi denotes the number of candies in the ith packet, then we define unfairness as

max(x1,x2,...xk) - min(x1,x2,...xk)

where max denotes the highest value amongst the elements, and min denotes the least value amongst the elements. Can you figure out the minimum unfairness and print it?

Input Format
The first line contains an integer N.
The second line contains an integer K. N lines follow. Each line contains an integer that denotes the candy in the nth (1≤n≤N) packet.

Output Format
An integer that denotes the minimum possible value of unfairness.

Constraints
1<=N<=105
1<=K<=N
0<= number of candies in any packet <=109

Sample Input #00

7
3
10
100
300
200
1000
20
30

Sample Output #00

20

Explanation #00
Here K = 3. We can choose packets that contain 10,20,30 candies. The unfairness is

max(10,20,30) - min(10,20,30) = 30 - 10 = 20

Sample Input #01

10
4
1
2
3
4
10
20
30
40
100
200

Sample Output #01

3

Explanation #01
Here K = 4. We can choose the packets that contain 1,2,3,4 candies. The unfairness is

max(1,2,3,4) - min(1,2,3,4) = 4 - 1 = 3
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


bool compare(const int num1, const int num2)
{
    return num1<num2;    
}

int main() 
{
    int N, K, unfairness;
    cin >> N >> K;
    int candies[N];
    for (int i=0; i<N; i++)
        cin >> candies[i];
    
    vector<int> myCandies (candies, candies+N);
    sort(myCandies.begin(),myCandies.end(),compare);
    
    unfairness=myCandies[N-1]-myCandies[0];
    for(int i=0;i<N-(K-1);i++)
        if(myCandies[i+K-1]-myCandies[i]<unfairness)
            unfairness=myCandies[i+K-1]-myCandies[i];
    
    cout << unfairness << "\n";
    return 0;
}
