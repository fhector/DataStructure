/* Deque using Linked list - Program to implement ADT deque using linked list */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>	/* Not required */
#define NULL 0		/* Not required */

/* Assume that the data portion of each node consists of an integer. */

struct node
{
  int data;
  struct node *next,*prev;
};

struct deque
{
 struct node *left,
	     *right;
};

/* This function initializes the deque to be empty by making 
   both front and rear as NULL */

void createdeque(struct deque *pdq)
{
  pdq->left=pdq->right=NULL;
}

void insertleft(struct deque *pdq,int x)
{
  struct node *pnode;

  pnode=(struct node*)malloc(sizeof(struct node));

  if(pnode==NULL)
  {
    printf("\nMemory overflow. Unable to create.");
    exit(1);
  }
  pnode->data=x;

  if(pdq->left==NULL)
  {
      pnode->prev=pnode->next=NULL;
      pdq->left=pdq->right=pnode;
  }
  else
  {
      pnode->prev=NULL;
      pnode->next=pdq->left;
      pdq->left->prev=pnode;
      pdq->left=pnode;
  }
}

void insertright(struct deque *pdq,int x)
{
  struct node *pnode;

  pnode=(struct node*)malloc(sizeof(struct node));

  if(pnode==NULL)
  {
    printf("\nMemory overflow. Unable to create.");
    exit(1);
  }
  pnode->data=x;

  if(pdq->right==NULL)
  {
      pnode->prev=pnode->next=NULL;
      pdq->left=pdq->right=pnode;
  }
  else
  {
      pnode->next=NULL;
      pnode->prev=pdq->right;
      pdq->right->next=pnode;
      pdq->right=pnode;
  }
}

int removeleft(struct deque *pdq)
{
  int x;
  struct node *p;

  if(pdq->left==NULL)
  {
    printf("Deque underflow. Cannot remove");
    getch();
    exit(1);
  }

  x=pdq->left->data;
  p=pdq->left;
  pdq->left=pdq->left->next;
  if(pdq->left==NULL)
      pdq->right=NULL;
  else
      pdq->left->prev=NULL;
  free(p);
  return x;
}

int removeright(struct deque *pdq)
{
  int x;
  struct node *p;

  if(pdq->right==NULL)
  {
    printf("Deque underflow. Cannot remove");
    getch();
    exit(1);
  }
  x=pdq->right->data;
  p=pdq->right;
  pdq->right=pdq->right->prev;
  if(pdq->right==NULL)
      pdq->left=NULL;
  else
      pdq->right->next=NULL;
  free(p);
  return x;
}


void show(struct deque dq)
{
  struct node *p;

  if(dq.left==NULL)
    printf("Deque empty. No data to display. \n");
  else
  {
    printf("Deque from left to right is as shown: \n");
    p=dq.left;
    while(p!=NULL)
    {
      printf("%d ",p->data);
      p=p->next;
    }
    printf("\n");
  }
}

void destroydeque(struct deque *pdq)
{
 pdq->left=pdq->right=NULL;
}

void main()
{
 int x,ch;

 struct deque dq;
 createdeque(&dq);

 clrscr();
 do
 {
  printf("\n\n  Menu: \n");
  printf("1:Insert Left.\n");
  printf("2:Remove Left.\n");
  printf("3:Insert Right.\n");
  printf("4:Remove Right.\n");
  printf("5:exit \n");
  printf("Enter your choice: ");
  scanf("%d",&ch);
  switch(ch)
  {
    case 1:
    printf("Enter element to be inserted at left: ");
    scanf("%d",&x);
    insertleft(&dq,x);
    show(dq);
    break;

    case 2:
    x=removeleft(&dq);
    printf("Element removed from left is: %d \n",x);
    show(dq);
    break;
  
    case 3:
    printf("Enter element to be inserted at right: ");
    scanf("%d",&x);
    insertright(&dq,x);
    show(dq);
    break;

    case 4:
    x=removeright(&dq);
    printf("Element removed from right is: %d \n",x);
    show(dq);
    break;
  }
 }
 while(ch!=5);

 destroydeque(&dq);

 getch();
}
