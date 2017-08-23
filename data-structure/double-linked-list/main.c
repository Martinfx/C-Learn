#include <stdio.h>
#include <stdlib.h>

/*
 * Example for data structure double linked list.
 * Allows operations push, pop, remove, delete item.
 */

typedef struct double_linked_list
{
    int node_data;
    struct double_linked_list *next;
    struct double_linked_list *prev;

} double_linked_list_t;

double_linked_list_t* create_double_linked_list(int n)
{
    double_linked_list_t *head = NULL;
    double_linked_list_t *temp = NULL;

    head->next = head;
    head->prev = head;
    //head->node_data = -1;

    //printf("list item : current is %p; next is %p; prev is %p;\n", (void*)temp, (void*)temp->next, (void*)temp->prev);

    if(n > 0)
    {
        for(int i = 0; i < n; i++)
        {
            temp = (double_linked_list_t*)malloc(sizeof(double_linked_list_t));
            if(temp == NULL)
            {
                printf("Pointer is NULL: ");
                return NULL;

            }

            temp->node_data = i;
            temp->next = head->next;
            head->next = temp;
            temp->prev = head;
            temp->next->prev = temp;

            printf("Next item: ");

        }
    }

    return head;
}

void print_list(double_linked_list_t *head)
{
    double_linked_list_t *temp = NULL;

    temp = head->next;
    while (temp != head)
    {
        printf("list item : current is %p; next is %p; prev is %p;\n", (void*)temp, (void*)temp->next, (void*)temp->prev);
        temp = temp->next;
    }
}

int main()
{
    //printf("xxxxxxxxxxxxxxxxxxxxxxx");
    //double_linked_list_t *list = NULL;
    //list = create_double_linked_list(5);
    //print_list(list);

    return 0;
}
