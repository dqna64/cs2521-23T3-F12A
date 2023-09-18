/**
 * Run:
 *  clang 2-heap-struct.c && ./a.out
 */

#include <stdlib.h>

struct node {
  int value;
  struct node *next;
};

void stack_struct() {
  struct node n;
  n.value = 42;
  n.next = NULL;

  // do smthn with the node
}

void heap_struct() {
  struct node *n = malloc(sizeof(struct node));
  n->value = 42;
  n->next = NULL;

  // do smthn with the node

  free(n);
}

int main(void) {

  stack_struct();
  heap_struct();

  return 0;
}