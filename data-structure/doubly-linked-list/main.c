#include <stdio.h>
#include <stdlib.h>

/*
 * Example for data structure double linked list.
 * Allows operations push, pop, remove, delete item.
 */

typedef struct d_linked_list
{
    int node_data;
    struct d_linked_list *next;
    struct d_linked_list *prev;

} d_linked_list_t;

d_linked_list_t* create_list(int n)
{
    d_linked_list_t *head = NULL;
    d_linked_list_t *temp = NULL;

    if(n > 0)
    {
        for(int i = 0; i < n; i++)
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

void print_list(d_linked_list_t *head)
{
    d_linked_list_t *temp = head;

    while (temp != NULL)
    {
        printf("list item : current is %p; next is %p; prev is %p;\n", (void*)temp, (void*)temp->next, (void*)temp->prev);
        temp = temp->next;
    }
}

int main()
{
    //printf("xxxxxxxxxxxxxxxxxxxxxxx");
    d_linked_list_t *list = NULL;
    list = create_list(4);

    print_list(list);

    return 0;
}
