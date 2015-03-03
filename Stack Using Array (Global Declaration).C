/* Stack using array - Program to implement ADT stack using array */

#include <stdio.h>

#define STACKSIZE 5
#define ERROR (-1)
#define OK      0

struct stack
{
    int top;
    int items[STACKSIZE]; /* assuming that stack consists of integers */
};

struct stack s;

int empty();

int push(int x)
{
    if(s.top == STACKSIZE - 1)
    {
        printf("Stack Overflow. Cannot push \n");
        return ERROR; /* terminates program */
    }
    s.items[++(s.top)] = x;
    return OK;
}

int empty()
{
    if(s.top == -1)
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
    return (s.items[(s.top)--]);
}

int stacktop()
{
    if(empty())
    {
        printf("Stack Underflow. \n");
        return ERROR;
    }
    return (s.items[s.top]);
}

void show()
{
    int i;
    printf("Stack from topmost element is as shown:\n");
    for(i = s.top; i >= 0; i--)
        printf("%d ", s.items[i]);
}

int main()
{
    int x, ch;

    s.top = -1;


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
