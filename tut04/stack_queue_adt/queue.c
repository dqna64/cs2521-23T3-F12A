#include "queue.h"
#include "stack.h"

struct queue {
  Stack s1;
  Stack s2;
};

Queue QueueNew(void) {
  Queue q = malloc(sizeof(struct queue));
  q->s1 = StackNew();
  q->s2 = StackNew();
  return q;
}

void QueueEnqueue(Queue q, int item) { StackPush(q->s1, item); }

int QueueDequeue(Queue q) {
  while (StackSize(q->s1) > 0) {
    int item = StackPop(q->s1);
    StackPush(q->s2, item);
  }

  int dequeuedItem = StackPop(q->s2);

  while (StackSize(q->s2) > 0) {
    int item = StackPop(q->s2);
    StackPush(q->s1, item);
  }

  return dequeuedItem;
}

void QueueFree(Queue q) {
  StackFree(q->s1);
  StackFree(q->s2);
  free(q);
}