#include<stdio.h>
#include<math.h>
int main()
{
     float lat1, lat2, lon1, lon2, D;


    printf("Enter latitude(L1, L2)\n");
    scanf("%f%f", &lat1, &lat2);

    printf("Enter longitude(G1, G2)\n");
    scanf("%f%f", &lon1, &lon2);

    lat1 = lat1 * ( 3.14 / 180.0 );
    lat2 = lat2 * ( 3.14 / 180.0 );
    lon1 = lon1 * ( 3.14/ 180.0 );
    lon2 = lon2 * ( 3.14 / 180.0 );


     D = 3963 * acos( sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(lon2 - lon1) );

    printf("the distance them in natical miles:%f",D);
    return 0;


}
