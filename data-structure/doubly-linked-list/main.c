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

    printf("Node created successfully \n");

    return head;
}

d_linked_list_t* create_list(size_t n)
{
    d_linked_list_t *head = NULL;
    d_linked_list_t *last = NULL;

    for(size_t i = 0; i < n; i++)
    {
        head = (d_linked_list_t*)malloc(sizeof(d_linked_list_t));
        if(head == NULL)
        {
            printf("Allocation memory failed!");
            return NULL;
        }

        head->prev = create_node(i);
        head->next = NULL;
        head->node_data = i;

        last->next = head;
        last = head;
    }

    return last;
}

void print_foward_list(d_linked_list_t *node)
{
    d_linked_list_t *temp = node;

    if(node)
    {
        printf("List is empty!\n");
    }

    while (temp != NULL)
    {
        printf("List item : current is %p; next is %p; prev is %p;\n",
               (void*)temp,
               (void*)temp->next,
               (void*)temp->prev);

        temp = temp->next;
    }
}


void remove_list(d_linked_list_t *node)
{
    d_linked_list_t *next = node;
    d_linked_list_t *prev = NULL;

    while(next)
    {
        prev = next->prev;
        prev->next = next->next;
        free(next);
        next = prev;
    }
}

int main()
{
    d_linked_list_t *list = NULL;
    list = create_list(4);

    print_foward_list(list);

    //remove_list(list);

    return 0;
}
