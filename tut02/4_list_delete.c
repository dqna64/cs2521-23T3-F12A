/**
 * Run:
 * $ clang 4_list_delete.c linked_list.c -o 4_list_delete
 * $ ./4_list_delete
 */

#include "linked_list.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct node *listDelete(struct node *l, int value);

int main() {
  struct node *list = listIntro();
  printf("Value to delete: ");
  int value;
  scanf("%d", &value);

  list = listDelete(list, value);
  printf("List after delete: ");
  printList(list);

  return 0;
}

/**
 * Recursive function to delete the first occurence of a value in a linked list.
 */
struct node *listDelete(struct node *l, int value) {
  if (l == NULL) {
    return NULL;
  }

  // l == (2) -> (3) -> (4) -> X
  // l->next == (3)
  if (l->value == value) {
    // yes we found the node that we must delete
    struct node *newHead = l->next;
    free(l);
    return newHead;
  } else {
    l->next = listDelete(l->next, value); // listDelete((3), value); -> (4)
                                          // l == (2) -> (4) -> X
    return l;
  }
}