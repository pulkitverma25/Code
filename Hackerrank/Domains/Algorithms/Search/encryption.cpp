/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
https://www.hackerrank.com/challenges/encryption

An English text needs to be encrypted. The encryption algorithm first removes the spaces from the text and then the characters are written into a rectangle (or a square), whose width and height have the following constraints:

    floor(sqrt( len(word) )) <= width, height <= ceil(sqrt( len(word) ))

    In case of a rectangle, the number of rows will always be smaller than the number of columns.For example, the sentence "if man was meant to stay on the ground god would have given us roots" is 54 characters long, so it is written in the form of a rectangle with 7 rows and 8 columns.

                    ifmanwas
                    meanttos        
                    tayonthe
                    groundgo
                    dwouldha
                    vegivenu
                    sroots

    Also ensure, height * width >= len(word)
    If multiple rectangles satisfy the above conditions, choose the one with the minimum area.

The encoded message is obtained by displaying the characters in a column, inserting a space, and then displaying the next column and inserting a space and so on.For example, the encoded message for the above rectangle is:

imtgdvs fearwer mayoogo anouuio ntnnlvt wttddes aohghn sseoau

You will be given a message in English with no spaces between the words.The maximum message length can be 81 characters. Print the encoded message.

Here are some more examples:

Sample Input:

haveaniceday

Sample Output:

hae and via ecy

Sample Input:

feedthedog    

Sample Output:

fto ehg ee dd

Sample Input:

chillout

Sample Output:

clu hlt io
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() 
{
    string s;
    cin>>s;
    int minArea=41*41,minR,minC;
    int len=s.size();
    int minVal= floor(sqrt( len )) ;
    int maxVal= ceil(sqrt( len )) ;
    for(int i=minVal;i<=maxVal;i++)
    {
        for(int j=minVal;j<=maxVal;j++)
        {
            if(i && j && i*j>=len && i*j<minArea)
            {
                minArea=i*j;
                minR=i;
                minC=j;
            }
        }
    }
    for(int i=0;i<minC;i++)
    {
        for(int j=0;j<minR;j++)
            if(minC*j+i<len)
                cout<<s[minC*j+i];
        cout<<" ";
    }
    cout<<endl;
    
    return 0;
}

