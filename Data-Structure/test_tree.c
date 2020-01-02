#include "tree.h"

int main() {
    btree_t *root = create_tree();
    root->key = 555;

    for (int i = 0; i < 10; ++i) {
        root = insert(root, rand() % 10);
    }

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
