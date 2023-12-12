#include <stdio.h>
#include <stdlib.h>

struct node_t {
    double x;
    struct node_t *next;
};

struct node_t *create_node(double data);
void print_node(struct node_t *head);
struct node_t *insert_head(struct node_t*head,struct node_t *node);
struct node_t *insert_middle(struct node_t *head,struct node_t *node,int position);
struct node_t *insert_tail(struct node_t *head, struct node_t *node);
void print_list(struct node_t *head);
struct node_t *delete_node(struct node_t *head, double del);
void delete_list(struct node_t *head);
int count_nodes(struct node_t *head);
struct node_t *find_node(struct node_t *head, double finder);
int printmainmenu(void);
int submenu(void);