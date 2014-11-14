/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/

/*
String of characters as arranged in a cellphone i.e.
1- NULL
2-a,b,c
3-d,e,f
4-g,h,i
.
.
.
9-w,x,y,z
0-NULL

Print all combinations for given number of digits(k) in lexicographical order 
*/

#include <string>
#include <iostream>

using namespace std;
typedef long long int ll;
char keyPad[8][4]={
					{'a','b','c','\0'},
					{'d','e','f','\0'},
					{'g','h','i','\0'},
					{'j','k','l','\0'},
					{'m','n','o','\0'},
					{'p','q','r','s'},
					{'t','u','v','\0'},
					{'w','x','y','z'}
				  };
				  
char keyLen[8]={3,3,3,3,3,4,3,4};					
string num;
ll len;

void printCombination(ll index,string str)
{
	if(index==len)
	{
		cout<<str<<endl;
		return;
	}	
	int count=keyLen[num[index]-'0'-2];
	for(int i=0;i<count;i++)
		printCombination(index+1,str+keyPad[num[index]-'0'-2][i]);
		
	return;
}

int main()
{
	cin>>num;
	len=num.size();
	
	printCombination(0,"");

	return 0;
}
