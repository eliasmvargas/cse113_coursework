#include <stdio.h>
#include <math.h>
#include <ctype.h>
#define SIZE 5

struct zombie{
  enum {MONDAY =1, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY} day;
  union{
    float blood;
    int toes; 
  } note; 
  int hour;
  int min;
  int sec;
  char dead; /* 'y' if dead 'n' if alive */
};

struct zombie zombie_h[4];
int i;

int printmenu(void);
void print_zombies(struct zombie zombie_h[]);
void input_time(struct zombie zombie_h[i], int i);
void input_toes(struct zombie zombie_h[i], int i);
void input_blood(struct zombie zombie_h[i], int i);