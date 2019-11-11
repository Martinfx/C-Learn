#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <memory.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#if DEBUG
#define debug(msg)                                                             \
  do {                                                                         \
    printf("[debug]: %s ,line: %i, file: %s, func: %s \n", msg, __LINE__,      \
           __FILE__, __FUNCTION__);                                            \
  } while (false)
#else
#define debug(msg)                                                             \
  do {                                                                         \
  } while (false)
#endif

#if DEBUG
#define trace(msg, ...)                                                        \
  do {                                                                         \
    printf("[trace]: %s, line: %i, file: %s, func: %s \n", msg, __LINE__,      \
           __FILE__, __FUNCTION__, __VA_ARGS__);                               \
  } while (false)
#else
#define trace(msg, ...)                                                        \
  do {                                                                         \
  } while (false)
#endif

/*
 * push_front(key)        add to front
 * pop_front()            remove front item
 * push_back(key)         add to back
 * pop_back()             remove back item
 * boolean find(key)      is key in list ?
 * erase(key)             remove key from list
 * remove_list()          remove all nodes from list
 * count_nodes()          count of nodes
 * lenght()               lenght of list
 * print_forward_list()   forward prints
 * print_backward_list()  backward prints
 */

typedef struct node {
  unsigned int key, count;
  struct node *next, *head, *tail;
} list_t;

list_t *create_node() {
  list_t *node = (list_t *)malloc(sizeof(list_t));
  if (!node) {
    debug("Allocation memory failed!\n");
    return NULL;
  }

  return node;
}

list_t *create_list() {
  list_t *list = (list_t *)malloc(sizeof(list_t));
  if (!list) {
    debug("Allocation memory failed!\n");
    return NULL;
  }

  memset(list, 0, sizeof(list_t));

  return list;
}

list_t *is_head_empty(list_t *list) {
  if (!list->head) {
    debug("Head is null!\n");
    return list;
  }
  return list;
}

list_t *is_list_empty(list_t *list) {
  if (!list) {
    debug("List is empty!\n");
    return list;
  }
  return list;
}

unsigned int count_nodes(list_t *list) { return list->count; }

unsigned int length_list(list_t *list) {
  unsigned int length = 0;

  if (is_list_empty(list) != NULL) {
    list_t *temp = NULL;
    temp = list->head;

    if (temp != NULL) {
      list_t *curr = NULL;
      for (curr = temp; curr != NULL; curr = curr->next) {
        length = length + 1;
      }
      return length;
    }
    return length;
  }
  return length;
}

list_t *pop_front(list_t *list) {
  if (!list->head) {
    printf("Head is null!\n");
    return list;
  }

  list->count--;
  list_t *temp = NULL;
  temp = list->head;
  list->head = list->head->next;
  free(temp);

  return list;
}

list_t *push_front(list_t *list, unsigned int key) {
  list_t *node = create_node();
  if (node == NULL) {
    return NULL;
  }

  node->key = key;
  node->next = list->head;

  if (list->head == NULL) {
    list->head = node;
    list->count++;
    return list;
  }

  node->next = list->head;
  list->head = node;
  list->count++;

  return list;
}

list_t *push_back(list_t *list, unsigned int key) {
  list_t *node = create_node();
  node->key = key;
  node->next = NULL;

  if (list->head == NULL) {
    list->head = node;
    list->head->next = NULL;
    list->count++;
    return list;
  } else {
    list->count++;
    list_t *temp = list->head;
    while (temp->next) {
      /*printf("temp: %p, temp->next: %p, temp->key: %d \n",
(void*)temp,
(void*)temp->next,
temp->key);*/

      temp = temp->next;
    }

    temp->next = node;
    temp->next->next = NULL;
  }

  return list;
}

list_t *pop_back(list_t *list) {
  list_t *temp = NULL;
  if (list->head == NULL) {
    printf("Head list is null!\n");
    return list;
  }

  if (list->head == list->tail) {
    list->head = NULL;
    list->tail = NULL;
  }

  if (!list->head) {
    return list;
  }

  temp = list->head;
  while (temp->next->next != NULL) {
    printf("List item: current is %p; next is %p; data is %u\n", (void *)temp,
           (void *)temp->next, temp->key);

    temp = temp->next;
  }

  list->count--;
  list->tail = temp;
  free(list->tail->next);
  list->tail->next = NULL;

  return list;
}

