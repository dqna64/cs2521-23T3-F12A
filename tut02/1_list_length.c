/**
 * Run:
 * $ clang 1_list_length.c linked_list.c -o 1_list_length
 * $ ./1_list_length
 */

#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

int listLengthContainer(struct list *l);
int listLength(struct node *l);

int main() {
  struct node *list = listIntro();

  int listLengthRes = listLength(list);
  printf("Length of linked list: %d\n", listLengthRes);

  return 0;
}

/**
 * Takes in a container struct to a linked list and returns the length of the
 * contained linked list.
 */
int listLengthContainer(struct list *l) { return listLength(l->head); }

/**
 * Recursive function to find the length of a linked list.
 */
int listLength(struct node *l) {
  // base case
  if (l == NULL) {
    return 0;
  }

  return 1 + listLength(l->next);
}
