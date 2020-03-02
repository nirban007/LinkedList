
#include<stdio.h>
#include<stdlib.h>

typedef struct Node node;
struct Node
{
    int value;
    node *next;

};
node *head = NULL;
int main()
{
    node *p = (node*)malloc(sizeof(node));
    node *q = (node*)malloc(sizeof(node));
    node *r = (node*)malloc(sizeof(node));
    head = p;

    p->value = 2;
    p->next = q;

    q->value = 3;
    q->next = r;

    r->value = 7;
    r->next = NULL;
    printf("Count of nodes is %d", getCount(head));
    printf("\n");
    printf("Before delete: ");
    print(head);
    delete_first_value(head);

    printf("\n");
    printf("After delete first element: ");
    print(head);
    printf("\n");
    printf("After delete last value: ");

    delete_last_value(head);
    print(head);
    printf("\n");
    //deleteNode(&head, 1);
    isEmpty(head);
    printf("\n");
    print_first(p->value);
    printf("\n");
    print_last(r->value);
    
    return 0;
}
node*temp;
void delete_first_value(node*x)
{
    temp=head;
    head=head->next;
    free(temp);
}
void print(node *x)
{
    if(x==NULL)
    {
        printf("Linked list is empty");
    }
    while(x!=NULL)
    {
        printf("%d ", x->value);
        x=x->next;
    }
}
void delete_last_value(node*x)
{
node*temp=head;
 if(head==NULL)
 {
     printf("Underflow");
     return;
 }
 while(temp->next->next)
 {
     temp=temp->next;
 }
 free(temp->next);
 temp->next=NULL;

}
int getCount(struct node* head)
{
    int count = 0;
    struct Node* current = head;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}
int isEmpty( node * head )
 {
   if( !head )
      {
          printf("Linked List is Not Empty");
      }
      else
      {
          printf("Linked list is empty");
      }

 }
 void print_first(node *x)
 {
     printf("The first value is : %d", x->value);
 }
 void print_last(node*x)
 {
     printf("The last value is : %d", x->value);
 }
 
