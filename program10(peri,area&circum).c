#include<stdio.h>
int main()
{
  float length,breadth,radius;
 float area1,peri,area2,circum;

 printf("enter the rectangle length and breadth=");
 scanf("%f\n%f",&length,&breadth);

 printf("enter the value of radius of a circle=");
 scanf("%f",&radius);

 peri = 2 * length + 2 * breadth;

 area1 = length * breadth;

 circum = 2 * 3.14 * radius;

 area2 = 3.14 * radius * radius;

 printf("the perimeter of rectangle=%f\n",peri);
 printf("the area of rectangle=%f\n",area1);
 printf("the circumference of circle=%f\n",circum);
 printf("the area of circle=%f\n",area2);


 return 0;

}








