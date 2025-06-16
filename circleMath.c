#include <stdio.h>
#include <math.h>

int main(void){
    const double pi = 3.14159;
    double radius = 0.0;
    double area = 0.0;
    double surfaceArea = 0.0;
    double volume =0.0;

    printf("Enter radius of circle in cm: ");
    scanf("%lf", &radius);

    area = pi * pow(radius,2); //2 dimensional circle
    surfaceArea = 4 * pi * pow(radius,2); //3 dim sphere
    volume = (4.0/3.0) * pi * pow(radius,3);
    printf(".........................................\n");

    printf("Area of circle is: %.2lf sq cm\n", area);
    printf("Surface area of sphere is: %.2lf sq cm\n", surfaceArea);
    printf("Volume of sphere is: %.2lf cu cm\n", volume);
}