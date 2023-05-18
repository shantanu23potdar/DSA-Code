#include<stdio.h>
#include<math.h>
int main()
{
    float t,v,wcf;

    printf("enter the temperature of wind: ");
    scanf("%f", &t);

    printf("enter the velocity of wind: ");
    scanf("%f", &v);

    wcf = 35.74 + 0.6215*t + (0.4275*t - 35.75) * pow(v,0.16);
    printf("the chill factor is:%f",wcf);

    return 0;
}


//enter the temperature of wind: 5
//enter the velocity of wind: 5
//the chill factor is:-4.637154
