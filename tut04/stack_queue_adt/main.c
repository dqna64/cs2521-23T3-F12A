/**
 * Run:
 * $ clang main.c stack.c queue.c && ./a.out
 */

#include "queue.h"
#include <stdio.h>

int main() {
  Queue q = QueueNew();
  QueueEnqueue(q, 1);
  QueueEnqueue(q, 2);
  QueueEnqueue(q, 3);
  QueueEnqueue(q, 4);

  printf("%d ", QueueDequeue(q)); // 1
  printf("%d ", QueueDequeue(q)); // 2
  printf("%d ", QueueDequeue(q)); // 3

  QueueEnqueue(q, 5);
  QueueEnqueue(q, 6);

  printf("%d ", QueueDequeue(q)); // 4
  printf("%d ", QueueDequeue(q)); // 5
  printf("%d ", QueueDequeue(q)); // 6

  printf("\n");

  //   QueueFree(q);
}