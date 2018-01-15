#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"
/*
typedef struct node
{
    int key;
    int height;
    struct node *left;
    struct node *right;
} tree_t;
*/

tree_t *create_node()
{
    tree_t *node = NULL;
    node = (tree_t*)malloc(sizeof(tree_t));
    if(node == NULL)
    {
        printf("Allocation memory failed list_t!\n");
        return NULL;
    }

    node->left = NULL;
    node->right = NULL;

    return node;
}

tree_t *create_tree()
{
    tree_t *node = NULL;
    node = (tree_t*)malloc(sizeof(tree_t));
    if(node == NULL)
    {
        printf("Allocation memory failed!");
        return NULL;
    }

    node->key = 0;
    node->left = NULL;
    node->right = NULL;

    return node;
}

tree_t *insert(tree_t *tree, int key)
{
    //printf("Insert key: %d \n", key);

    // Empty tree , create new node
    if(tree == NULL)
    {
        tree = create_node();
        tree->key = key;
        tree->left = NULL;
        tree->right = NULL;
    }
    else if(key < tree->key)
    {
        // Insert in left
        tree->left = insert(tree->left, key);
    }
    else if(key > tree->key)
    {
        // Insert in right
        tree->right = insert(tree->right, key);
    }
    return tree;
}

tree_t *search(tree_t *tree, int key)
{
    while(tree != NULL && tree->key != key)
    {
        if(key < tree->key)
        {
            tree = tree->left;

            if(tree->key == key)
            {
                printf("Found key: %d\n", key);
            }
        }
        else
        {
            tree = tree->right;

            if(tree->key == key)
            {
                printf("Found key: %d\n", key);
            }
        }
    }

    return tree;
}

int height(tree_t* tree)
{
    if(tree == NULL)
    {
        return 0;
    }

    tree->height =  1 + max(height(tree->left), height(tree->right));

    return tree->height;
}

void print_in_order(tree_t *tree)
{
    if(tree->left != NULL)
    {
        print_in_order(tree->left);
    }

    printf("printInOrder: %d \n", tree->key);

    if(tree->right != NULL)
    {
        print_in_order(tree->right);
    }
}

/*
 * Depth first in_order_traversal()
 *
 *    root
 *       A
 *     /   \
 *    B     E
 *  /  \   /  \
 * C   D  F    G
 *
 * Output: C, B, D, A, F, E, G
 */
void in_order_traversal(tree_t *tree)
{
    if(tree == NULL)
    {
        return;
    }

    in_order_traversal(tree->left); //printf("tree->left: %d \n", tree->key);
    printf("InOrderTraversal in tree->key : %d \n", tree->key);
    in_order_traversal(tree->right); //printf("tree->right: %d \n", tree->key);
}

/*
 * Depth first pre_order_traversal()
 *
 *    root
 *       A
 *     /   \
 *    B     E
 *  /  \   / \
 * C    D F   G
 *
 * Output: A, B, C, D, E, F, G
 */
void pre_order_traversal(tree_t *tree)
{
    if(tree == NULL)
    {
        return;
    }

    printf("PreOrderTraversal in tree->key : %d \n", tree->key);
    pre_order_traversal(tree->left);
    pre_order_traversal(tree->right); //printf("tree->right: %d \n", tree->key);
}

/*
 * Depth first post_order_traversal()
 *
 *      root
 *       A
 *     /    \
 *    B      E
 *  /  \    / \
 * C    D  F   G
 *            / \
 *           H   I
 *
 * Output: C, D, B, D, F, H, I, G, E, A
 */
void post_order_traversal(tree_t *tree)
{
    if(tree == NULL)
    {
        return;
    }

    post_order_traversal(tree->left);
    post_order_traversal(tree->right); //printf("tree->right: %d \n", tree->key);
    printf("PostOrderTraversal in tree->key : %d \n", tree->key);
}

/*
 * Breath-first level_traversal()
 *
 *
 */
void level_traversal(tree_t *tree)
{
    if(tree == NULL)
    {
        return;
    }

    queue_t *q = create_queue();
    enqueue(q, tree);

    //tree_t *node = NULL;
    /*while(!is_empty_queue(q))
    {
        //if(tree->)
    }*/
}

tree_t *remove_tree(tree_t *tree)
{
    if(tree)
    {
        remove_tree(tree->left);
        remove_tree(tree->right);
        free(tree);
        tree = NULL;
    }

    return tree;
}

int main()
{
    tree_t *root = NULL;
    root = create_tree();
    root->key = 555;
    root = insert(root, 20);
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 80);
    root = insert(root, 50);
    root = insert(root, 40);

    print_in_order(root);

    printf("Tree Height: %d \n", height(root));

    printf("------------------------------------------------\n");
    in_order_traversal(root);
    printf("------------------------------------------------\n");
    pre_order_traversal(root);
    printf("------------------------------------------------\n");
    post_order_traversal(root);
    printf("------------------------------------------------\n");
    remove_tree(root);

    return 0;
}
