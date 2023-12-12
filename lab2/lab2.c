/**
* @file lab2.c
* @author Elias Vargas
* @date 9/28/23
* @brief A multipurpose geometry calculator :D 
*/

#include <stdio.h>
#include <ctype.h>
#include "functions.h"
#include "functions.c"

int main(void) 
{
    printf("Welcome to the Daffy Duck geometry calculator! \n Menu:\n");
    printf(" A. Angles \n C. Circle \n N. N-Sided Polygon Area \n R. Rectangle \n T. Triangle \n Any other character to exit:" );
    tmp = getchar();
    tmp = toupper(tmp);
    switch(tmp){
    
    case 'R':
        // Rectangle area inputs
        printf("Menu: \n A. Area \n P. Perimeter \n");
        getchar();
        tmp = getchar();
        tmp = toupper(tmp);
        switch(tmp){
            case 'A':
                printf("Enter the length of a rectangle: "); 
                scanf("%d", &l);
                    if (l < 0) { //input validation
                        printf("Please enter a valid number (Greater than 0): \n");
                        scanf("%d", &l);
                    }
                printf("Enter the width: ");
                scanf("%d", &w);
                     if (w < 0) { //input validation
                        printf("Please enter a valid number (Greater than 0): \n");
                        scanf("%d", &w);
                    }
                printf("The area is: %lf \n", area_rectangle(w, l)); 
                break;
            case 'P':
                printf("Enter the length of a rectangle: "); 
                scanf("%d", &l);
                    if (l < 0) { //input validation
                            printf("Please enter a valid number (Greater than 0): \n");
                            scanf("%d", &l);
                        }
                printf("Enter the width: ");
                scanf("%d", &w);
                    if (w < 0) { //input validation
                        printf("Please enter a valid number (Greater than 0): \n");
                        scanf("%d", &w);
                    }
                printf("The area is: %d \n", rectangle_perimeter(w, l)); 
                break;
        }
        break;
    

    case 'C':
        printf("Menu: \n A. Area \n C. Circumference \n");
        getchar();
        tmp = getchar();
        tmp = toupper(tmp);
        switch(tmp){
            case 'A':
                // Circle area
                printf("Enter the radius of a circle  ");
                scanf("%lf", &r);
                    if (r < 0){
                        printf("Please enter a valid number (Greater than 0): \n");
                        scanf("%lf", &r);
                    }
                printf("The area is: %lf \n", area_circle(r));
                break;

            case 'C':
                //Circumference
                printf("Enter the radius of a circle  ");
                scanf("%lf", &r);
                     if (r < 0){
                        printf("Please enter a valid number (Greater than 0): \n");
                        scanf("%lf", &r);
                    }
                printf("The circumference is %lf \n", circumference(r));
                break;
        }
        break;
    case 'T':
        printf("Menu: \n H. Hypotenuse \n P. Perimeter \n");
        getchar();
        tmp = getchar();
        tmp = toupper(tmp);
        switch (tmp){
            case 'H':
                // Hypotenuse
                printf("Enter side 1 of a triangle: ");
                scanf("%lf", &b);
                    if (b < 0){
                        printf("Please enter a valid number (Greater than 0): \n");
                        scanf("%lf", &b);
                    }
                printf("Enter side 2: ");
                scanf("%lf", &h);
                    if (h < 0){
                        printf("Please enter a valid number (Greater than 0): \n");
                        scanf("%lf", &h);
                    }
                printf("The hypotenuse is: %lf \n", hypotenuse(b, h));
                break;

            case 'P':
                // Perimeter
                printf("Enter side 1 of a triangle: ");
                scanf("%lf", &b);
                    if (b < 0){
                        printf("Please enter a valid number (Greater than 0): \n");
                        scanf("%lf", &b);
                    }
                printf("Enter side 2: ");
                scanf("%lf", &h);
                    if (h < 0){
                        printf("Please enter a valid number (Greater than 0): \n");
                        scanf("%lf", &h);
                    }
                printf("The perimeter is: %lf \n", perimeter_triangle(b, h));
                break;
        }
        break;
    case 'A':
        printf("Menu: \n E. External Angle \n I. Interior Angle \n");
        getchar();
        tmp = getchar();
        tmp = toupper(tmp);
        switch (tmp){
            case 'E':
            // Exterior angle
            printf("Enter the number of sides: ");
            scanf("%d", &n);
                if(n < 0){
                    printf("Please enter a valid number (Greater than 0): \n");
                    scanf("%d", &n);
                }
            printf("The exterior angles are: %lf degrees \n", exterior_angle(n));
            break;

            case 'I':
            //interior angle
            printf("Enter the number of sides: ");
            scanf("%d", &n);
                if(n < 0){
                    printf("Please enter a valid number (Greater than 0): \n");
                    scanf("%d", &n);
                }
            printf("The interior angles are: %lf degrees \n", interior_angle(n));
            break;
        }
        break;

    case 'N':
        // Polygon area
        printf("Enter the number of sides: ");
        scanf("%d", &n);
            if(a < 0){
                printf("Please enter a valid number (Greater than 0): \n");
                scanf("%d", &n);
            }
        printf("Side lengths: ");
        scanf("%lf", &s);
            if(n < 0){
                printf("Please enter a valid number (Greater than 0): \n");
                scanf("%lf", &s);
            }
        printf("The area of the regular polygon is: %lf \n", area_polygon(n, s));
        break; 

    return 0;
}
}