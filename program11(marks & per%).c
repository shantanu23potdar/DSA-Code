#include<stdio.h>
int main()
{
    int eng,hindi,math,sst,sci,marks;
    float per;

    printf("enter the marks of english= ");
    scanf("%d",&eng);

    printf("enter the marks of hindi=");
    scanf("%d",&hindi);

    printf("enter the marks of math=");
    scanf("%d",&math);

    printf("enter the marks of sst=");
    scanf("%d",&sst);

    printf("enter the marks of sci=");
    scanf("%d",&sci);

    marks = eng + hindi + math + sst + sci;

    per = (marks/0.5) * 0.1 ;    //per = (marks/5);

    printf("enter the marks= %d\n",marks);
    printf("enter the percentage= %f\n",per);

    return 0;
}
