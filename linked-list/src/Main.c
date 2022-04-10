#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node *head;

void Insert(int data, int pos){
   struct Node *newNode = malloc(sizeof(*newNode));

   newNode -> data = data;
   newNode -> next = NULL;

   if(pos == 1) {
     newNode -> next = head;
     head = newNode;
     return;
   }

   struct Node *prevNode = malloc(sizeof(*prevNode));
   prevNode = head;

   for (int i = 0; i < pos - 2; i++)
   {
     prevNode = prevNode -> next;
   }
   newNode -> next = prevNode -> next;
   prevNode -> next = newNode;
  
}

void Delete(int pos) {
  struct Node *temp = malloc(sizeof(*temp));
  temp = head;

  if(pos == 1) {
    head = temp -> next;
    free(temp);
    return;
  }

  for(int i = 0; i < pos -2; i++) {
    temp = temp -> next;
  }

  struct Node *temp2 = malloc(sizeof(*temp2));
  temp2 = temp -> next;
  temp -> next = temp2 -> next;
  free(temp2);
}

void Print() {

  printf("List : ");
  while (head != NULL)
  {
    printf(" %d", head -> data);
    head = head -> next;
  }
  printf("\n");
}

int main(int argc, char const *argv[])
{
  int n, x;
  head = NULL;

  Insert(2,1); // List : 2
  Insert(3,2); // List : 2 3
  Insert(4,3); // List : 2 3 4
  Insert(5,3); // List : 2 3 5 4

  Delete(3);
  Delete(1);

  Print();
  
  return 0;
}
