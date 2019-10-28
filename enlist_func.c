#include <stdio.h>
#include <stdlib.h>
#include "enlist_header.h"

void print_list(struct node *p) {
  printf("Printing list: ");
  printf("[ ");
  while (p != NULL) {
    printf("%d ",p->i);
    p=p->next;
  }
  printf("]\n");
}

struct node * insert_front(struct node *p, int value) {
  struct node *newNode;
  newNode = malloc(sizeof(struct node));
  newNode->i = value;
  newNode->next = p;
  p = newNode;
  printf("Adding %d to the list --> ", value);
  return p;
}

struct node * free_list(struct node *p) {
  struct node *temp;
  while (p != NULL ) {
    temp = p;
    p = p->next;
    int value = temp->i;
    free(temp);
    printf("Freeing node: %d --> ", value);
    print_list(p);
  }
  return p;
}

struct node * remove_node(struct node *front, int data) {
  printf("Removing %d --> ", data);
  
  if (front == NULL) {
    printf("List is empty.\n");
    return front;
  }

  struct node *head;
  struct node *previous;
  head = front;


  //first case: node to be removed is the first node front points to
  if (head->i == data) {
    head = front->next;
    free(front);
    return head;
  }

  //second case and third case: node to be removed is in the middle of the list or
  //or at the end of the list
  previous = front;
  front = front->next;
  while (front != NULL) {
    if (front->i == data){
      previous->next = front->next;
      free(front);
      return head;
    }
    previous = front;
    front = front->next;
  }

  printf("Data is not in the list.\n");
  return head;
}
