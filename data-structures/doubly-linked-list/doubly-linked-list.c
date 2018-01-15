#include <stdio.h>
#include <stdlib.h>

/*
 * Example for data structure doubly linked list.
 * Allows operations create node, list, push, pop, remove.
 */

typedef struct d_list
{
    int key;
    struct d_list *next;
    struct d_list *prev;
} d_list_t;

d_list_t *create_node()
{
    d_list_t *head = NULL;

    head = (d_list_t*)malloc(sizeof(d_list_t));
    if(head == NULL)
    {
        printf("Allocation memory failed!");
        return NULL;
    }

    head->next = NULL;
    head->prev = NULL;
    head->key = 0;

    return head;
}

d_list_t* create_list()
{
    d_list_t *list = NULL;
    list = (d_list_t*)malloc(sizeof(d_list_t));
    if(list == NULL)
    {
        printf("Allocation memory failed!");
        return NULL;
    }

    list->next = NULL;
    list->prev = NULL;
    list->key = 0;

    return list;
}

int print_length_list(d_list_t *head)
{
    int length = 0;
    d_list_t *curr = NULL;
    for(curr = head; curr != NULL; curr = curr->next)
    {
        length = length + 1;
    }

    return length;
}

void print_forward_list(d_list_t *node)
{
    d_list_t *temp = node;

    if(node == NULL)
    {
        printf("List is empty!\n");
    }

    printf("------------------------------------------------\n");

    while (temp != NULL)
    {
        printf("Forward list item: "
               "current is %p; "
               "next is %p; "
               "prev is %p; "
               "key is %d\n",
               (void*)temp,
               (void*)temp->next,
               (void*)temp->prev,
               temp->key);

        temp = temp->next;
    }
}


void print_backward_list(d_list_t *node)
{
    d_list_t *temp = node;

    if(node == NULL)
    {
        printf("List is empty!\n");
    }

    printf("------------------------------------------------\n");

    // Go to for last node
    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    while (temp != NULL)
    {
        printf("Backward list item: "
               "current is %p; "
               "next is %p; "
               "prev is %p; "
               "key is %d\n",
               (void*)temp,
               (void*)temp->next,
               (void*)temp->prev,
               temp->key);

        temp = temp->prev;
    }
}

void push_back(d_list_t *head, int key)
{
    d_list_t *temp = head;
    d_list_t *node = create_node();
    node->key = key;

    if(head == NULL)
    {
        head = node;
    }

    while(temp->next != NULL)
    {
        //printf("while : %zu\n", temp->node_data);
        temp->key = temp->key + 1;
        temp = temp->next;
    }

    temp->next = node;
    node->prev = temp;

    //printf("List item: current is %zu \n", temp->next->node_data);
}

void push_to_begin(d_list_t **head)
{
    d_list_t *node = create_node();
    node->key = (*head)->key + 1;
    node->next = (*head);
    node->prev = NULL;
    (*head) = node;
}

void remove_list(d_list_t *node)
{
    d_list_t *temp = NULL;

    while(node != NULL)
    {
        temp = node;
        node = node->next;
        free(temp);
    }

    printf("List removed.\n");
}

void pop(d_list_t **node)
{
    d_list_t *temp = NULL;
    temp = (*node)->next;
    free((*node));
    (*node) = temp;
}

int main()
{
    d_list_t *head_list= NULL;
    head_list = create_list();

    for(int i = 0; i < 10; i++)
    {
        push_back(head_list, i);
    }

    print_forward_list(head_list);
    print_backward_list(head_list);

    push_back(head_list, 2000);
    printf("Count of node in list : %d \n",
           print_length_list(head_list));

    push_to_begin(&head_list);
    printf("Count of node in list : %d \n",
           print_length_list(head_list));

    pop(&head_list);
    printf("Count of node in list : %d \n",
           print_length_list(head_list));

    remove_list(head_list);

    return 0;
}
