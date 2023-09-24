/**
 * Run:
 * $ clang 2_list_count_odds.c linked_list.c -o 2_list_count_odds
 * $ ./2_list_count_odds
 */

#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

int listCountOddsContainer(struct list *l);
int listCountOdds(struct node *l);

int main() {
  struct node *list = listIntro();

  int listNumOdds = listCountOdds(list);
  printf("Number of odd nums in linked list: %d\n", listNumOdds);

  return 0;
}

/**
 * Takes in a container struct to a linked list and returns the number of odd
 * numbers in the contained linked list.
 */
int listCountOddsContainer(struct list *l) { return listCountOdds(l->head); }

/**
 * Recursive function to cound the number of odd elements in a linked list.
 */
int listCountOdds(struct node *l) {
  if (l == NULL) {
    return 0;
  }

  if (l->value % 2 == 1) {
    // odd
    return 1 + listCountOdds(l->next);
  } else {
    // even
    return listCountOdds(l->next);
  }
}