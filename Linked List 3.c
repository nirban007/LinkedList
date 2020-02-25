#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node *next;
};

void print_list(struct node *head)
{
    printf("H->");

    while(head)
    {
        printf("%d->", head->val);
        head = head->next;
    }

    printf("|||\n\n");
}

void insert_front(struct node **head, int value)
{
    struct node * new_node = NULL;

    new_node = (struct node *)malloc(sizeof(struct node));

    if (new_node == NULL)
    {
        printf("Failed to insert element. Out of memory");
    }

    new_node->val = value;
    new_node->next = *head;

    *head = new_node;
}

void insert_end(struct node **head, int value)
{
    struct node * new_node = NULL;
    struct node * last = NULL;

    new_node = (struct node *)malloc(sizeof(struct node));

    if (new_node == NULL)
    {
        printf("Failed to insert element. Out of memory");
    }

    new_node->val = value;
    new_node->next = NULL;

    if( *head == NULL)
    {
        *head = new_node;
        return;
    }

    last = *head;
    while(last->next) last = last->next;

    last->next = new_node;
}

void delete_node(struct node **head, int val)
{
 struct node *tmp = NULL;
 struct node *tmp1 = NULL;

 if (head == NULL || *head == NULL) return;

 if((*head)->val == val)
 {
  /*Delete the head node*/
  tmp = *head;
  *head = (*head)->next;
  free(tmp);
  return;
 }

 tmp = *head;

 while(tmp->next && tmp->next->val != val) tmp = tmp->next;

 if(tmp->next)
 {
  tmp1 = tmp->next;
  tmp->next = tmp1->next;

  free(tmp1);
 }
 else
 {
  printf("%d not found in the list.\n", val);
 }
}
void deleteNode(struct node **head, int key)
{

    struct node* temp = *head, *prev;


    if (temp != NULL && temp->val == key)
    {
        *head = temp->next;
        free(temp);
        return;
    }



    while (temp != NULL && temp->val != key)
    {
        prev = temp;
        temp = temp->next;
    }


    if (temp == NULL) return;


    prev->next = temp->next;

    free(temp);
}



void main()
{
    int count = 0, i, val, after, before,key;
    struct node * head = NULL;

    printf("Enter number of elements: ");
    scanf("%d", &count);

    for (i = 0; i < count; i++)
    {
        printf("Enter %dth element: ", i);
        scanf("%d", &val);
        insert_front(&head, val);
    }

    printf("Initial List: ");
    print_list(head);

    printf("Enter a value to enter at the front of the list: ");
    scanf("%d", &val);
    insert_front(&head, val);

    printf("List after insertion: ");
    print_list(head);

    printf("Enter a value to enter at the end of the list: ");
    scanf("%d", &val);
    insert_end(&head, val);

    printf("List after insertion: ");
    print_list(head);

    printf("Enter a value to insert in the list: ");
    scanf("%d", &val);

    //printf("Insert after: ");
    //scanf("%d", &after);

    //insert_after(head, val, after);

    printf("List after insertion: ");
    print_list(head);

    //printf("Enter a value to insert in the list: ");
    //scanf("%d", &val);

    //printf("Insert before: ");
    //scanf("%d", &before);

    //insert_before(&head, val, before);

    //printf("List after insertion: ");
    //print_list(head);
    //printf("Enter a value to delete from the list: ");
    //canf("%d", &val);
    delete_node(&head, val);
    print_list(head);
    printf("Enter a value for delete : ");
    deleteNode(&head,scanf("%d",&key));
    print_list(head);

}
