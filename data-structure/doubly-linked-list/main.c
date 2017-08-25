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

d_linked_list_t* create_list(size_t n)
{
    d_linked_list_t *head = NULL;
    d_linked_list_t *temp = NULL;

    if(n > 0)
    {
        for(size_t i = 0; i < n; i++)
        {
            temp = (d_linked_list_t*)malloc(sizeof(d_linked_list_t));
            if(temp == NULL)
            {
                printf("Allocation memory failed!");
                return NULL;
            }

            temp->node_data = i;
            temp->next = head;
            temp->prev = NULL;

            if(head != NULL)
            {
                head->prev = temp;
            }

            head = temp;
        }
    }

    return head;
}

void print_forward_list(d_linked_list_t *node)
{
    d_linked_list_t *temp = node;

    while (temp != NULL)
    {
        printf("List forward item : current is %p; next is %p; prev is %p;\n",
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
        printf("List backward item : current is %p; next is %p; prev is %p;\n",
               (void*)temp,
               (void*)temp->next,
               (void*)temp->prev);

        temp = temp->prev;
    }
}

void remove_list(d_linked_list_t *node)
{
    /*d_linked_list_t *next = node;
    d_linked_list_t *prev = NULL;

    while(next)
    {
        prev = next->prev;
        prev->next = next->next;
        free(next);
        next = prev;
    }*/
}

int main()
{
    d_linked_list_t *list = NULL;
    list = create_list(4);

    print_forward_list(list);
    //print_backward_list(list);
    //remove_list(list);

    return 0;
}
