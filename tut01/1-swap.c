/**
 * Run:
 *  clang 1-swap.c && ./a.out
 */

#include <stdio.h>

void swapIncorrectly(int a, int b) {
  int tmp = a;
  a = b;
  b = tmp;
}

void swapCorrectly(int *a_ptr, int *b_ptr) {
  int tmp = *a_ptr; // tmp = 5
  *a_ptr = *b_ptr;  // *a_ptr = 7
  *b_ptr = tmp;     // *b_ptr = 5
}

int main(void) {
  int a = 5;
  int b = 7;

  printf("=== Incorrect ===\n");
  printf("Before swap: a = %d, b = %d\n", a, b); // a=5, b=7
  swapIncorrectly(a, b);
  printf("After swap: a = %d, b = %d\n", a, b); // a=5, b=7

  printf("=== Correct ===\n");
  printf("Before swap: a = %d, b = %d\n", a, b); // a=5, b=7
  swapCorrectly(&a, &b);
  printf("After swap: a = %d, b = %d\n", a, b); // a=7, b=5
}
