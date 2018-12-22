#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int st[MAX], top = -1;

void push(int st[], int v)
{
    if (-1 == top)
    {
        st[0] = v;
        top = 0;
    }
    else if (top < MAX)
    {
        top++;
        st[top] = v;
    }
    else
    {
        printf("Your size overflow!!!\n");
    }
}

int pop(int st[])
{
    int v = 0;
    if (top >= 0)
    {
        v = st[top];
        st[top] = 0;
        top--;
    }
    else
    {
        printf("\n stack is empty!\n");
    }

    return v;
}

int peek(int st[])
{
    if(top >= 0)
    {
        return st[top];
    }
    else
    {
        return -1;
    }
}

void display(int st[])
{
    if (-1 == top)
    {
        printf("\n stack is NULL\n");
    }
    else
    {
        printf("\n stack :\n");
        for (int i = top; i >= 0; i--)
        {
            printf(" %d", st[i]);
        }
        printf(" \n");
    }
}

int main()
{
    int option, val;

    do
    {
        printf("\n *****MAIN MENU******");
        printf("\n 1. PUSH");
        printf("\n 2. POP");
        printf("\n 3. PEEK");
        printf("\n 4. DISPLAY");
        printf("\n 5. EXIT");
        printf("\n Enter your option:");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("\n Enter the num to be pushed on stack : ");
            scanf("%d", &val);
            push(st, val);
            break;
        case 2:
            val = pop(st);
            if (-1 != val)
            {
                printf("\n the val deleted from stack is : %d ", val);
            }
            break;
        case 3:
            val = peek(st);
            if (-1 != val)
            {
                printf("\n the val at the top of stack is : %d ", val);
            }
            break;
        case 4:
            display(st);
            break;
        default:

            break;
        }

    } while (5 != option);

    return 0;
}