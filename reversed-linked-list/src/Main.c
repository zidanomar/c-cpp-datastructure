#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node* Reverse(struct Node* head) {
  struct Node *current, *prev, *next;
  current = head;
  prev = NULL;

  
  while (current != NULL)
  {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }

  head = prev;

  return head;
}

struct Node* RecursionReverse(struct Node* head) {
  if(head == NULL) {
    return head;
  }

  struct Node* q = head -> next;
  q -> next = head;
  head -> next = NULL;

}

struct Node* Insert(struct Node* head, int data){
   struct Node *temp = (struct Node*)malloc(sizeof(struct Node));


   temp -> data = data;
   temp -> next = NULL;


  if(head == NULL) head = temp;
  else {
    struct Node* temp1 = head;
    while (temp1->next != NULL) temp1 = temp1->next;
    temp1->next = temp;
  }

  return head;
}

void Print(struct Node* p) {
  if (p == NULL) {
   printf("\n");
    return;
  }

  printf(" %d", p->data);
  Print(p->next);
}

int main(int argc, char const *argv[])
{
  struct Node* head = NULL;

  head = Insert(head,1); 
  head = Insert(head,2); 
  head = Insert(head,3); 
  head = Insert(head,4); 

  Print(head);

  head = Reverse(head);

  Print(head);

  head = RecursionReverse(head);
  Print(head);
  
  return 0;
}
