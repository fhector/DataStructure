/* Stack using array - Program to implement ADT stack using array */

#include <stdio.h>

#define STACKSIZE 5
#define ERROR (-1)
#define OK      0

int top;
int items[STACKSIZE]; /* assuming that stack consists of integers */

int empty();


int push(int x)
{
    if(top == STACKSIZE - 1)
    {
        printf("Stack Overflow. Cannot push \n");
        return ERROR; /* terminates program */
    }
    items[++top] = x;
    return OK;
}

int empty()
{
    if(top == -1)
        return 1;
    else
        return 0;
}

int pop()
{
    if(empty())
    {
        printf("Stack Underflow. Cannot pop \n");
        return ERROR;
    }
    return (items[top--]);
}

int stacktop()
{
    if(empty())
    {
        printf("Stack Underflow. \n");
        return ERROR;
    }
    return (items[top]);
}

void show()
{
    int i;
    printf("Stack from topmost element is as shown:\n");
    for(i = top; i >= 0; i--)
        printf("%d ", items[i]);
}

int main()
{
    int x, ch;


    top = -1;

    do
    {
        printf("\n\n  Menu: \n");
        printf("1:push \n");
        printf("2:pop \n");
        printf("3:stacktop \n");
        printf("4:exit \n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                printf("Enter element to be pushed: ");
                scanf("%d", &x);
                push(x);
                show();
                break;

            case 2:
                x = pop();
                printf("Element popped is %d \n", x);
                show();
                break;

            case 3:
                x = stacktop();
                printf("Topmost Element is %d \n", x);
                show();
                break;

            case 4:
                break;
        }
    }
    while(ch != 4);
    return OK;
}
