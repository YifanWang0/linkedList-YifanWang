#include <stdio.h>
#include <stdlib.h>
#include "enlist_header.h"

int main() {

  //testing print_list with empty list
  struct node *p = NULL;
  printf("Printing empty list.\n");
  printf("Expected: [ ]\n");
  print_list(p);
  printf("---------\n");

  //testing insert_front
  printf("Adding #s 0-9 to list.\n");
  printf("Expected: [ 9 8 7 6 5 4 3 2 1 0 ] \n");

  struct node *node0;
  node0 = NULL;

  for (int i = 0; i < 10; i++) {
    struct node *node;
    node = insert_front(node0, i);
    node0 = node;
    print_list(node0);
  }

  printf("---------\n");

  //testing free_list
  printf("Freeing list.\n");
  printf("Expected: [ ]\n");
  free_list(node0);
  printf("---------\n");

  //testing remove_node
  struct node *tail;
  tail = malloc(sizeof(struct node));
  tail->i = 0;
  tail->next = NULL;

  struct node *first;
  first = malloc(sizeof(struct node));
  first->i = 1;
  first->next = tail;

  struct node *second;
  second = malloc(sizeof(struct node));
  second->i = 2;
  second->next = first;

  struct node *third;
  third = malloc(sizeof(struct node));
  third->i = 3;
  third->next = second;

  struct node *head;
  head = malloc(sizeof(struct node));
  head->i = 4;
  head->next = third;

  printf("Removing nodes.\n");
  printf("Current list --> ");
  print_list(head);

  print_list(remove_node(head, 4));
  print_list(remove_node(third, 1));
  print_list(remove_node(third, 0));
  print_list(remove_node(third, 4));

  printf("\n");
  printf("Current list --> ");
  print_list(p);
  print_list(remove_node(p, 7));
  printf("---------\n");

}
