#include<stdio.h>
#include<math.h>
int main()
{
    float x,y,r,theta,degree;
    printf("enter the cartesian co-ordinates:");
    scanf("%f%f", &x,&y);

    r = sqrt(x*x + y*y);
    theta = atan(x/y);

    degree = theta * 180 / 3.14;

    printf("polar co-ordinates of r is:%f\n",r);
    printf("polar co-ordinates of theta is:%f\n",theta);
    printf("polar co-odinates of r and theta is:(%f,%f)",r,degree);
    return 0;

}


//enter the cartesian co-ordinates:1
//1
//polar co-ordinates of r is:1.414214
//polar co-ordinates of theta is:0.785398
//polar co-odinates of r and theta is:(1.414214,45.022827)
