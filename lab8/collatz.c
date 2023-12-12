/**
 * @file collatz.c
 * @author Elias Vargas
 * @brief Tests the collatz conjecture
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <stdlib.h>

struct node_t{
    int data;
    struct node_t* next;
};

void printy(int count, struct node_t *head);

int main()
{
    //
    int n = 0;
    int count = 0;
    printf("Enter a natural number greater than 1: \n"); 
    scanf("%d",&n);
    freopen("hailstone","w",stdout); //output to file hailstone
    //
    // establishing head and tail nodes
    struct node_t* head=NULL;
    struct node_t* tail=NULL;

    while(1)
    {
        //algorithm temp var
        struct node_t *temp = NULL;
        temp = malloc(sizeof(struct node_t));
        temp->data=n;
        temp->next=NULL;

        if(head==NULL){ //making sure everything works
            head=temp;
            tail=temp;
        }

        else{
            tail->next=temp;
            tail=tail->next;
        }
        ++count;

        if(n == 1){ // stops while loop when data reaches 1
            break;
        }

        if(n % 2==0){
            n = n / 2;
        }

        else
        n = (n * 3)+1;
    }
    printy(count, head);
}

/**
 * @brief Prints the list 
 * 
 * @param count number of nodes
 * @param head head node
 */
void printy(int count, struct node_t *head){
    printf("cycle length = %d\n",count);
    while(head!=NULL)
    {
        printf("%d",head->data);
        head=head->next;
    }
    printf("\n");
}