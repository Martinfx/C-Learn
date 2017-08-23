#include <stdio.h>
#include <stdlib.h>

/*
 * Example for data structur linked list.
 * Allows operations push, pop, remove, delete item.
 */

typedef struct linked_list
{
    int node_data;
    struct linked_list *next;
} linked_list_t;

linked_list_t* create_linked_list(int n)
{
    linked_list_t *head = NULL;
    linked_list_t *temp = NULL;

    if(n > 0)
    {
        for(int i = 0; i < n; i++)
        {
            temp = malloc(sizeof(linked_list_t));
            if(temp == NULL)
            {
                printf("Allocation memory failed!");
                return NULL;
            }

            temp->node_data = i;
            temp->next = head;
            head = temp;
        }
    }

    return head;
}

void push_to_end(linked_list_t *node)
{
    linked_list_t *temp = node;

    while(temp->next != NULL)
    {
        //printf("while : %d\n", temp->node_data);
        //temp->next->node_data = temp->next->node_data + 1;
        temp->node_data = temp->node_data + 1;
        temp = temp->next;
    }

    temp->next = malloc(sizeof(linked_list_t));
    temp->node_data = temp->node_data + 1;
    //printf("List item: current is %p", temp->next->node_data);
    temp->next->next = NULL;
}

void push_to_begin(linked_list_t **node)
{
    linked_list_t *temp;
    temp = malloc(sizeof(linked_list_t));
    temp->node_data = temp->node_data + 1;
    temp->next = *node;
    *node = temp;
}

int pop(linked_list_t **node)
{
    int return_val;
    linked_list_t *temp = NULL;

    if(*node == NULL)
    {
        return -1;
    }

    temp = (*node)->next;
    return_val = (*node)->node_data;
    free(*node);
    *node = temp;

    return return_val;
}

void remove_list(linked_list_t *node)
{
    linked_list_t *temp = node;
    linked_list_t *next = node;

    while(temp)
    {
        next = temp->next;
        free(temp);
        temp = next;
    }
}


void print_list(linked_list_t *node)
{
    linked_list_t *temp = node;

    while(temp != NULL)
    {
        printf("List item: current is %p; next is %p; data is %d\n", (void*)temp, (void*)temp->next, temp->node_data);
        temp = temp->next;
    }
}

int main()
{
    linked_list_t *list;
    list = create_linked_list(5);
    print_list(list);

    push_to_end(list);
    push_to_end(list);
    print_list(list);

    push_to_begin(&list);
    push_to_begin(&list);
    print_list(list);

    pop(&list);
    pop(&list);
    print_list(list);

    remove_list(list);

    return 0;
}
