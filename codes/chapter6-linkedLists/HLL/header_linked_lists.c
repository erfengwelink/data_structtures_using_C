#include <stdio.h>
#include <stdlib.h>

#if 1

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} node_t;

node_t *start = NULL;

#if 0
node_t *create_hll(node_t *start)
{
    node_t *ptr = NULL;
    int nvalue = 0;
    ptr = start;

    printf("Enter the new node data value:\n");
    scanf("%d", &nvalue);
    while (nvalue != -1)
    {
        node_t *new_node = (node_t *)malloc(sizeof(node_t));
        if (NULL == new_node)
        {
            printf("memory allocate failed!!!\n");
            return start;
        }

        new_node->data = nvalue;
        if (NULL == start)
        {
            printf("NULL == ptr\n");
            start = (node_t *)malloc(sizeof(node_t));
            new_node->prev = new_node;
            new_node->next = new_node;
            start->next = new_node;
            //printf("NULL == %s\n", start == NULL ? "NULL":"start");
        }
        else
        {
            printf("ptr->next %d |  start->next->prev %d\n", ptr->next->data, start->next->prev->data);
            ptr = start->next;
            if (ptr->next == ptr && ptr->prev == ptr)
            {
                printf("***********\n");
                // ptr->next = new_node;
                // ptr->prev = new_node;
                // new_node->prev = ptr;
                // new_node->next = ptr;
            }
            else
            {
                printf("@@@@@@@@@@@@@\n");
                // while (ptr->next != start->next->prev)
                // {
                //     ptr = ptr->next;
                // }
                // printf("DATA:%d \n", ptr->data);
                // ptr->next = new_node;
                // start->next->prev = new_node;
                // new_node->next = start->next;
                // new_node->prev = ptr;
            }
        }
        printf("Enter the new node data value:\n");
        scanf("%d", &nvalue);
    }

    return start;
}
#endif

node_t *create_hll(node_t *start)
{
    int nvalue = 0;
    node_t *ptr = NULL, *beg = NULL, *new_node = NULL;

    printf("Enter -1 to end!\n");
    printf("Enter data:");
    scanf("%d", &nvalue);
    while (-1 != nvalue)
    {
        printf("value you entered: %d\n", nvalue);
        new_node = (node_t *)malloc(sizeof(node_t));
        if (NULL == new_node)
        {
            printf(" 'new_node' mem allocate fail!\n");
            return start;
        }
        new_node->data = nvalue;
        new_node->next = NULL;
        new_node->prev = NULL;

        if (NULL == start)
        {
            start = (node_t *)malloc(sizeof(node_t));
            if (NULL == start)
            {
                printf(" 'start' mem allocate fail!\n");
                return start;
            }
            new_node->prev = new_node;
            new_node->next = new_node;
            start->next = new_node;
        }
        else
        {
            ptr = start->next;
            if (ptr->next == ptr && ptr->prev == ptr)
            {
                ptr->next = NULL;
                ptr->prev = NULL;
                new_node->prev = ptr;
                new_node->next = ptr;
                ptr->next = new_node;
                ptr->prev = new_node;
            }
            else
            {
                ptr = start->next;
                beg = start->next;
                while (ptr->next != beg)
                {
                    //printf("%d |", ptr->data);
                    ptr = ptr->next;
                }
                //printf("ptr %d |", ptr->data);
                ptr->next = new_node;
                new_node->prev = ptr;
                beg->prev = new_node;
                new_node->next = beg;
            }
        }

        printf("Enter data:");
        scanf("%d", &nvalue);
    }
    return start;
}

node_t *display(node_t *start)
{
    node_t *ptr = NULL;
    ptr = start;
    printf("Display: \n");
    if (ptr == NULL)
    {
        printf(" NULL \n");
        return start;
    }
    ptr = start->next;
    while (ptr->next != start->next)
    {
        printf(" %d", ptr->data);
        ptr = ptr->next;
    }
    printf(" %d", ptr->data);
    return start;
}

int main()
{
    int option;
    do
    {

        printf("\n\n ********* Main Menu **********");
        printf("\n 1: Create a list");
        printf("\n 2: Display the list");

        printf("\n 3: EXIT");
        printf("\n Enter your option : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            start = create_hll(start);
            printf("\n LINKED LIST CREATED");
            break;
        case 2:
            start = display(start);
            break;
        default:

            break;
        }

    } while (3 != option);
    return 0;
}

#endif