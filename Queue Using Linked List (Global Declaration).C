/* Queue using Linked List - Program to create a queue ADT using
linked list. ADT should support the following operations
1)  Createqueue
2)  Insert into the queue
3)  Delete from the queue
4)  destroyqueue
*/

#include <stdio.h>
#include <stdlib.h> /* Not required */
#ifndef NULL
#define NULL 0      /* Not required */
#endif
#define ERROR (-1)
#define OK      0
struct node
{
    int data;
    struct node *next;
};

struct queue
{
    struct node *front,
               *rear;
};

struct queue q;


int empty();


/* This function initializes the queue to be empty by making
   both front and rear as NULL */
void createqueue()
{
    q.front = q.rear = NULL;
}

int empty()
{
    if(q.front == NULL)
        return 1;
    else
        return 0;
}

int insert(int x)
{
    struct node *pnode;

    pnode = (struct node*)malloc(sizeof(struct node));

    if(pnode == NULL)
    {
        printf("Memory overflow. Unable to insert.\n");
        return ERROR;
    }
    pnode->data = x;
    pnode->next = NULL; /* New node is always last node */
    if(empty())
        q.front = q.rear = pnode;
    else
    {
        (q.rear)->next = pnode;
        q.rear = pnode;
    }
    return OK;
}

int removes()
{
    int x;
    struct node *p;

    if(empty())
    {
        printf("Queue Underflow. Unable to remove.\n");
        return ERROR;
    }
    p = q.front;
    x = (q.front)->data;
    q.front = (q.front)->next;
    if(q.front == NULL)     /* Queue contained only one node */
        q.rear = NULL;
    free(p);
    return x;
}

void show()
{
    struct node *p;

    if(empty())
        printf("Queue empty. No data to display \n");
    else
    {
        printf("Queue from front to rear is as shown: \n");
        p = q.front;
        while(p != NULL)
        {
            printf("%d ", p->data);
            p = p->next;
        }
        printf("\n");
    }
}

void destroyqueue()
{
    q.front = q.rear = NULL;
}

int main()
{
    int x, ch;

    createqueue();


    do
    {
        printf("\n\n  Menu: \n");
        printf("1:Insert \n");
        printf("2:Remove \n");
        printf("3:exit \n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                printf("Enter element to be inserted: ");
                scanf("%d", &x);
                insert(x);
                show();
                break;

            case 2:
                x = removes();
                printf("Element removed is: %d\n", x);
                show();
                break;

            case 3:
                break;
        }
    }
    while(ch != 3);

    destroyqueue();

    return OK;
}








