/**
 * Run:
 * $ clang main.c set.c && ./a.out
 */

#include "set.h"
#include <stdio.h>

int numOddOccurrences(int arr[], int size) {
  Set s = SetNew();

  for (int i = 0; i < size; i++) {
    if (SetContains(s, arr[i])) {
      SetDelete(s, arr[i]);
    } else {
      SetInsert(s, arr[i]);
    }
  }

  int count = SetSize(s);
  SetFree(s);
  return count;
}

int numSingleOccurrences(int arr[], int size) {
  Set once = SetNew();
  Set moreThanOnce = SetNew();

  for (int i = 0; i < size; i++) {
    if (SetContains(once, arr[i])) {
      SetDelete(once, arr[i]);
      SetInsert(moreThanOnce, arr[i]);
    } else if (!SetContains(moreThanOnce, arr[i])) {
      SetInsert(once, arr[i]);
    }
  }

  int count = SetSize(once);
  SetFree(once);
  SetFree(moreThanOnce);
  return count;
}

int main(void) {
  int arr1[] = {4, 3, 4, 8, 8, 4};
  printf("arr1: ");
  for (int i = 0; i < 6; i++) {
    printf("%d ", arr1[i]);
  }
  printf("\n");
  printf("Number of elements that occur an odd number of times: %d\n",
         numOddOccurrences(arr1, 6));

  int arr2[] = {4, 3, 4, 8, 7, 4};
  printf("arr2: ");
  for (int i = 0; i < 6; i++) {
    printf("%d ", arr2[i]);
  }
  printf("\n");
  printf("Number of elements that occur exactly once: %d\n",
         numSingleOccurrences(arr2, 6));
}