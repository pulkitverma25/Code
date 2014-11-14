/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/

/*
You are given a map in the form of a rectangular grid. In this map, a 1 represents a piece of land and 0 represents water. A group of connected 1's forms an island. Two 1's are connected if they are adjacent on the grid (You can consider up, down, left, right as well as diagonal points to be adjacent). Your job is to find the area of the largest island.

Input

The first line has the dimensions of the grid n,m. n lines follow each having m characters each (either 0 or 1).

0<=n,m<=1000

Output

Print a single integer, the area of the largest island.

Sample Input 1

4 4  
1111  
0110  
1000  
0001  

Sample Output 1

7

Sample Input 2

4 4
1111
1110
1000
0001

Sample Output 2

8
*/

#include <stdio.h>

typedef long long int ll;

int map[1001][1001]={0};
int isVis[1001][1001]={0};
int que[1000000][2]={0};

int dx[]={-1,0,1,-1,1,-1,0,1};
int dy[]={-1,-1,-1,0,0,1,1,1};

int main()
{
	int m,n,i,j,k;
	scanf("%d %d",&n,&m);
	char c;
	printf("map:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf(" %c",&c);
			map[i][j]=c-'0';
			printf("%d ",map[i][j]);
		}	
		printf("\n");
	}
		
	ll maxSize=0;
	ll count=0;

    for( i=0; i<m; i++)
    {
        for( j=0; j<n; j++)
        {
			
        	if(!isVis[i][j] && map[i][j]==1)
        	{
        		count++;
				ll size=1;        		
				isVis[i][j]=1;
		    	int front=0;
	        	int rear=1;
				que[front][0]=i;
				que[front][1]=j;
				while(front!=rear)
				{
					for(k=0;k<8;k++)
					{
						int x=que[front][0]+dx[k];
						int y=que[front][1]+dy[k];

						if(x>=0 && x<n && y>=0 && y<m && map[x][y]==1 && !isVis[x][y])
						{
							size++;
							que[rear][0]=x;
							que[rear][1]=y;
							rear++;
							isVis[x][y]=1;
						}
					}
					front++;
					
				}    
				if(size>maxSize)
					maxSize=size;  	
				
        	}
        	isVis[i][j]=1;
        }
    }	
    
    printf("%lld\n",maxSize);
    printf("%lld\n",count);
	return 0;
}
