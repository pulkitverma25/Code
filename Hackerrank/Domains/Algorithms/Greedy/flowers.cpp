/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
https://www.hackerrank.com/challenges/flowers

You and your K-1 friends want to buy N flowers. Flower number i has cost ci. Unfortunately the seller does not want just one customer to buy a lot of flowers, so he tries to change the price of flowers for customers who have already bought some flowers. More precisely, if a customer has already bought x flowers, he should pay (x+1)*ci dollars to buy flower number i.
You and your K-1 friends want to buy all N flowers in such a way that you spend the least amount of money. You can buy the flowers in any order.

Input:

The first line of input contains two integers N and K (K <= N). The next line contains N space separated positive integers c1,c2,...,cN.

Output:

Print the minimum amount of money you (and your friends) have to pay in order to buy all N flowers.

Constraint :

1 <= N, K <= 100
Any ci is not more than 1,000,000

Sample input #00

3 3
2 5 6

Sample output #00

13

Sample input #01

3 2
2 5 6

Sample output #01

15

Explanation :
Sample Case #00: In this example, all of you should buy one flower each. Hence, you'll have to pay 13 dollars.
Sample Case #01: Here one of the friend buys first two flowers in decreasing order of their price. So he will pay (0+1)*5 + (1+1)*2 = 9. And other friend will buy the costliest flower of cost 6. So total money need is 9+6=15.
*/

#include<iostream>
#include<algorithm>
#include <functional> 

using namespace std;

int main(void)
{
   int N, K;
   cin >> N >> K;
    int C[N];
   for(int i = 0; i < N; i++)
      cin >> C[i];

   sort(C,C+N,greater<int>());
   int result=0;
   for(int i=0;i<K;i++)
   {
     int num=i,count=1;
     while(num<N)
     {
        result+=(count*C[num]);
         count++;
         num+=K;
     }
   }
    
   cout << result << "\n";
   
   return 0;
}

