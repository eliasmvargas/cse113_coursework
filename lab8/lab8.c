/**
 * @file lab8.c
 * @author Elias Vargas
 * @brief Works with linked lists in various ways
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>
#include "lab8.h"

int main(){
    int position = 0;
    double data = 0;
    struct node_t *head = NULL;
    int p = 0;
    while(p != 6){
        p = printmainmenu();
        if (p == 1){
                printf("Enter data: \n");
                scanf("%lf", &data);
                struct node_t *node = create_node(data);
                printf("... \n");
                printf("Node created! \nPlease select a location: \n");
                p = submenu();
                switch(p){
                    case 'a':
                        head = insert_head(head, node);
                        printf("Header node inserted.\n");
                        printf("\n_____________\n");
                        break;
                    
                    case 'b':
                        printf("Please enter location index: \n");
                        scanf("%d", &position);
                        head = insert_middle(head, node, position);
                        printf("Node inserted.\n");
                        printf("\n_____________\n");
                        break;

                    case 'c':
                        head = insert_tail(head, node);
                        printf("Tail node inserted.\n");
                        printf("\n_____________\n");
                        break;
                }
            }
        else if(p == 2){
            printf("Which number would you like to delete?\n");
            double del = 0;
            scanf("%lf", &del);
            head = delete_node(head, del);
            printf("...\n");
            printf("Node removed!\n");
        }
        else if (p == 3){
            printf("\n\n DATA:\n");
            print_list(head);
            printf("\n\n");
        }
        else if (p == 4){
            count_nodes(head);
            printf("\n");
        }
        else if (p == 5){
            double finder_I_hardly_know_her = 0;
            printf("Which number are you looking for? \n");
            scanf("%lf", &finder_I_hardly_know_her);
            struct node_t *f_node = find_node(head, finder_I_hardly_know_her);
            if (f_node != NULL){
                printf("Data entry: %lf exists in the list. \n", finder_I_hardly_know_her);
            }
            else{
                printf("Not found in the list\n");
            }

        }
    }
    if (p == 6){
        delete_list(head);
    }
}

/**
 * @brief Create a node object
 * 
 * @param data 
 * @return struct node_t* 
 */
struct node_t *create_node(double data)
{
        struct node_t *node = NULL;
        node = malloc(sizeof(struct node_t));
        node->x = data;
        node->next = NULL;
        return node;
}

/**
 * @brief Print a node
 * 
 * @param head 
 */
void print_node(struct node_t *head){
    printf("DATA: %lf\n",head->x);
}

/**
 * @brief Insert a head node
 * 
 * @param head 
 * @param node 
 * @return struct node_t* 
 */
struct node_t *insert_head(struct node_t*head, struct node_t *node)
{
    node->next = head;
    head = node;
    return head;
}

/**
 * @brief Insert a node in the middle of the list
 * 
 * @param head 
 * @param node 
 * @param position 
 * @return struct node_t* 
 */
struct node_t *insert_middle(struct node_t *head,struct node_t *node,int position){
        if(head == NULL || position == 0)
        return(insert_head(head,node));
        else if(position >= count_nodes(head))
        return(insert_tail(head,node));
        else{
            struct node_t *current = head;
            struct node_t *previous = NULL;

            int i =0;

            while(current != NULL)
            {
                if(i == position)
                {
                    previous->next = node;
                    node->next = current;
                    return head;
                }
                previous = current;
                current = current->next;
                i++;
            }
            return head;
        }
}
/**
 * @brief Insert a node in the tail of a list 
 * 
 * @param head 
 * @param node 
 * @return struct node_t* 
 */
struct node_t *insert_tail(struct node_t *head, struct node_t *node){
    if(head == NULL){
        return insert_head(head, node);
    }
    else{
        struct node_t *ptr;
        ptr = head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = node;
        }
    return head;
}

/**
 * @brief Prints the linked list 
 * 
 * @param head 
 */
void print_list(struct node_t *head){
    if (head == NULL)
        printf ("List is empty\n");
    struct node_t *ptr = NULL;
    ptr = head;
    while (ptr != NULL){
        print_node(ptr);
        ptr = ptr->next;
    }
}

/**
 * @brief Deletes a node by value
 * 
 * @param head 
 * @param del 
 * @return struct node_t* 
 */
struct node_t *delete_node(struct node_t *head, double del){
    struct node_t *node_removal = find_node(head, del);
    if (node_removal == NULL){
        return head;
    }
    if (node_removal == head){
        head = head->next;
        free(node_removal);
        return head;
    }
    struct node_t *ptr = head;
    struct node_t *back = head;
    while(ptr != NULL){
        if(ptr == node_removal){
            back->next = ptr->next;
            free(ptr);
            return head;
        }
        back = ptr;
        ptr = ptr->next;
    }
    return head;
}

/**
 * @brief Deletes the entire list
 * 
 * @param head 
 */
void delete_list(struct node_t *head){
    struct node_t *ptr;
    while(head != NULL){
        ptr = head;
        head = head->next;
        free(ptr);
    }
}

/**
 * @brief Counts number of nodes in the list 
 * 
 * @param head 
 * @return int 
 */
int count_nodes(struct node_t *head){
    int count = 0;
    if(head == NULL)
        printf("Empty list");
    struct node_t *ptr = NULL;
    ptr = head; 
    while (ptr != NULL) {
        count++;
        ptr = ptr->next;
    }
    printf("The total number of nodes is: %d", count);
    return count;
}

/**
 * @brief Finds a node by value in list
 * 
 * @param head 
 * @param finder 
 * @return struct node_t* 
 */
struct node_t *find_node(struct node_t *head, double finder){
    struct node_t*ptr= head;
    while(ptr != NULL)
    {
        if(isgreaterequal(ptr->x,finder) && islessequal(ptr->x,finder))
        return ptr;
        ptr = ptr->next;
    }
    return NULL;
}

/**
 * @brief Prints the main menu
 * 
 * @return int 
 */
int printmainmenu(void){
    int t = 0;
    printf("1) Enter a number\n");
    printf("2) Delete a number\n");
    printf("3) Print all numbers\n");
    printf("4) Count number of items in list\n");
    printf("5) Search the list for a number\n");
    printf("6) Quit\n");
    scanf("%d", &t);
    while(t > 6 | t < 1){
        printf("Please enter a valid selection\n");
        scanf("%d", &t);
    }
        return t;
}

/**
 * @brief Prints the submenu for prompt 1
 * 
 * @return int 
 */
int submenu(void){
    char r = 0;
    printf("a) Head of the list\n"); 
    printf("b) Middle of the list\n");
    printf("c) Tail of the list\n");
    scanf("%c", &r);
    while(r > 'c' | r < 'a'){
        printf("Please enter a valid selection\n");
        scanf("%c", &r);
    }
    return r;
}

