#include "bst.h"

/**
 * Run command:
 *    $ clang bst_traversal_orders.c bst.c && ./a.out
 *
 */

static void visitBstNode(struct node *t);

// Prints the in-order traversal of the given BST
void bstInOrder(struct node *t) {
  if (t == NULL)
    return;

  bstInOrder(t->left);
  visitBstNode(t);
  bstInOrder(t->right);
}

// Prints the pre-order traversal of the given BST
void bstPreOrder(struct node *t) {
  if (t == NULL)
    return;

  visitBstNode(t);
  bstPreOrder(t->left);
  bstPreOrder(t->right);
}

// Prints the post-order traversal of the given BST
void bstPostOrder(struct node *t) {
  if (t == NULL)
    return;

  bstPostOrder(t->left);
  bstPostOrder(t->right);
  visitBstNode(t);
}

// Prints the level-order traversal of the given BST
void bstLevelOrder(struct node *t) {
  // TODO: Task 5 - Implement this function
}

// Prints the value in the given node
static void visitBstNode(struct node *t) {
  if (t == NULL)
    return;
  printf("%d ", t->value);
}

int main() {
  TreeNode tree = NULL;
  tree = bstInsert(tree, 5);
  tree = bstInsert(tree, 3);
  tree = bstInsert(tree, 7);
  tree = bstInsert(tree, 2);
  tree = bstInsert(tree, 4);
  bstShow(tree);

  printf("In-order traversal:    ");
  bstInOrder(tree);
  printf("\n");

  printf("Pre-order traversal:   ");
  bstPreOrder(tree);
  printf("\n");

  printf("Post-order traversal:  ");
  bstPostOrder(tree);
  printf("\n");

  printf("Level-order traversal: ");
  bstLevelOrder(tree);
  printf("\n");
}