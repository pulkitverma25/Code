/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
http://www.codechef.com/problems/CRAWA

 Oh no! Chef’s robot from problem "Reach The Point" (RETPO) has broken up.
It's old oil tank has got leaked, it is leaking oil now.

The robot start doing the following weird moves. While moving it keeps leaving a trace of oil on the path it's been tracing.

Note that in a single step robot will move by one unit in the current direction it is moving.

    Initially the robot is at position (0, 0).
    In the beginning it goes 1 step to the East (i.e. In a single step, its x coordinate will increase by 1 unit.)
    then 2 steps to the North, (i.e. In a single step, its y coordinate will increase by 1 unit.)
    then 3 steps to the West, (i.e. In a single step, its x coordinate will decrease by 1 unit.)
    then 4 steps to the South, (i.e. In a single step, its y coordinate will decrease by 1 unit.)
    then 5 steps to the East,
    and so on.

Thus each time the robot turns 90 degrees anti clockwise, and it will go one more step than before. Please view the following image to
understand the moves. The red line in the example shows the path traced by the robot having traces of oil on it. 

https://codechef_shared.s3.amazonaws.com/download/AUG14/robot2.jpg

Now chef wants to know whether the point (X, Y) will have traces of oil on it or not.
Input

The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.

For each test case, there is a single line containing two space-separated integers X and Y.
Output

For each test case, output a single line containing “YES” (without quotes) if robot will reach point (X, Y) and “NO” otherwise.
Constraints

    1 ≤ T ≤ 100000 = 105
    -1000000000 ≤ X, Y ≤ 1000000000, i.e., -109 ≤ X, Y ≤ 109

Example

Input:
3
3 3
3 5
0 0

Output:
YES
NO
YES

Explanation

The points (0, 0) and (3, 3) will be having trace of oil while point (3, 5) will not have any trace of oil because point (3, 5) does not lie on the trajectory of robot. 
*/

#include <stdio.h>

#define TRUE 1
#define FALSE 0

int hasOilTrace(int x, int y)
{
	if((y == 0) && (x == 0))
		return TRUE;
	else if ((x > 0) && ((x-1) % 2 == 0) && (y <= (x+1)) && (y >= (-x+	1)))
		return TRUE;
	else if ((x < 0) && (((-1*x) % 2) == 0) && (y <= (-1*x)) && (y >= x))
		return TRUE;
	else if ((y >= 0) && (y % 2 == 0) && (x <= (y-1)) && (x >= (-1*y)))
		return TRUE;
	else if ((y < 0) && (((-1*y) % 2) == 0) && (x <= (-1*y)+1) && (x >= y))
		return TRUE;

	return FALSE;
}

int main()
{
	int num,x,y;

	for((scanf("%d",&num)); num > 0; num--)
	{
		scanf("%d %d",&x,&y);
		
		if (hasOilTrace(x,y))
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}

