#include <stdio.h>
#include <stdlib.h>

/*
 * Example for data structure double linked list.
 * Allows operations push, pop, remove, delete item.
 */

typedef struct d_linked_list
{
    size_t node_data;
    struct d_linked_list *next;
    struct d_linked_list *prev;

} d_linked_list_t;

d_linked_list_t *create_node(size_t n)
{
    d_linked_list_t *head = NULL;

    head = (d_linked_list_t*)malloc(sizeof(d_linked_list_t));
    if(head == NULL)
    {
        printf("Allocation memory failed!");
        return NULL;
    }

    head->next = NULL;
    head->prev = NULL;
    head->node_data = n;

    return head;
}

d_linked_list_t* create_list(size_t n)
{
    d_linked_list_t *curr = NULL;
    d_linked_list_t *first = NULL;

    for(size_t i = 0; i < n; i++)
    {
        /*curr = create_node(i);
        if(first == NULL)
        {
            first = curr;
        }

        first->prev = curr;
        curr->next = first;
        first = curr;  */

        curr = create_node(i);
        curr->next = first;
        curr->prev = NULL;
        if(first)
        {
            first->prev = curr;
        }

        first = curr;
    }

    return first;
}

void print_foward_list(d_linked_list_t *node)
{
    d_linked_list_t *temp = node;

    while (temp != NULL)
    {
        printf("List item : current is %p; next is %p; prev is %p;\n",
               (void*)temp,
               (void*)temp->next,
               (void*)temp->prev);

        temp = temp->next;
    }
}

void print_backward_list(d_linked_list_t *node)
{
    d_linked_list_t *temp = node;

    while (temp != NULL)
    {
        printf("List item : current is %p; next is %p; prev is %p;\n",
               (void*)temp,
               (void*)temp->next,
               (void*)temp->prev);

        temp = temp->prev;
    }
}


void remove_list(d_linked_list_t *node)
{
    d_linked_list_t *temp = NULL;

    while(node != NULL)
    {
        temp = node;
        node = node->next;
        free(temp);
    }

    /*d_linked_list_t *next = node;
    d_linked_list_t *prev = NULL;

    while(next)
    {
        prev->prev = next->prev;
        prev->next = next->next;
        free(next);
        next = prev;
    }*/
}

int main()
{
    d_linked_list_t *list = NULL;
    list = create_list(4);

    print_foward_list(list);
    //print_backward_list(list);
    remove_list(list);

    return 0;
}
