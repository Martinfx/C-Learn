#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/****************************************************
 * Methods for implementation
 ****************************************************
 * push_front(key)        add to front
 * pop_front()            remove front item
 * push_back(key)         add to back
 * pop_back()             remove back item
 * boolean find(key)      is key in list ?
 * erase(key)             remove key from list
 * remove_list()          remove all nodes from list
 * count_nodes()          count of nodes
 * lenght()               lenght of list
 * print_forward_list()   print list forward
 * print_backward_list()  print list backward
 *
 * *************************************************
 * Not implemented
 * *************************************************
 * (key) top_back()    return back item
 * (key) TopFront()    return front item
 * *************************************************
 */

typedef struct node
{
    int key;
    int count;
    struct node *next;
    struct node *head;
    struct node *tail;
} list_t;

list_t *create_list();
list_t* push_front(list_t *list, int key);
list_t* pop_front(list_t *list);
list_t *push_back(list_t *list, int key);
list_t *pop_back(list_t *list);
list_t *remove_list(list_t *list);
list_t *erase(list_t *list, int pos);

void print_forward_list(list_t *list);
void print_backward_list(list_t *list);

bool find(list_t *list, int key);
int length_list(list_t *list);

#endif
