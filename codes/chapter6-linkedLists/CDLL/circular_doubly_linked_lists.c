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

node_t *create_cdll(node_t *start)
{
    node_t *ptr = NULL;
    int nvalue = 0;
    ptr = start;
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (NULL == new_node)
    {
        printf("memory allocate failed!!!\n");
        return start;
    }
    printf("Enter the new node data value:\n");
    scanf("%d", &nvalue);
    new_node->data = nvalue;
    if (NULL == ptr)
    {
        new_node->prev = new_node;
        new_node->next = new_node;
        start = new_node;
    }
    else
    {
        while (ptr->next != start)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
        start->prev = new_node;
        new_node->next = start;
        new_node->prev = ptr;
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
    while (ptr->next != start)
    {
        printf(" %d", ptr->data);
        ptr = ptr->next;
    }
    printf(" %d", ptr->data);
    return start;
}

node_t *insert_beg(node_t *start)
{
    node_t *ptr = NULL, *s = NULL;
    int nvalue = 0;
    ptr = start;
    s = start;
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (NULL == new_node)
    {
        printf("memory allocate failed!!!\n");
        return start;
    }
    printf("Enter the node data value U wanna insert at beginning of CDLL:");
    scanf("%d", &nvalue);
    new_node->data = nvalue;
    while (ptr->next != start)
    {
        //printf(" %d", ptr->data);
        ptr = ptr->next;
    }
    ptr->next = new_node;
    new_node->next = start;
    new_node->prev = ptr;
    start->prev = new_node;
    s = new_node;
    return s;
}

node_t *insert_end(node_t *start)
{
    node_t *ptr = NULL;
    int nvalue = 0;
    ptr = start;
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (NULL == new_node)
    {
        printf("memory allocate failed!!!\n");
        return start;
    }
    printf("Enter the new node data value:\n");
    scanf("%d", &nvalue);
    new_node->data = nvalue;
    if (NULL == ptr)
    {
        new_node->prev = new_node;
        new_node->next = new_node;
        start = new_node;
    }
    else
    {
        while (ptr->next != start)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
        start->prev = new_node;
        new_node->next = start;
        new_node->prev = ptr;
    }
    return start;
}

node_t *delete_beg(node_t *start)
{
    node_t *ptr = NULL, *s = NULL;
    ptr = start;
    s = start->next;

    while (ptr->next != start)
    {
        ptr = ptr->next;
    }
    ptr->next = s;
    s->prev = ptr;
    start->prev = NULL;
    start->next = NULL;
    free(start);
    return s;
}

node_t *delete_end(node_t *start)
{
    node_t *ptr = NULL, *s = NULL, *temp = NULL;
    ptr = start;
    s = start;
    while (ptr->next != start)
    {
        temp = ptr;
        ptr = ptr->next;
    }
    temp->next = s;
    s->prev = temp;
    ptr->prev = NULL;
    ptr->next = NULL;
    free(ptr);
    return start;
}

node_t *delete_node(node_t *start)
{
    node_t *ptr = NULL, *temp = NULL;
    int dvalue = 0;
    ptr = start;
    printf("Enter the node value that U wanna delete:\n");
    scanf("%d", &dvalue);
    while (ptr->next != start && dvalue != ptr->data)
    {
        temp = ptr;
        ptr = ptr->next;
    }

    if (dvalue == ptr->data)
    {
        temp->next = ptr->next;
        ptr->next->prev = temp;
        ptr->prev = NULL;
        ptr->next = NULL;
        free(ptr);
    }
    else
    {
        printf("NO FUND node!\n");
    }

    return start;
}

node_t *delete_list(node_t *start)
{
    if(NULL == start)
    {
        printf("Already NULL list!\n");
        return start;
    }
    while(start->prev != start)
    {
        start = delete_end(start);
    }
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
        printf("\n 3: Add a node at the beginning");
        printf("\n 4: Add a node at the end");

        printf("\n 5: Delete a node from the beginning");
        printf("\n 6: Delete a node from the end");

        printf("\n 7: Delete a node after a given node");
        printf("\n 8: Delete the entire list");
        printf("\n 9: EXIT");
        printf("\n Enter your option : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            start = create_cdll(start);
            printf("\n LINKED LIST CREATED");
            break;
        case 2:
            start = display(start);
            break;
        case 3:
            start = insert_beg(start);
            break;
        case 4:
            start = insert_end(start);
            break;
        case 5:
            start = delete_beg(start);
            break;
        case 6:
            start = delete_end(start);
            break;
        case 7:
            start = delete_node(start);
            break;
        case 8:
            start = delete_list(start);
            break;
        default:

            break;
        }

    } while (9 != option);
    return 0;
}

#endif