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

linked_list_t* create(int n)
{
    linked_list_t *head = NULL;
    linked_list_t *temp = NULL;

    if(n > 0)
    {
        for(int i = 0; i < n; i++)
        {
            temp = malloc(sizeof(linked_list_t));
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

    //printf("temp->next : %d\n ", temp->node_data);

    temp->next = malloc(sizeof(linked_list_t));
    temp->node_data = temp->node_data + 1;
    //printf("List item: current is %p", temp->next->node_data);
    temp->next->next = NULL;
}


// TODO: push_to_begin, pop, delete, maybe search,

/*
void pop(linked_list_t *node)
{

}
*/

void print(linked_list_t *node)
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
    list = create(5);
    print(list);

    push_to_end(list);
    //push_to_end(list);
    //push_to_end(list);
    //push_to_end(list);

    print(list);

    return 0;
}