void print_forward_list(list_t *list) {
  if (is_list_empty(list) != NULL) {
    list_t *temp = list->head;

    if (!list->head) {
      debug("List->head is null");
    } else {

      printf("------------------------------------------------\n");

      while (temp != NULL) {
        printf("List item: current is %p; next is %p; data is %u\n",
               (void *)temp, (void *)temp->next, temp->key);

        temp = temp->next;
      }
    }
  }
}

void print_backward_list(list_t *list) {
  list_t *current = list->head;
  list_t *last = NULL;

  if (!list->head) {
    debug("List->head is null");
  } else {

    printf("------------------------------------------------\n");

    while (last != list->head) {
      while (current->next != last) {
        current = current->next;
      }

      last = current;

      printf("List item: current is %p; next is %p; data is %u\n", (void *)last,
             (void *)last->next, last->key);

      current = list->head;
    }
  }
}

list_t *remove_list(list_t *list) {
  if (is_list_empty(list) != NULL) {
    list_t *temp = list->head;
    list_t *next = NULL;

    while (temp != NULL) {
      next = temp->next;
      free(temp);
      temp = next;
    }

    free(list);

    list = NULL;
    return list;
  }

  return list;
}

bool find(list_t *list, unsigned int key) {
  list_t *temp = list->head;

  while (temp != NULL) {
    if (temp->key == key) {
      printf("Found key: %u\n", temp->key);
      return true;
    }

    temp = temp->next;
  }

  printf("Cannot found key: %u \n", key);
  return false;
}

list_t *erase(list_t *list, unsigned int pos) {
  list_t *temp1 = list->head;
  list_t *temp2 = NULL;

  if (pos < length_list(list)) {

    for (unsigned int i = 0; i < pos - 1; ++i) {
      /*printf("A im on postion: %u \n", i);
printf("Position: current is %p; next is %p; data is %u\n",
(void*)temp1,
(void*)temp1->next,
temp1->key);*/

      temp1 = temp1->next;
    }

    temp2 = temp1->next;
    temp1->next = temp2->next;
    printf("Remove temp2->key: %u \n", temp2->key);
    free(temp2);
  }
  return list;
}

void remove_duplicate(list_t *list) {
  list_t *temp = list->head;
  if (!temp) {
    debug("Cannot remove duplicite items from list");
  } else {

    while (temp->next != NULL) {
      if (temp->key == temp->next->key) {
        list_t *next = temp->next->next;
        free(temp->next);
        temp->next = next;
        debug("Found duplicate item in list.");
      } else {
        temp = temp->next;
        debug("Not found duplicate item.");
      }
    }
  }
}

int main() {
  list_t *list = create_list();

  for (unsigned int i = 0; i < 10; i++) {
    list = push_front(list, rand() % 100);
  }

  list = pop_back(list);
  printf("Lenght list is %u items.\n", length_list(list));

  find(list, 666);

  print_forward_list(list);
  list = pop_front(list);
  print_forward_list(list);

  printf("Count of nodes: %u \n", count_nodes(list));
  printf("Lenght list is %u items.\n", length_list(list));

  list = push_front(list, 2222);

  print_forward_list(list);
  printf("Lenght list is %u items.\n", length_list(list));
  list = erase(list, 4);
  print_forward_list(list);
  print_backward_list(list);

  printf("Lenght list is %u items.\n", length_list(list));

  list = push_front(list, 99999);
  list = push_front(list, 99999);
  list = push_front(list, 99999);

  remove_duplicate(list);
  print_forward_list(list);

  list = remove_list(list);
  print_forward_list(list);

  return 0;
}

/*
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
        //printf("node: %u, node->next: %u, node->node_data: %u \n", node,
node->next, node->node_data);
        node = node->next;
    }

    node->next = temp;
    node->next->next = NULL;
}

void push_to_begin_pointer_to_pointer(list_t **node, int key)
{
    list_t *temp;
    temp = create_node();
    temp->key = key;
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
    data = (*node)->key;
    free(*node);
    *node = temp;

    return data;
}

list_t *push_to_position(list_t *list, int key, int position)
{
    list_t *node = NULL;
    node = create_node();
    node->key = key;

    if(list->head == NULL)
    {
        list->head = node;
        return list;
    }
    else
    {
        list_t *last = list->head;
        int p = 0;

        if(position == 0)
        {
            node->next = list->head;
            return list;
        }

        while(last != NULL)
        {
            printf("Postion: %u \n", last->key);
            if(p == position - 1)
            {
                node->next = last->next;
                last->next = node;
            }
            else
            {
                last = last->next;
            }

            p = p + 1;
        }

        return list;
    }
}

*/

#endif
