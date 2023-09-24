/**
 * Run:
 * $ clang 3_list_is_sorted.c linked_list.c -o 3_list_is_sorted
 * $ ./3_list_is_sorted
 */

#include "linked_list.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool listIsSortedContainer(struct list *l);
bool listIsSorted(struct node *l);

int main() {
  struct node *list = listIntro();

  bool res = listIsSorted(list);
  printf("Linked list sorted order:  %s\n", res ? "true" : "false");

  return 0;
}

/**
 * Takes in a container struct to a linked list and returns whether the
 * contained linked list is in sorted ascending order.
 */
bool listIsSortedContainer(struct list *l) { return listIsSorted(l->head); }

/**
 * Recursive function to determine whether the linked list is in sorted
 * ascending order.
 */
bool listIsSorted(struct node *l) {
  if (l == NULL) {
    return true;
  }

  if (l->next == NULL) {
    return true;
  }

  if (l->value <= l->next->value) {
    return listIsSorted(l->next);
  } else {
    return false;
  }
}