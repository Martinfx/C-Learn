#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b) { return (a) < (b) ? (a) : (b); }

int max(int a, int b) { return (a) > (b) ? (a) : (b); }

typedef struct btree {
  int key, height;
  struct btree *left;
  struct btree *right;
} btree_t;

btree_t *create_node() {
  btree_t *node = (btree_t *)malloc(sizeof(btree_t));
  if (!node) {
    printf("Allocation memory failed list_t!\n");
    return NULL;
  }

  node->left = NULL;
  node->right = NULL;

  return node;
}

btree_t *create_tree() {
  btree_t *node = (btree_t *)malloc(sizeof(btree_t));
  if (!node) {
    printf("Allocation memory failed!");
    return NULL;
  }

  node->key = 0;
  node->left = NULL;
  node->right = NULL;

  return node;
}

btree_t *insert(btree_t *tree, int key) {
  // printf("Insert key: %d \n", key);

  // Empty tree , create new node
  if (tree == NULL) {
    tree = create_node();
    tree->key = key;
    tree->left = NULL;
    tree->right = NULL;
  } else if (key < tree->key) {
    // Insert in left
    tree->left = insert(tree->left, key);
  } else if (key > tree->key) {
    // Insert in right
    tree->right = insert(tree->right, key);
  }
  return tree;
}

btree_t *search(btree_t *tree, int key) {
  while (tree != NULL && tree->key != key) {
    if (key < tree->key) {
      tree = tree->left;

      if (tree->key == key) {
        printf("Found key: %d\n", key);
      }
    } else {
      tree = tree->right;

      if (tree->key == key) {
        printf("Found key: %d\n", key);
      }
    }
  }

  return tree;
}

int height(btree_t *tree) {
  if (tree != NULL) {
    tree->height = 1 + max(height(tree->left), height(tree->right));
    return tree->height;
  }
  return 0;
}

void print_in_order(btree_t *tree) {
  if (tree->left != NULL) {
    print_in_order(tree->left);
  }

  printf("printInOrder: %d \n", tree->key);

  if (tree->right != NULL) {
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
void in_order_traversal(btree_t *tree) {
  if (tree != NULL) {
    in_order_traversal(tree->left); // printf("tree->left: %d \n", tree->key);
    printf("InOrderTraversal in tree->key : %d \n", tree->key);
    in_order_traversal(tree->right); // printf("tree->right: %d \n", tree->key);
  }
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
void pre_order_traversal(btree_t *tree) {
  if (tree != NULL) {
    printf("PreOrderTraversal in tree->key : %d \n", tree->key);
    pre_order_traversal(tree->left);
    pre_order_traversal(
        tree->right); // printf("tree->right: %d \n", tree->key);
  }
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
void post_order_traversal(btree_t *tree) {
  if (tree != NULL) {
    post_order_traversal(tree->left);
    post_order_traversal(
        tree->right); // printf("tree->right: %d \n", tree->key);
    printf("PostOrderTraversal in tree->key : %d \n", tree->key);
  }
}

void level_order_traversal(btree_t *tree) {
  //if(tree != NULL) {

  //}
}

btree_t *remove_tree(btree_t *tree) {
  if (tree) {
    remove_tree(tree->left);
    remove_tree(tree->right);
    free(tree);
    tree = NULL;
  }

  return tree;
}
