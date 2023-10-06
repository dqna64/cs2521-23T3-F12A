#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

#define MAX_STACK_SIZE 100

// Define a structure for the stack
struct stack {
  int data[MAX_STACK_SIZE];
  int top;
};

// Define a typedef for Stack
typedef struct stack *Stack;

// Creates a new empty stack
Stack StackNew(void) {
  Stack s = (Stack)malloc(sizeof(struct stack));
  if (s == NULL) {
    perror("Failed to allocate memory for Stack");
    exit(EXIT_FAILURE);
  }
  s->top = -1;
  return s;
}

// Frees memory allocated to the stack
void StackFree(Stack s) {
  free(s->data);
  free(s);
}

// Pushes an element onto the stack
void StackPush(Stack s, int elem) {
  if (s->top < MAX_STACK_SIZE - 1) {
    s->data[++(s->top)] = elem;
  } else {
    printf("Stack overflow: Cannot push element onto a full stack.\n");
  }
}

// Pops an element from the stack and returns it
int StackPop(Stack s) {
  if (!StackIsEmpty(s)) {
    return s->data[(s->top)--];
  } else {
    printf("Stack underflow: Cannot pop element from an empty stack.\n");
    exit(EXIT_FAILURE);
  }
}

// Returns the element at the top of the stack without removing it
int StackTop(Stack s) {
  if (!StackIsEmpty(s)) {
    return s->data[s->top];
  } else {
    printf("Stack is empty. Cannot retrieve the top element.\n");
    exit(EXIT_FAILURE);
  }
}

// Returns true if the stack is empty, and false otherwise
bool StackIsEmpty(Stack s) { return (s->top == -1); }

// Returns the number of elements in the stack
int StackSize(Stack s) { return (s->top + 1); }
