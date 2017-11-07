#include <stdio.h>
#include <stdlib.h>

/*
 * Example for data structure circual linked list.
 * Allows operations:
 * create node,
 * create linked list,
 * push to begin,
 * remove list,
 * print list
 */

typedef struct list
{
    int data;
    struct list *next;
} list_t;

/*
 * Create node and return allocated item
 */
list_t *create_node()
{
    list_t *node = NULL;
    list_t *head = NULL;

    node = (list_t*)malloc(sizeof(list_t));
    if(node == NULL)
    {
        printf("Allocation memory failed!");
        return NULL;
    }

    node->next = node;
    head = node;
    return head;
}

list_t* create_linked_list(int n)
{
    list_t *head = NULL;
    list_t *temp = NULL;

    if(n > 0)
    {
        for(int i = 0; i < n; i++)
        {
            temp = create_node();
            temp->data = i;
            temp->next = head;
            head = temp;
        }
    }

    return head;
}

void print_list(list_t *head)
{
    if(head == NULL)
    {
        printf("List is empty! ");
        return;
    }
    else
    {
        list_t *temp = NULL;

        if (head == NULL)+
        {
            printf("List is empty.");
            return;
        }

        temp = head->next;

        do
        {
            printf("Item list : %d \n", temp->data);
            temp = temp->next;

        }
        while(temp != head->next);
    }
}

list_t *push_to_begin(list_t *head, int data)
{
    list_t *node = create_node();
    node->data = data;
    node->next = NULL;

    if(head == NULL)
    {
        head = node;
        head->next = node;
        return head;
    }

    node->next = head->next;
    head->next = node;
    head = node;
    return head;
}

void remove_list(list_t *node)
{
    list_t *temp = node;
    list_t *next = node;

    while(temp)
    {
        next = temp->next;
        free(temp);
        temp = next;
    }

    node = NULL;
}
int main()
{
    list_t *list = NULL;
    list = create_node();

    list = push_to_begin(list, 222);

    print_list(list);

   // remove_list(list);

    return 0;
}
