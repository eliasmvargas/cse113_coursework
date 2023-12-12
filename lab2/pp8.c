/**
* @file pp8.c
* @author Elias Vargas
* @date 10/05/23
* @brief Gives the closest flight departure and arrival time for a given flight table list
*/

#include <stdio.h>
#include <stdlib.h>

int ttime, arrival, departure, minutes, hours;
int d_arr[] = {8*60, 9*60+43, 11*60+19, 12*60+47, 14*60, 15*60+45, 19*60, 21*60+45}; // converting times into minutes since midnight
int a_arr[] = {10*60+16, 11*60+452, 13*60+31, 15*60, 16*60+8, 17*60+55, 21*60+20, 23*60+58};


int main(void){

    printf("Please enter a 24-hour time in hours and minutes (HH MM): \n");
    scanf("%d:%d", &hours, &minutes);
    if ((hours | minutes) < 0 ){
        printf("Please enter a valid time: \n");
        scanf("%d:%d", &hours, &minutes);
    }

    ttime = hours * 60 + minutes; // Converts user input into minutes since midnight

    if (ttime <= d_arr[0]){  // 8 am 
        departure = d_arr[0];
        arrival = a_arr[0];
    }
    else if(ttime <= d_arr[1]){ // Adjusts the inequality to be between the next available flight for comparison
        departure = (ttime - d_arr[0]) <= (d_arr[1] - ttime) ? d_arr[0] : d_arr[1]; // 9:43 am
        arrival = (ttime - d_arr[0]) <= (d_arr[1] - ttime) ? a_arr[0] : a_arr[1];
    }
    else if(ttime <= d_arr[2]){ 
        departure = (ttime - d_arr[1]) <= (d_arr[2] - ttime) ? d_arr[1] : d_arr[2]; // 11:10 am
        arrival = (ttime - d_arr[1]) <= (d_arr[2] - ttime) ? a_arr[1] : a_arr[2];
    }
     else if(ttime <= d_arr[3]){
        departure = (ttime - d_arr[2]) <= (d_arr[3] - ttime) ? d_arr[2] : d_arr[3]; // 12:47 am
        arrival = (ttime - d_arr[2]) <= (d_arr[3] - ttime) ? a_arr[2] : a_arr[3];
    }
     else if(ttime <= d_arr[4]){
        departure = (ttime - d_arr[3]) <= (d_arr[4] - ttime) ? d_arr[3] : d_arr[4]; // 2:00 pm
        arrival = (ttime - d_arr[3]) <= (d_arr[4] - ttime) ? a_arr[3] : a_arr[4];
    }
     else if(ttime <= d_arr[5]){
        departure = (ttime - d_arr[4]) <= (d_arr[5] - ttime) ? d_arr[4] : d_arr[5]; // 3:45 pm
        arrival = (ttime - d_arr[4]) <= (d_arr[5] - ttime) ? a_arr[4] : a_arr[5];
    }
     else if(ttime <= d_arr[6]){
        departure = (ttime - d_arr[5]) <= (d_arr[6] - ttime) ? d_arr[5] : d_arr[6]; // 7:00 pm
        arrival = (ttime - d_arr[5]) <= (d_arr[6] - ttime) ? a_arr[5] : a_arr[6];
    }
     else {
        departure = (ttime - d_arr[6]) <= (d_arr[7] - ttime) ? d_arr[6] : d_arr[7]; // 9:45 pm
        arrival = (ttime - d_arr[6]) <= (d_arr[7] - ttime) ? a_arr[6] : a_arr[7];
    }

    hours = departure / 60;
    minutes = departure - (hours * 60);

    if(hours >= 12){  // converting 24hr time to 12hr time
        if (hours != 12)
            hours = hours - 12;
            printf ("Closest departure time is %d:%.2dpm, ", hours, minutes);
        }
    else{
            printf ("Closest departure time is %d:%.2dam, ", hours, minutes);
        }


    hours = arrival / 60;
    minutes = arrival - (hours * 60);

    if(hours >= 12){  // converting 24hr time to 12hr time
        if (hours != 12)
            hours = hours - 12;
            printf ("arriving at %d:%.2dpm. \n", hours, minutes);
        }
    else{
            printf ("arriving at %d:%.2dam. \n", hours, minutes);
        }

    return 0;
}