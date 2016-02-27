/* 
Date (last modified):10/6/13
Description:
This program approximates the value of pi using the Monte Carlo method*/

#include<stdio.h>.srand()
#include<math.h>
#include<stdlib.h>
#include<time.h>

double approximate(int); /*Function declarations*/
void print(int);

int main ()
{
    srand(time(0)); /*seed the random func gen*/
    print(10);/*approx values of PI for specified num of pts*/
    print(100);
    print(1000);
    print(1000000);

}
double approximate(int points)
{
    int i;
    double x,y,z=0;
    int inside=0;
    for(i=0; i<points; i++)
    {
        x=(double)rand()/(double)RAND_MAX; /*generate random points within the unit square.*/
        y=(double)rand()/(double)RAND_MAX;
        z= sqrt( (x*x) + (y*y));/*calculate distance from origin*/
        if(z<1.0) /*is the radius within the unit circle?*/
            inside=inside+1;
    }
      double value= ((double)inside/(double)points)*4.0;
    return value;

}
void print(int points)
{
    double myApproxi= approximate(points); /*returned approximate value*/
    double error= (fabs(myApproxi-M_PI)/M_PI)*100; /*calculate percent error*/
    printf("points: %d, value: %f, error: %f%% \n",points, myApproxi, error);
}
