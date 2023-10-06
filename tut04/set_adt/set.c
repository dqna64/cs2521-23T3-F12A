// #include <stdbool.h>
// #include <stdio.h>
// #include <stdlib.h>

// #include "set.h"

// // Define a structure for a BST node
// typedef struct TreeNode {
//   int data;
//   struct TreeNode *left;
//   struct TreeNode *right;
// } TreeNode;

// // Define a structure for the set
// struct set {
//   TreeNode *root;
//   int size;
// };

// // Creates a new empty set
// Set SetNew(void) {
//   Set newSet;
//   newSet->root = NULL;
//   newSet->size = 0;
//   return newSet;
// }

// // Frees memory allocated to the BST
// void FreeTree(TreeNode *node) {
//   if (node == NULL)
//     return;
//   FreeTree(node->left);
//   FreeTree(node->right);
//   free(node);
// }

// // Frees memory allocated to the set
// void SetFree(Set s) {
//   FreeTree(s->root);
//   s->root = NULL;
//   s->size = 0;
// }

// // Inserts an element into the set
// TreeNode *InsertNode(TreeNode *node, int elem) {
//   if (node == NULL) {
//     TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
//     if (newNode == NULL) {
//       perror("Failed to allocate memory for TreeNode");
//       exit(EXIT_FAILURE);
//     }
//     newNode->data = elem;
//     newNode->left = newNode->right = NULL;
//     return newNode;
//   }

//   if (elem < node->data) {
//     node->left = InsertNode(node->left, elem);
//   } else if (elem > node->data) {
//     node->right = InsertNode(node->right, elem);
//   }

//   return node;
// }

// void SetInsert(Set s, int elem) {
//   if (!SetContains(s, elem)) {
//     s->root = InsertNode(s->root, elem);
//     s->size++;
//   }
// }

// // Deletes an element from the set
// TreeNode *FindMin(TreeNode *node) {
//   while (node->left != NULL) {
//     node = node->left;
//   }
//   return node;
// }

// TreeNode *DeleteNode(TreeNode *node, int elem) {
//   if (node == NULL)
//     return node;

//   if (elem < node->data) {
//     node->left = DeleteNode(node->left, elem);
//   } else if (elem > node->data) {
//     node->right = DeleteNode(node->right, elem);
//   } else {
//     if (node->left == NULL) {
//       TreeNode *temp = node->right;
//       free(node);
//       return temp;
//     } else if (node->right == NULL) {
//       TreeNode *temp = node->left;
//       free(node);
//       return temp;
//     }

//     TreeNode *temp = FindMin(node->right);
//     node->data = temp->data;
//     node->right = DeleteNode(node->right, temp->data);
//   }
//   return node;
// }

// void SetDelete(Set s, int elem) {
//   if (SetContains(s, elem)) {
//     s->root = DeleteNode(s->root, elem);
//     s->size--;
//   }
// }

// // Returns true if the given element is in the set, and false otherwise
// bool Search(TreeNode *node, int elem) {
//   if (node == NULL)
//     return false;
//   if (elem == node->data)
//     return true;
//   if (elem < node->data)
//     return Search(node->left, elem);
//   return Search(node->right, elem);
// }

// bool SetContains(Set s, int elem) { return Search(s->root, elem); }

// // Returns the number of elements in the set
// int SetSize(Set s) { return s->size; }

// int main() {
//   Set mySet = SetNew();

//   SetInsert(mySet, 1);
//   SetInsert(mySet, 2);
//   SetInsert(mySet, 3);

//   printf("Set size: %d\n", SetSize(mySet));

//   SetDelete(mySet, 2);
//   printf("After deleting 2, Set size: %d\n", SetSize(mySet));

//   if (SetContains(mySet, 1)) {
//     printf("Set contains 1\n");
//   } else {
//     printf("Set does not contain 1\n");
//   }

//   SetFree(mySet);

//   return 0;
// }

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "set.h"

// Define a structure for a BST node
typedef struct TreeNode {
  int data;
  struct TreeNode *left;
  struct TreeNode *right;
} TreeNode;

// Define a structure for the set
struct set {
  TreeNode *root;
  int size;
}; // Define Set as a pointer to the set structure

static TreeNode *FindMin(TreeNode *node);

// Creates a new empty set
Set SetNew(void) {
  Set newSet = (Set)malloc(sizeof(struct set));
  if (newSet == NULL) {
    perror("Failed to allocate memory for Set");
    exit(EXIT_FAILURE);
  }
  newSet->root = NULL;
  newSet->size = 0;
  return newSet;
}

// Frees memory allocated to the BST
void FreeTree(TreeNode *node) {
  if (node == NULL)
    return;
  FreeTree(node->left);
  FreeTree(node->right);
  free(node);
}

// Frees memory allocated to the set
void SetFree(Set s) {
  FreeTree(s->root);
  free(s);
}

// Inserts an element into the set
TreeNode *InsertNode(TreeNode *node, int elem) {
  if (node == NULL) {
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    if (newNode == NULL) {
      perror("Failed to allocate memory for TreeNode");
      exit(EXIT_FAILURE);
    }
    newNode->data = elem;
    newNode->left = newNode->right = NULL;
    return newNode;
  }

  if (elem < node->data) {
    node->left = InsertNode(node->left, elem);
  } else if (elem > node->data) {
    node->right = InsertNode(node->right, elem);
  }

  return node;
}

void SetInsert(Set s, int elem) {
  if (!SetContains(s, elem)) {
    s->root = InsertNode(s->root, elem);
    s->size++;
  }
}

// Deletes an element from the set
TreeNode *DeleteNode(TreeNode *node, int elem) {
  if (node == NULL)
    return node;

  if (elem < node->data) {
    node->left = DeleteNode(node->left, elem);
  } else if (elem > node->data) {
    node->right = DeleteNode(node->right, elem);
  } else {
    if (node->left == NULL) {
      TreeNode *temp = node->right;
      free(node);
      return temp;
    } else if (node->right == NULL) {
      TreeNode *temp = node->left;
      free(node);
      return temp;
    }

    TreeNode *temp = FindMin(node->right);
    node->data = temp->data;
    node->right = DeleteNode(node->right, temp->data);
  }
  return node;
}

// Find the minimum value node in a BST
static TreeNode *FindMin(TreeNode *node) {
  while (node->left != NULL) {
    node = node->left;
  }
  return node;
}

void SetDelete(Set s, int elem) {
  if (SetContains(s, elem)) {
    s->root = DeleteNode(s->root, elem);
    s->size--;
  }
}

// Returns true if the given element is in the set, and false otherwise
bool Search(TreeNode *node, int elem) {
  if (node == NULL)
    return false;
  if (elem == node->data)
    return true;
  if (elem < node->data)
    return Search(node->left, elem);
  return Search(node->right, elem);
}

bool SetContains(Set s, int elem) { return Search(s->root, elem); }

// Returns the number of elements in the set
int SetSize(Set s) { return s->size; }

void InOrderTraversal(TreeNode *node) {
  if (node != NULL) {
    InOrderTraversal(node->left);
    printf("%d ", node->data);
    InOrderTraversal(node->right);
  }
}

void PrintSet(Set s) {
  if (s->root != NULL) {
    printf("Set elements: ");
    InOrderTraversal(s->root);
    printf("\n");
  } else {
    printf("Set is empty.\n");
  }
}
