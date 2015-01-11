/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
https://www.hackerrank.com/contests/fun-2-0/challenges/dating-penny

Raj and Leonard are playing numbers game. Whoever wins the game gets to date Penny (Yes Penny is single!). The game rules is as follow

They write some integer smaller then 2000000000 (2*109) and take turns one after another. Raj is the first to make a move. The turn is made by the following rule: from the written integer any non-zero digit is subtracted, and the new integer replaces the old one on the desk. For example for integer 40534, the next move can be: 40530, 40531 or 40529. The winner is the player who writes zero on the desk.

Raj has advantage with the 1st move. Raj is so desperate to date Penny, he wants to know who will win the game. He is not very good in the number game. So he wants your help.

Input

The input contains the integer from which the game is started.

Output

In the first line you must write 1 if Raj wins and 2 if Lenorard. If Raj wins then in the second line you must output the move in the first turn which guarantees victory for him. If there are many such moves then output any of them.

Example

Input:

14

Output:

1
4
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long int ll;

int main() {
    ll num;
    cin>>num;
    
    ll first;
    if(num%10==0)
        cout<<"2"<<endl;
    else
    {
        first=num%10;
        cout<<"1\n"<<first<<endl;
    }
    return 0;
}

