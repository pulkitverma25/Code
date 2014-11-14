/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
http://code.google.com/codejam/contest/6214486/dashboard#s=p2

Once upon a day, Mary bought a one-way ticket from somewhere to somewhere with some flight transfers.

For example: SFO->DFW DFW->JFK JFK->MIA MIA->ORD.

Obviously, transfer flights at a city twice or more doesn't make any sense. So Mary will not do that.

Unfortunately, after she received the tickets, she messed up the tickets and she forgot the order of the ticket.

Help Mary rearrange the tickets to make the tickets in correct order.

Input
The first line contains the number of test cases T, after which T cases follow.
For each case, it starts with an integer N. There are N flight tickets follow.
Each of the next 2 lines contains the source and destination of a flight ticket.

Output
For each test case, output one line containing "Case #x: itinerary", where x is the test case number (starting from 1) and itinerary is sorted list of flight tickets which represents the actual itinerary. Each flight segment in the itinerary should be outputted as pair of source-destination airport codes.
Limits

1 ≤ T ≤ 100.
For each case, the input tickets are messed up from an entire itinerary bought by Mary. In other words, it's ensured can be recovered to a valid itinerary.
Small dataset

1 ≤ N ≤ 100.
Large dataset

1 ≤ N ≤ 104.
(The segment for second case in sample can be seen as below) MIA-ORD, DFW-JFK, SFO-DFW, JFK-MIA

Sample

Input
2
1
SFO
DFW
4
MIA
ORD
DFW
JFK
SFO
DFW
JFK
MIA

Output
Case #1: SFO-DFW
Case #2: SFO-DFW DFW-JFK JFK-MIA MIA-ORD
*/

#include <iostream>
#include <map>
#include <string>

using namespace std;
typedef long long int ll;

int main() 
{
    ll t;
    cin>>t;
    
    for(ll z=1;z<=t;z++)
    {
        ll n;
        map <string,string> m1;
        map <string, ll> m2;

        cin>>n;
        string s1,s2;
        for(ll i=0;i<n;i++)
        {
            cin>>s1>>s2;
            m1[s1]=s2;
            
            if(!m2.count(s1))
                m2[s1]=1;
            else
                m2.erase(s1);
                
            if(!m2.count(s2))
                m2[s2]=1;
            else
                m2.erase(s2);
        }
        string start;
        for (map<string,ll>::iterator it=m2.begin(); it!=m2.end(); it++)
        {
            string temp=it->first;
            if(m1.count(temp)>0)
                start=temp;
        }
        
        cout<<"Case #"<<z<<": ";
        for(ll i=0;i<n;i++)
        {
            cout<<start<<"-"<<m1[start]<<" ";
            start=m1[start];
        }
        cout<<endl;
        
        
    }
    return 0;
}
