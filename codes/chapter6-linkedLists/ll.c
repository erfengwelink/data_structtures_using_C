#include <stdio.h>
#include <stdlib.h>

#if 1

typedef struct node
{
    int data;
    struct node *next;
} node_t;

node_t *start = NULL;
node_t *create_ll(node_t *node)
{
    node_t *ptr, *new_node;
    int num;
    printf("\n Enter -1 to end");
    printf("\n Enter the data:");
    scanf("%d", &num);
    while (-1 != num)
    {
        new_node = (node_t *)malloc(sizeof(node_t));
        new_node->data = num;
        if (NULL == node)
        {
            new_node->next = NULL;
            node = new_node;
            //printf("NULL\n");
        }
        else
        {
            ptr = node;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = new_node;
            new_node->next = NULL;
            //printf("certain\n");
        }
        printf("\n Enter the data:");
        scanf("%d", &num);
    }

#if 0
    if(node)
        printf("\t %d", node->data);
    ptr = node;
    while(ptr->next != NULL)
    {
        printf("\t %d", ptr->data);
        ptr = ptr->next;
    }
#endif

    return node;
}

node_t *display(node_t *node)
{
    node_t *ptr;
    ptr = node;
    if (ptr)
    {
        while (NULL != ptr)
        {
            printf("%d \t", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
    return node;
}

node_t *insert_beg(node_t *node)
{
    int num;
    node_t *new_node, *ptr = NULL;
    ptr = node;
    new_node = (node_t *)malloc(sizeof(node_t));
    printf("\n Enter the num(data) you want to insert at begin : ");
    scanf("%d", &num);
    new_node->data = num;
    new_node->next = node;
    return new_node;
}

node_t *insert_end(node_t *node)
{
    int num;
    node_t *new_node, *ptr = NULL;
    ptr = node;
    new_node = (node_t *)malloc(sizeof(node_t));
    printf("\n Enter the num(data) you want to insert at end : ");
    scanf("%d", &num);
    new_node->data = num;
    while (ptr->next)
    {
        ptr = ptr->next;
    }
    ptr->next = new_node;
    return node;
}

node_t *insert_before(node_t *node)
{
    int num, val;
    node_t *ptr, *bfr, *new_node;
    ptr = node;
    new_node = (node_t *)malloc(sizeof(node_t));
    printf("\n Enter the num(data) you want to insert before certain value : ");
    scanf("%d", &num);
    new_node->data = num;

    printf("\n Enter the certain value : ");
    scanf("%d", &val);

    if (ptr->next == NULL)
    {
        printf("\n There are only one node in LL.");
        if (val == ptr->data)
        {
            printf("\n There are only one node in LL. insert OK!");
            new_node->next = node;
            return new_node;
        }
        else
        {
            printf("\n Cannot found the matched data value return;");
            return node;
        }
    }

    while (ptr->data != val)
    {
        bfr = ptr;
        ptr = ptr->next;
    }
    bfr->next = new_node;
    new_node->next = ptr;
    return node;
}

node_t *insert_after(node_t *node)
{
    int num, val;
    node_t *ptr, *new_node;
    ptr = node;
    new_node = (node_t *)malloc(sizeof(node_t));
    printf("\n Enter the num(data) you want to insert after the certain value : ");
    scanf("%d", &num);
    new_node->data = num;

    printf("\n Enter the certain value : ");
    scanf("%d", &val);

    if (ptr->next == NULL)
    {
        printf("\n There are only one node in LL.");
        if (val == ptr->data)
        {
            printf("\n There are only one node in LL. insert OK!");
            new_node->next = NULL;
            node->next = new_node;
            return node;
        }
        else
        {
            printf("\n Cannot found the matched data value return;");
            return node;
        }
    }

    while (ptr->data != val)
    {
        ptr = ptr->next;
    }
    printf("\n Data:%d", ptr->data);

    new_node->next = ptr->next;
    ptr->next = new_node;

    return node;
}

node_t *delete_beg(node_t *node)
{
    node_t *ptr = NULL;
    ptr = node;
    //printf("\n Just to delete at begin : ");
    node = node->next;
    ptr->next = NULL;
    free(ptr);
    return node;
}

node_t *delete_end(node_t *node)
{
    node_t *new_node, *ptr = NULL;
    ptr = node;
    printf("\n Just to delete at end : ");
    while (ptr->next != NULL)
    {
        new_node = ptr;
        ptr = ptr->next;
    }
    new_node->next = NULL;
    free(ptr);
    return node;
}

node_t *delete_node(node_t *node)
{
    int val;
    node_t *new_node, *ptr = NULL;
    ptr = node;

    printf("\n Enter the certain value : ");
    scanf("%d", &val);
    if (ptr->data == val)
    {
        return delete_beg(node);
    }
    else
    {
        while (ptr->data != val && ptr->next)
        {
            new_node = ptr;
            ptr = ptr->next;
        }
        if (ptr->data == val)
        {
            new_node->next = ptr->next;
            ptr->next = NULL;
            free(ptr);
        }
        else
        {
            printf("\n Cannot found the certain value !");
        }
    }

    return node;
}

node_t *delete_after(node_t *node)
{
    int val;
    node_t *new_node, *ptr = NULL;
    ptr = node;

    printf("\n Enter the certain value that you want to delete after it: ");
    scanf("%d", &val);
    if (ptr->data == val)
    {
        new_node = ptr->next;
        ptr->next = new_node->next;
        new_node->next = NULL;
        free(new_node);
    }
    else
    {
        while (ptr->data != val && ptr->next)
        {
            ptr = ptr->next;
        }
        if (val == ptr->data)
        {
            new_node = ptr->next;
            ptr->next = new_node->next;
            new_node->next = NULL;
            free(new_node);
        }
        else
        {
            printf("\n Cannot found the certain value !");
        }
    }
    return node;
}

#if 0
node_t *delete_list(node_t *node)
{
    node_t *ptr = NULL;
    ptr = node;
    while (ptr->next != NULL)
    {
        printf("\n <Deleting the node of value:%d ... ptr:%s", \
        ptr->data, ptr==NULL?"NULL":"!NULL");
        node = delete_beg(ptr);
        // if(ptr->next)
        // {
            ptr = ptr->next;
            printf("\n >Deleting the node of value:%d ... ptr:%s", \
            ptr->data, ptr==NULL?"NULL":"!NULL");
        // }
    }
    return node;
}
#endif
// error ????
node_t *delete_list(node_t *start)
{
    node_t *ptr;
    ptr = start;
    while(ptr->next != NULL)
    {
        printf("\n %d is to be deleted next", ptr->data);
        start = delete_beg(ptr);
        ptr = ptr->next;
    }
    return start;
}

node_t *sort_list(node_t *node)
{
    node_t *ptr1 = NULL, *ptr2 = NULL;
    int temp;

    ptr1 = node;
    printf("\n Sorting the list...");
    while (ptr1->next != NULL)
    {
        ptr2 = ptr1->next;
        while (ptr2 != NULL)
        {
            if (ptr1->data > ptr2->data)
            {
                temp = ptr2->data;
                ptr2->data = ptr1->data;
                ptr1->data = temp;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    return node;
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
        printf("\n 5: Add a node before a given node");
        printf("\n 6: Add a node after a given node");
        printf("\n 7: Delete a node from the beginning");
        printf("\n 8: Delete a node from the end");
        printf("\n 9: Delete a given node");
        printf("\n 10: Delete a node after a given node");
        printf("\n 11: Delete the entire list");
        printf("\n 12: Sort the list");
        printf("\n 13: EXIT");
        printf("\n Enter your option : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            start = create_ll(start);
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
            start = insert_before(start);
            break;
        case 6:
            start = insert_after(start);
            break;
        case 7:
            start = delete_beg(start);
            break;
        case 8:
            start = delete_end(start);
            break;
        case 9:
            start = delete_node(start);
            break;
        case 10:
            start = delete_after(start);
            break;
        case 11:
            start = delete_list(start);
            break;
        case 12:
            start = sort_list(start);
            break;
        default:

            break;
        }

    } while (13 != option);
    //getch();
    //printf("\n Marks: %d", stud.marks);
    return 0;
}

#endif
