/* Wacp to create a circularly linked list abstract data type. ADT should  support the following operations
1)  Deletion of nodes from the list
2)  List traversal
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};


/* This function is responsible for creating the Circuraly Linked List
right from the BEGINING. */

void create(struct node **pfirst, struct node **plast)
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

        if(*pfirst == NULL)
            *pfirst = *plast = pnode;
        else
        {
            (*plast)->next = pnode;
            *plast = pnode;  /* *plast keeps track of last node */
        }

        (*plast)->next = *pfirst;
    }
}


/* This function will delete a node with value k from the
   Linked List if such a node exists */
void deletenode(struct node **pfirst, struct node **plast, int k)
{
    struct node *p, *follow;

    p = *pfirst;
    follow = NULL;

    /* searching the node to be deleted */
    while(p->data != k && follow != *plast)
    {
        follow = p;
        p = p->next;
    }

    if(follow == *plast)
        printf("Required node not found.\n");
    else
    {
        if(p == *pfirst && p == *plast) /* deleting the one and the only node */
            *pfirst = *plast = NULL;
        else if(p == *pfirst)        /* deleting the first node */
        {
            *pfirst = (*pfirst)->next;
            (*plast)->next = *pfirst;
        }
        else if(p == *plast)       /* deleting the last node */
        {
            *plast = follow;
            (*plast)->next = *pfirst;
        }
        else                /* deleting any other node */
            follow->next = p->next;
        free(p);
    }
}

/* This function go through all the nodes of Linked List exactly once
   and will display data value of each node */
void traverse(struct node *first, struct node *last)
{
    struct node *p, *follow;
    if(first == NULL)
        printf("Circularly Linked List Empty");
    else
    {
        printf("Circularly Linked List is as shown: \n");
        p = first;
        follow = NULL;
        while(follow != last)
        {
            printf("%d ", p->data);
            follow = p;
            p = p->next;
        }
        printf("\n");
    }
}

int main()
{
    int x, k, ch;
    struct node *first = NULL;
    struct node *last = NULL;
    do
    {
        printf("\n Menu: \n");
        printf("1:Create Linked List \n");
        printf("2:Delete Node \n");
        printf("3:Traverse \n");
        printf("4:Exit \n");

        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                create(&first, &last);
                break;

            case 2:
                printf("Enter the data value of the node to be deleted: ");
                scanf("%d", &k);
                deletenode(&first, &last, k);
                break;

            case 3:
                traverse(first, last);
                break;

            case 4:
                break;

        }
    }
    while(ch != 4);
    return 0;
}


