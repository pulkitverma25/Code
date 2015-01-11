/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
https://www.hackerrank.com/contests/warm-up-1/challenges/warm-up-1

Mrs. Sunny(leone) has a binary tree. The binary tree consists of 1 or more nodes. Each node has a unique integer id. Each node has up to 2 children, which are identified by their ids, and each node is the child of at most 1 other node. A node X is considered to be an ancestor of node Y if node Y is a child of node X or if there is some node Z for which X is an ancestor of Z and Y is a child of Z. No node is an ancestor of itself. A special node called the root node is an ancestor of all other nodes.

Mrs. Sunny(leone) has forgotten which node of her tree is the root, and wants you to help her to figure it out. Unfortunately, sunny's knowledge of the tree is incomplete. She does not remember the ids of the children of each node, but only remembers the sum of the ids of the children of each node.

Input Begins with an integer T, the number of test cases. Each test case begins with an integer N, the number of nodes in the tree. N lines follow with 2 integers each: the id of a node, and the sum of the ids of its children. The second number will be 0 if the node has no children.

Output For each test case, output on a line a space separated list of all possible values for the id of the root node in increasing order. It is guaranteed that at least one such id exists for each test case.

Constraints
1 ≤ T ≤ 50
1 ≤ N ≤ 30
All node ids are between 1 and 1000, inclusive.

Sample Input

2
1
4 0
6
1 5
2 0
3 0
4 0
5 5
6 5

Sample Output

4
6

In the first sample test case, there is only one node, which is clearly the root. In the second test case, there are two non-isomorphic trees that satisfy the constraints, as seen in the following picture. 
*/

#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int ll;

struct node
{
    ll value;
    ll cSum;
};
typedef struct node No;
    
No arr[30];
ll tempArr[1000000];
bool compare(No a, No b)
{
    if(a.cSum==b.cSum)
        return a.value>b.value;
    return a.cSum>b.cSum;    
}

int main() {
    ll t;   
    cin>>t;
    
    while(t--)
    {
        ll n;
        cin>>n;
        memset(tempArr,0,sizeof(tempArr));
        for(ll i=0;i<30;i++)
            arr[i].value=arr[i].cSum=-1;
        for(ll i=0;i<n;i++)
        {
            cin>>arr[i].value>>arr[i].cSum;
            tempArr[arr[i].cSum]++;
        }
        sort(arr,arr+n,compare);
        
        if(tempArr[arr[0].cSum]==1)
            cout<<arr[0].value<<endl;
        else
            cout<<arr[0].value<<endl;
    }
    return 0;
}

