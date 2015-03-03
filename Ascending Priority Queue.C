/* Ascending priority queue using Linked List - Program to implement
   Ascending priority queue using Linked List */

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

int empty(struct queue *pq);

/* This function initializes the queue to be empty by making
   both front and rear as NULL */
void createqueue(struct queue *pq)
{
    pq->front = pq->rear = NULL;
}

int empty(struct queue *pq)
{
    if(pq->front == NULL)
        return 1;
    else
        return 0;
}

int insert(struct queue *pq, int x)
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
    if(empty(pq))
        pq->front = pq->rear = pnode;
    else
    {
        pq->rear->next = pnode;
        pq->rear = pnode;
    }
    return OK;
}

int removes(struct queue *pq)
{
    int min;
    struct node *follow, *follow1, *p, *p1;

    if(empty(pq))
    {
        printf("\nQueue Underflow. Unable to remove.");
        return ERROR;
    }

    /* finding the node with minimum value in the APQ.*/
    p = p1 = pq->front;
    follow = follow1 = NULL;
    min = pq->front->data;
    while(p != NULL)
    {
        if(p->data < min)
        {
            min = p->data;
            follow1 = follow;
            p1 = p;
        }
        follow = p;
        p = p->next;
    }

    /* Deleting the node with min value */

    if(p1 == pq->front) /* deleting first node.*/
    {
        pq->front = pq->front->next;
        if(pq->front == NULL)     /* Deleting the only one node */
            pq->rear = NULL;
    }
    else if(p1 == pq->rear) /* Deleting last node */
    {
        pq->rear = follow1;
        pq->rear->next = NULL;
    }
    else          /* deleting any other node.*/
        follow1->next = p1->next;


    free(p1);
    return min;    /* DONT FORGET LAST 2 STATEMENTS.*/
}

void show(struct queue q)
{
    struct node *p;

    if(empty(&q))
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

void destroyqueue(struct queue *pq)
{
    pq->front = pq->rear = NULL;
}

int main()
{
    int x, ch;

    struct queue q;
    createqueue(&q);


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
                insert(&q, x);
                show(q);
                break;

            case 2:
                x = removes(&q);
                printf("Element removed is: %d\n", x);
                show(q);
                break;

            case 3:
                break;
        }
    }
    while(ch != 3);

    destroyqueue(&q);

    return OK;
}








