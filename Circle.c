#include <stdio.h>
#include <math.h>

#define PI (3.141592653589793)
int main()
{

    float radius;
    float circumference;
    float area;

    printf("\nEnter radius: ");

    scanf("%f", &radius);
    radius=fabsf(radius);
    circumference= 2 *PI * radius;
    area = PI * pow(radius,2);
    printf("\nThe circumference is : %f",circumference );
    printf("\nThe area is : %f", area);
    printf("\nThe square root of the area is : %f", sqrt(area));
    return 0;
}
