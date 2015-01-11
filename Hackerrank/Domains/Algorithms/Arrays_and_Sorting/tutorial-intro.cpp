/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/

/*
https://www.hackerrank.com/challenges/tutorial-intro

Given a sorted array (ar) and a number (V), can you print the index location of V in the array?

{The next section describes the input format. You can often skip it, if you are using included methods. }

Input Format
There will be three lines of input:

    V - the value that has to be searched.
    n - the size of the array.
    ar - n numbers that make up the array.

Output Format
Output the index of V in the array.

{The next section describes the constraints and ranges of the input. You should check this section to know the range of the input. }

Constraints
1<=n<=1000
-1000 <=x <= 1000 , x ∈ ar

{This "sample" shows the first input test case. It is often useful to go through the sample to understand a challenge. }

Sample Input

4
6
1 4 5 7 9 12

Sample Output

1

Explanation
V = 4. The 4 is located in the 1st spot on the array, so the answer is 1.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int v,n,num;
    cin>>v>>n;
    
    for(int i=0;i<n;i++)
    {
        cin>>num;
        if(num==v)
            cout<<i<<endl;
    }
    
    return 0;
}

