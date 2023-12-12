/**
* @file functions.c
* @author Elias Vargas
* @date 9/28/23
* @brief Preprocessor directive for geometry calculator - function definitions 
*/

#include <stdio.h>
#include "functions.h"

/*
* Takes two ints and returns a double
* @param w = width
* @param l = length
* @return the area
*/
double area_rectangle(int w, int l){
double i = w * l;
return i;
}

/* 
* Takes two ints and returns an int
* @param w = width
* @param l = length
* @return the perimeter
*/
int rectangle_perimeter(int w, int l){
int  i = 2 * (w + l);
return i;
}

/*
* Takes two doubles and returns a double
* @param r is radius
* @return the area
*/
double area_circle(double r){
double i = PI * pow(r, 2);
return i;
}

/*
* Takes two doubles and returns a double
* @param r is radius
* @return the circumference
*/
double circumference(double r){
double i = 2 * PI * r;
return i;
}
/*
* Takes two doubles and returns a double
* @param b = base
* @param h = height
* @return the area
*/
double area_triangle(double b, double h){
double i = (b * h) / 2;
return i;
}

/*
* Takes two doubles and returns a double
* @param h = side 1, reusing variable
* @param b = side 2
* @return the hypotenuse
*/
double hypotenuse(double b, double h){
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
double perimeter_triangle(double b, double h){
double i = hypotenuse(b, h) + b + h;
return i;
}

/*
* Takes one int and returns a double
* @param n is the number of sides
* @return exterior angles
*/
double exterior_angle(int n){    
double i = 360 / n;
return i;
}


/*
* Takes one int and returns a double
* @param n is the number of sides
* @return interior angles
*/
double interior_angle(int n){
double i = ((n - 2) * 180) / n;
return i;
}


/*
* Takes two doubles and returns a double
* @param a is the apothem
* @param n is the number of sides
* @param s is the length of a side
* @return area of the polygon
*/
double area_polygon(int n, double s){
double i = (pow(s, 2) * n) / (4 * tan(PI / n));
return i;
}