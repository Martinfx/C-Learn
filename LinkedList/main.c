#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList
{
    int m_list_data;
    struct LinkedList *m_next;
} LinkedList;


int main()
{
    LinkedList *head = NULL, *temp = NULL;

    for(int i = 0; i < 3; i++)
    {
        temp = malloc(sizeof(LinkedList));
        temp->m_list_data = i;
        temp->m_next = head;
        head = temp;
    }

    temp = head;

    while(temp != NULL)
    {
        printf("List item: current is %p; next is %p; data is %d\n", temp, temp->m_next, temp->m_list_data);
        temp = temp->m_next;
    }

    return 0;
}
