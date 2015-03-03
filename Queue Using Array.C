/* Queue using array - Program to implement a ADT queue using array */

#include <stdio.h>

#define QUEUESIZE 5
#define ERROR (-1)
#define OK      0

struct queue
{
    int front, rear;
    int items[QUEUESIZE]; /* assuming queue contains integers */
};

int empty(struct queue *pq);
int insert(struct queue *pq, int x)
{
    if(pq->rear == QUEUESIZE - 1)
    {
        printf("Queue Overflow. Cannot insert \n");
        return ERROR;   /* terminates program */
    }
    pq->items[++(pq->rear)] = x;
    return OK;
}


int removes(struct queue *pq)
{
    if(empty(pq))
    {
        printf("Queue Underflow. Cannot remove \n");
        return ERROR;
    }
    return (pq->items[(pq->front)++]);
}

int empty(struct queue *pq)
{
    if(pq->rear < pq->front)
        return 1;
    else
        return 0;
}

void show(struct queue q)
{
    int i;
    printf("Queue from frontmost element is as shown:\n");
    for(i = q.front; i <= q.rear; i++)
        printf("%d ", q.items[i]);
}

int main()
{
    int x, ch;

    struct queue q;


    q.rear = -1;
    q.front = 0;

    do
    {
        printf("\n Menu: \n");
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
                printf("Element removed is: %d \n", x);
                show(q);
                break;

            case 3:
                break;
        }
    }
    while(ch != 3);
    return OK;
}

