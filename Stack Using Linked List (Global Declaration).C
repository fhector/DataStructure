/* Stack using Linked List - Program to create a stack ADT using
linked list. ADT should  support the following operations
1)  Createstack
2)  pushstack
3)  popstack
4)  destroystack
*/

#include <stdio.h>
#include <stdlib.h> /* Not required */
#ifndef NULL
#define NULL 0      /* Not required */
#endif
#define ERROR (-1)
#define OK      0

int empty();

struct node
{
    int data;
    struct node *next;
};

struct stack
{
    struct node *top;
};

struct stack s;

/* This fn. initializes the stack to be empty by making it NULL */
void createstack()
{
    s.top = NULL;
}

int pushstack(int x)
{
    struct node *pnode;

    pnode = (struct node*)malloc(sizeof(struct node));

    if(pnode == NULL)
    {
        printf("Memory overflow. Unable to push.\n");
        return ERROR;
    }
    pnode->data = x;

    pnode->next = s.top;
    s.top = pnode;
    return OK;
}

int empty()
{
    if(s.top == NULL)
        return 1;
    else
        return 0;
}

int popstack()
{
    int x;
    struct node *p;

    if(empty())
    {
        printf("Stack Underflow. Unable to pop.\n");
        return ERROR;
    }
    x = (s.top)->data;
    p = s.top;
    s.top = (s.top)->next;
    free(p);
    return x;
}

/* MIDDLE 3 STATEMENTS OF else SHOULD NOT BE WRITTEN
   FOR function stacktop()*/

void show()
{
    struct node *p;

    if(empty())
        printf("Stack empty. No data to display.\n");
    else
    {
        printf("Stack from topmost element is as shown:\n");
        p = s.top;
        while(p != NULL)
        {
            printf("%d ", p->data);
            p = p->next;
        }
        printf("\n");
    }
}

void destroystack()
{
    s.top = NULL;
}

int main()
{
    int x, ch;

    createstack();

    do
    {
        printf("\n\n  Menu: \n");
        printf("1:push \n");
        printf("2:pop \n");
        printf("3:exit \n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                printf("Enter element to be pushed: ");
                scanf("%d", &x);
                pushstack(x);
                show();
                break;

            case 2:
                x = popstack();
                printf("Element popped is: %d \n", x);
                show();
                break;

            case 3:
                break;
        }
    }
    while(ch != 3);

    destroystack();

    return OK;
}

/*
The operation createstack is same as s.top=-1.
Even if it is not asked it should be obviously given.
The question remains whether it should be given as a separate function.
Giving it as function is always preferable.
However the operation destroystack need not be given if not asked to do so.
Morover even empty operation was not asked.
But giving it is necessary for pop and for show.
*/






