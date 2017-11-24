#include <stdio.h>
#include <stdlib.h>

/*
 * Example for data structur linked list.
 * Allows operations:
 * create node,
 * create linked list,
 * push to begin,
 * push to end,
 * lenght list,
 * pop,
 * remove list,
 * print list
 * search item
 */

typedef struct list
{
    int node_data;
    struct list *next;
} list_t;

/*
 * Create node and return allocated item
 */
list_t *create_node()
{
    list_t *node = NULL;

    node = (list_t*)malloc(sizeof(list_t));
    if(node == NULL)
    {
        printf("Allocation memory failed!");
        return NULL;
    }

    node->next = NULL;

    return node;
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
            temp->node_data = i;
            temp->next = head;
            head = temp;
        }
    }

    return head;
}

int length_list(list_t *head)
{
    int length = 0;

    if(head != NULL)
    {
        list_t *curr = NULL;
        for(curr = head; curr != NULL; curr = curr->next)
        {
            length = length + 1;
        }

        return length;
    }

    return length;
}

list_t *push_to_end(list_t *head, int data)
{
    list_t *node = create_node();
    node->node_data = data;
    node->next = NULL;

    if(head == NULL)
    {
        head = node;
        head->next = NULL;
        return head;
    }
    else
    {
        list_t *temp = head;
        while(temp->next)
        {
            //printf("node: %d, node->next: %d, node->node_data: %d \n", node, node->next, node->node_data);
            temp = temp->next;
        }

        temp->next = node;
        temp->next->next = NULL;
    }

    return  head;
}

void push_to_end_without_return(list_t *node)
{
    list_t *temp = create_node();
    temp->next = NULL;

    // This is good idea, but we cannot return value
    if(node == NULL)
    {
        node = create_node();
    }

    while(node->next)
    {
        //printf("node: %d, node->next: %d, node->node_data: %d \n", node, node->next, node->node_data);
        node = node->next;
    }

    node->next = temp;
    node->next->next = NULL;
}

list_t *push_to_front(list_t *head, int data)
{
    list_t *node = create_node();
    node->node_data = data;
    node->next = NULL;

    if(head == NULL)
    {
        head = node;
        head->next = NULL;
        return head;
    }

        ///list_t *temp = head;
    node->next = head;
    head = node;
    return head;
}

/*
 * Push item to begin list with pointer to pointer
 */
void push_to_begin_pointer_to_pointer(list_t **node, int data)
{
    list_t *temp;
    temp = create_node();
    temp->node_data = data;
    temp->next = *node;
    *node = temp;
}

int pop(list_t **node)
{
    int data = 0;
    list_t *temp = NULL;

    if(*node == NULL)
    {
        return -1;
    }

    temp = (*node)->next;
    data = (*node)->node_data;
    free(*node);
    *node = temp;

    return data;
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

void print_list(list_t *head)
{
    while(head != NULL)
    {
        printf("List item: current is %p; next is %p; data is %d\n", (void*)head, (void*)head->next, head->node_data);
        head = head->next;
    }
}

int search_key(list_t *head, int item)
{
    list_t *temp = head;

    if(head == NULL)
    {
        printf("Cannot find item!");
    }

    while(temp->node_data != item)
    {
        temp = temp->next;

        if(temp->node_data == item)
        {
            printf("Found item: %d\n", temp->node_data);
        }
    }
}

int main()
{
    list_t *list = NULL;
    list = create_linked_list(5);
    print_list(list);

    printf("Lenght list is %d items.\n", length_list(list));

    list = push_to_end(list, 255);
    list = push_to_end(list, 333);
    print_list(list);

    list = push_to_front(list, 20);
    list = push_to_front(list, 88);
    print_list(list);

    search_key(list, 255);

    printf("Lenght list is %d items.\n", length_list(list));

    pop(&list);
    pop(&list);
    print_list(list);

    printf("Lenght list is %d items.\n", length_list(list));

    remove_list(list);

    return 0;
}
