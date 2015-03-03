/* Singly Linked List ( Copy, Concatenate, Split ) - Program to implement
   operations of copy, concatenate and split on singly linked list */

#include <stdio.h>
#include <stdlib.h>     /* Not required */
#include <math.h>

#ifndef NULL
#define NULL 0      /* Not required */
#endif
/* Assume that the data portion of each node consists of ONLY an integer.*/

struct node
{
    int data;
    struct node *next;
};


/* This function is responsible for creating the Linked List
right from the BEGINING. */

void create(struct node **pfirst)
{
    int i, n;
    struct node *pnode, *p;

    printf("Enter the number of nodes required:\n");
    scanf("%d", &n);

    printf("Enter the data value of each node:\n");
    for(i = 1; i <= n; i++)
    {
        pnode = (struct node*)malloc(sizeof(struct node));

        if(pnode == NULL)
        {
            printf("Memory overflow. Unable to create.\n");
            return;
        }

        scanf("%d", &pnode->data);
        pnode->next = NULL; /* New node will be the last node */

        if(*pfirst == NULL)
            *pfirst = p = pnode;
        else
        {
            p->next = pnode;
            p = pnode;    /* p keeps track of last node */
        }
    }
}

/* This function go through all the nodes of Linked List exactly once
   and will display data value of each node */
void traverse(struct node *first)
{
    struct node *p;
    if(first == NULL)
        printf("Linked List Empty\n");
    else
    {
        p = first;
        while(p != NULL)
        {
            printf("%d ", p->data);
            p = p->next;
        }
        printf("\n");
    }
}

/* This function will copy contents of first linked list
   into a newly created second linked list */
void copy(struct node *first1, struct node **pfirst2)
{
    struct node *pnode, *p1, *p2;
    /* p1 keeps track of original linked list.
       p2 keeps track of copied   linked list. */

    if(first1 == NULL)
        return;

    p1 = first1;
    while(p1 != NULL)
    {
        pnode = (struct node*)malloc(sizeof(struct node));
        pnode->data = p1->data;
        pnode->next = NULL; /* could be the last node */

        if(*pfirst2 == NULL)
            *pfirst2 = p2 = pnode;
        else
        {
            p2->next = pnode;
            p2 = pnode;
        }
        p1 = p1->next;
    }
}

/* This function will create a third linked list by concatenating
   contents of first and second linked list */
void concatenate(struct node *first1, struct node *first2,
                 struct node **pfirst3)
{
    struct node *p1;

    if(first1 == NULL && first2 == NULL)
        return;
    else if(first1 == NULL)
        *pfirst3 = first2;
    else if(first2 == NULL)
        *pfirst3 = first1;
    else
    {
        p1 = first1;
        while(p1->next != NULL)
            p1 = p1->next;

        p1->next = first2;

        *pfirst3 = first1;
    }
}

/* This function will split a linked list from centre
   thereby creating two new linked lists. If the
   linked list has odd number of nodes then the first
   linked list will have one node more than second one */
void split(struct node **pfirst1, struct node **pfirst2)
{
    struct node *p1, *last;
    int i;
    float n = 0;

    if(*pfirst1 == NULL)
        return;

    /* Counting the number of nodes */
    p1 = *pfirst1;
    while(p1 != NULL)
    {
        n++;
        p1 = p1->next;
    }

    last = *pfirst1;
    for(i = 1; i < ceil(n / 2); i++)
        last = last->next;

    /* The for loop brings last to the last node of the
       first half. The expression ceil(n/2) = 3 for n=6 or 5
       and 1 for n=1 */

    *pfirst2 = last->next;
    last->next = NULL;
}

int main()
{
    int x, k, ch;

    struct node *first1, *first2, *first3;

    do
    {
        printf("\n Menu: \n");
        printf("1:Copy \n");
        printf("2:Concatenate \n");
        printf("3:Split \n");
        printf("4:Exit \n");

        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                first1 = first2 = NULL;
                printf("Creating Original Linked List:\n");
                create(&first1);
                copy(first1, &first2);
                printf("Original Linked List:\n");
                traverse(first1);
                printf("Copied Linked List:\n");
                traverse(first2);
                break;

            case 2:
                first1 = first2 = first3 = NULL;
                printf("Creating first Linked List:\n");
                create(&first1);
                printf("Creating second Linked List:\n");
                create(&first2);
                concatenate(first1, first2, &first3);
                printf("Concatenated Linked List:\n");
                traverse(first3);
                break;

            case 3:
                first1 = first2 = NULL;
                printf("Creating original Linked List:\n");
                create(&first1);
                split(&first1, &first2);
                printf("First Half of original Linked List:\n");
                traverse(first1);
                printf("Second Half of original Linked List:\n");
                traverse(first2);
                break;

            case 4:
                break;
        }
    }
    while(ch != 4);
    return 0;
}







