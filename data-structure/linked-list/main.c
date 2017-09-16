#include <stdio.h>
#include <stdlib.h>

/*
 * Example for data structur linked list.
 * Allows operations push, pop, remove, delete item.
 */

typedef struct list
{
    int node_data;
    struct list *next;
} list_t;

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

list_t *push_to_end_return_head(list_t *node)
{
    if(node == NULL)
    {
        node = create_node();
        return node;
    }
    else
    {
        while(node->next)
        {
            //printf("node: %d, node->next: %d, node->node_data: %d \n", node, node->next, node->node_data);
            node = node->next;
        }

        node->next = create_node();
        node->next->next = NULL;
    }

    return  node;
}

void push_to_end(list_t *node)
{

    /*
     * This is good idea, but we havent return value
    if(node == NULL)
    {
        node = create_node();
    }
    */

    while(node->next)
    {
        //printf("node: %d, node->next: %d, node->node_data: %d \n", node, node->next, node->node_data);
        node = node->next;
    }

    node->next = create_node();
    node->next->next = NULL;
}

void push_to_begin(list_t **node)
{
    list_t *temp;
    temp = create_node();
    temp->node_data = temp->node_data + 1;
    temp->next = *node;
    *node = temp;
}

int pop(list_t **node)
{
    int return_val;
    list_t *temp = NULL;

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
}

void print_list(list_t *node)
{
    list_t *temp = node;

    while(temp != NULL)
    {
        //printf("List item: current is %p; next is %p; data is %d\n", (void*)temp, (void*)temp->next, temp->node_data);
        temp = temp->next;
    }
}

int main()
{
    list_t *list;
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
