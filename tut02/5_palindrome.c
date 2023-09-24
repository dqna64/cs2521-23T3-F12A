/**
 * Run:
 * $ clang 5_palindrome.c -o 5_palindrome
 * $ ./5_palindrome racecar
 */

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

static bool isPalindrome(char *s);

int main(int argc, char *argv[]) {
  if (argc == 2) {
    if (isPalindrome(argv[1])) {
      printf("is a palindrome\n");
    } else {
      printf("not a palindrome\n");
    }
  } else {
    printf("Usage: %s <string>\n", argv[0]);
  }
  return 0;
}

static bool isPalindrome(char *s) {
  int l = 0;
  int r = strlen(s) - 1;

  while (l <= r) {
    if (s[l] == s[r]) {
      l++;
      r--;
    } else {
      return false;
    }
  }

  return true;
}