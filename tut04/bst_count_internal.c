#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Run command:
 *    $ clang bst_count_internal.c bst.c && ./a.out
 *
 */

int bstCountInternal(struct node *t) {
  if (t == NULL) {
    return 0;
  } else if (t->left == NULL && t->right == NULL) {
    return 0;
  } else {
    return 1 + bstCountInternal(t->left) + bstCountInternal(t->right);
  }
}

int main(void) {

  struct node *tree = NULL;
  tree = bstInsert(tree, 7);
  tree = bstInsert(tree, 2);
  tree = bstInsert(tree, 9);
  tree = bstInsert(tree, 1);
  tree = bstInsert(tree, 5);
  tree = bstInsert(tree, 8);
  tree = bstInsert(tree, 10);
  tree = bstInsert(tree, 4);
  bstShow(tree);

  int result = bstCountInternal(tree);
  printf("number of internal nodes: %d\n", result); // should be 4
}