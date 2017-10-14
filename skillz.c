//Kristin Lin
//Systems pd10
//Work 06: Enlist your C skillz
//2017-10-14

#include <stdio.h>
#include <stdlib.h>

//struct node with int baggage and pointer to next;
struct node {
  int baggage;
  struct node *next;
};

//while your current is not NULL, print baggage, move on to next
void print_list(struct node * one)
{
  printf("START\n");
  while (one) {
    printf("%d\n", (*one).baggage);
    one = (*one).next;
  }
  printf("END\n");
}

//create a new node pointer, initialize its contents, realign pointers
struct node * insert_front (struct node * one, int item)
{
  struct node * update;
  //assign number of bytes as a standard struct node
  update = (struct node *) malloc(sizeof(*one)); 
  (*update).baggage = item;
  (*update).next = one;
  return update;
}

//use a temp struct node pointer to store next node before freeing current node
struct node * free_list(struct node * one)
{
  struct node * two;
  while (one) {
    two = (*one).next;
    free(one);
    one = two;
  }
  return one;
}

//----------TESTING---------------------
int main ()
{
  struct node * dogs;

  printf("\nInitializing dogs:\n");
  dogs = NULL;
  print_list(dogs);
  
  printf("\nAdded 5 to dogs:\n");
  dogs = insert_front(dogs, 5);
  print_list(dogs);

  printf("\nAdded 9 to dogs:\n");
  dogs = insert_front(dogs, 9);
  print_list(dogs);

  printf("\nAdded 24 to dogs:\n");
  dogs = insert_front(dogs, 24);
  print_list(dogs);

  printf("\nWho let the dogs out?\n");
  dogs = free_list(dogs);
  print_list(dogs);

}
