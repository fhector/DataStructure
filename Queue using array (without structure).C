/* Queue using array - Program to implement ADT queue using array */

#include <stdio.h>
#define QUEUESIZE 5
#define ERROR (-1)
#define OK      0

int front, rear;
int items[QUEUESIZE]; /* assuming queue contains integers */

int empty();
int insert(int x)
{
    if(rear == QUEUESIZE - 1)
    {
        printf("Queue Overflow. Cannot insert \n");
        return ERROR;   /* terminates program */
    }
    items[++rear] = x;
    return OK;
}


int removes()
{
    if(empty())
    {
        printf("Queue Underflow. Cannot remove \n");
        return ERROR;
    }
    return (items[front++]);
}

int empty()
{
    if(rear < front)
        return 1;
    else
        return 0;
}

void show()
{
    int i;
    printf("Queue from frontmost element is as shown:\n");
    for(i = front; i <= rear; i++)
        printf("%d ", items[i]);
}

int main()
{
    int x, ch;


    rear = -1;
    front = 0;

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
                insert(x);
                show();
                break;

            case 2:
                x = removes();
                printf("Element removed is: %d \n", x);
                show();
                break;

            case 3:
                break;
        }
    }
    while(ch != 3);
    return OK;
}

