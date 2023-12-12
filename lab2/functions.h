/**
* @file functions.h
* @author Elias Vargas
* @date 9/28/23
* @brief Preprocessor directive for geometry calculator - function prototypes and variable declaration
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.141593

int w, l, n, beep, tmp; // beep is for switch statement cases
double a, r, b, h, s;

double area_rectangle(int w, int l);
int rectangle_perimeter(int w, int l);
double area_circle(double r);
double circumference(double r);
double area_triangle(double b, double h);
double perimeter_triangle(double b, double h);
double hypotenuse(double b, double h);
double exterior_angle(int n);
double interior_angle(int n);
double area_polygon(int n, double s);