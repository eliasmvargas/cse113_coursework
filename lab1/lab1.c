/**
 * @file lab1.c
 * @author Elias Vargas
 * @brief Here is a simple geometry calculator for most basic geometric calculations.
 * @version 0.1
 * @date 2023-09-20
 * 
 */


#include <stdio.h>
#include <math.h>
#define PI 3.141593


int w, l, n, beep; // beep is for switch statement cases
double a, r, b, h;

double area_rectangle();
int rectangle_perimeter();
double area_circle();
double circumference();
double area_triangle();
double perimeter_triangle();
double hypotenuse();
double exterior_angle();
double interior_angle();
double area_polygon();


/*
* Main is essentially the menu, giving a switch for each function of the program.
* There are 8 options.
* @param beep is the switch case number
* @param all geometric functions listed below
* @return Result of the one function selected
*/


int main(void) 
{
    printf("What function would you like to use? \n");
    printf(" 1. Rectangle area \n 2. Rectangle perimeter \n 3. Circle area \n 4. Circle Circumference \n 5. Triangle Hypotenuse \n 6. Triangle perimeter \n 7. Exterior angle \n 8. Interior angle \n 9. N-Sided Polygon Area.");
    scanf("%d", &beep);
    switch(beep){
    
    case 1:
    // Rectangle area inputs
    printf("Enter the length of a rectangle: "); 
    scanf("%d", &l);
    printf("Enter the width: ");
    scanf("%d", &w);
    printf("The area is: %lf \n", area_rectangle()); 
    break;

    case 2:
    // Rectangle perimeter
    printf("Enter the length of a rectangle: ");
    scanf("%d", &l);
    printf("Enter the width: ");
    scanf("%d", &w);
    printf("The perimeter is: %d \n", rectangle_perimeter());
    break;

    case 3:
    // Circle area
    printf("Enter the radius of a circle  ");
    scanf("%lf", &r);
    printf("The area is: %lf \n", area_circle());
    break;
    
    case 4:
    //Circumference
    printf("Enter the radius of a circle  ");
    scanf("%lf", &r);
    printf("The circumference is %lf \n", circumference());
    break;

    case 5:
    // Hypotenuse
    printf("Enter side 1 of a triangle: ");
    scanf("%lf", &b);
    printf("Enter side 2: ");
    scanf("%lf", &h);
    printf("The hypotenuse is: %lf \n", hypotenuse());
    break;

    case 6:
    // Perimeter
    printf("Enter side 1 of a triangle: ");
    scanf("%lf", &b);
    printf("Enter side 2: ");
    scanf("%lf", &h);
    printf("The perimeter is: %lf \n", perimeter_triangle());
    break;
    
    case 7:
    // Exterior angle
    printf("Enter the number of sides: ");
    scanf("%d", &n);
    printf("The exterior angles are: %lf degrees \n", exterior_angle());
    break;

    case 8:
    //interior angle
    printf("Enter the number of sides: ");
    scanf("%d", &n);
    printf("The interior angles are: %lf degrees \n", interior_angle());
    break;

    case 9:
    // Polygon area
    printf("Enter the apothem: ");
    scanf("%lf", &a);
    printf("Enter the perimeter: ");
    scanf("%d", &n);
    printf("The area of the normal polygon is: %lf \n", area_polygon());
    break; 

    return 0;
}
}

/*
* Takes two ints and returns a double
* @param w = width
* @param l = length
* @return the area
*/
double area_rectangle(){
double i = w * l;
return i;
}

/* 
* Takes two ints and returns an int
* @param w = width
* @param l = length
* @return the perimeter
*/
int rectangle_perimeter(){
int  i = 2 * (w + l);
return i;
}

/*
* Takes two doubles and returns a double
* @param r is radius
* @return the area
*/
double area_circle(){
double i = PI * pow(r, 2);
return i;
}

/*
* Takes two doubles and returns a double
* @param r is radius
* @return the circumference
*/
double circumference(){
double i = 2 * PI * r;
return i;
}
/*
* Takes two doubles and returns a double
* @param b = base
* @param h = height
* @return the area
*/
double area_triangle(){
double i = (b * h) / 2;
return i;
}

/*
* Takes two doubles and returns a double
* @param h = side 1, reusing variable
* @param b = side 2
* @return the hypotenuse
*/
double hypotenuse(){
double i = sqrt(pow(h, 2) + pow(b, 2));
return i;
}

/*
* Takes two doubles and returns a double
* @param hypotenuse funct.
* @param h = side 1
* @param b = side 2
* @return triangle perimeter
*/
double perimeter_triangle(){
double i = hypotenuse() + b + h;
return i;
}

/*
* Takes one int and returns a double
* @param n is the number of sides
* @return exterior angles
*/
double exterior_angle(){    
double i = 360 / n;
return i;
}


/*
* Takes one int and returns a double
* @param n is the number of sides
* @return interior angles
*/
double interior_angle(){
double i = ((n - 2) * 180) / n;
return i;
}


/*
* Takes two doubles and returns a double
* @param a is the apothem
* @param n is number of sides
* @return area of the polygon
*/
double area_polygon(){
double i = (a * n) / 2;
return i;
}