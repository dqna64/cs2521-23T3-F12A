
#include <stdbool.h>
#include <stdio.h>

/**
 * Binary Search Tree Node
 */
typedef struct node {
  int value;
  struct node *left;
  struct node *right;
} *TreeNode;

////////////////////////////////////////////////////////////////////////

// Creates a new empty BST
struct node *bstNew(void);

// Frees all the memory associated with the given BST
void bstFree(struct node *t);

// Inserts a new value into the given BST and returns the root of the
// updated BST. Does not insert duplicate values.
struct node *bstInsert(struct node *t, int val);

// Checks whether a value is in the given BST.
bool bstFind(struct node *t, int val);

// Prints a BST to the given file.
// Assumes that the file is open for writing.
void bstPrint(struct node *t, FILE *out);

// Prints a BST to stdout.
void bstShow(struct node *t);
