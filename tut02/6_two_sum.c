/**
 * Run:
 * $ clang 6_two_sum.c -o 6_two_sum
 * $ ./6_two_sum
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Test cases
 * Nums: 2 3 4
 * Target: 6
 * Output: true
 *
 * Nums: 2 3 5
 * Target: 6
 * Output: false
 *
 * Nums: 1 2 5
 * Target: 5
 * Output: false
 *
 * Nums: 2 2 5
 * Target: 4
 * Output: true
 */

bool hasTwoSum(int nums[], int n, int target);

int main(int argc, char *argv[]) {
  /**
   * Ask the user for a list of numbers and dynamically allocate an array to
   * store them.
   */
  printf("How many numbers: ");
  int size = 0;
  scanf("%d", &size);

  printf("Enter a list of numbers: ");
  int *nums = malloc(sizeof(int) * size);
  for (int i = 0; i < size; i++) {
    scanf("%d", &nums[i]);
  }

  int target;
  printf("Enter a target sum: ");
  scanf("%d", &target);

  if (hasTwoSum(nums, size, target)) {
    printf("true\n");
  } else {
    printf("false\n");
  }

  return 0;
}

bool hasTwoSum(int nums[], int n, int target) {
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (nums[i] + nums[j] == target) {
        return true;
      }
    }
  }
  return false;
}