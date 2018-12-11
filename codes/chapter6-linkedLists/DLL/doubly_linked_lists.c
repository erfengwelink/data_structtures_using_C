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

node_t *create_dll(node_t *start)
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
        if (NULL == start)
        {
            new_node->next = NULL;
            new_node->prev = NULL;
            start = new_node;
            //printf("NULL\n");
        }
        else
        {
            ptr = start;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = new_node;
            new_node->next = NULL;
            new_node->prev = ptr;
            //printf("certain\n");
        }
        printf("\n Enter the data:");
        scanf("%d", &num);
    }
    return start;
}

node_t *display(node_t *start)
{
    printf("\n Whole nodes: ");
    printf("\n Display:\n");
    node_t *ptr;
    ptr = start;
    if (ptr == NULL)
    {
        printf("\n CLL is NULL");
        return start;
    }
    while (ptr->next != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("%d\t", ptr->data);

    return start;
}

node_t *insert_beg(node_t *start)
{
    node_t *ptr, *new_node;
    int num;
    printf("\n Enter the data that you wanna insert:");
    scanf("%d", &num);
    ptr = start;
    new_node = (node_t *)malloc(sizeof(node_t));
    if (new_node)
    {
        new_node->data = num;
        new_node->next = ptr;
        new_node->prev = NULL;
        start = new_node;
    }
    return start;
}

node_t *insert_end(node_t *start)
{
    node_t *ptr, *new_node;
    int num;
    printf("\n Enter the data that you wanna insert:");
    scanf("%d", &num);
    ptr = start;
    new_node = (node_t *)malloc(sizeof(node_t));
    if (new_node)
    {
        while (ptr->next != NULL)
        {
            printf("%d @", ptr->data);
            ptr = ptr->next;
        }
        new_node->data = num;
        new_node->next = NULL;
        new_node->prev = ptr;
        ptr->next = new_node;
    }
    return start;
}

node_t *insert_before(node_t *start)
{
    node_t *ptr, *new_node, *bef;
    int num, val;
    printf("\n Enter the num that you wanna find:");
    scanf("%d", &num);
    printf("\n Enter the data that you wanna insert before %d:", num);
    scanf("%d", &val);
    ptr = start;
    new_node = (node_t *)malloc(sizeof(node_t));
    if (new_node)
    {
        while (ptr->data != num)
        {
            printf("%d @", ptr->data);
            bef = ptr;
            ptr = ptr->next;
        }

        new_node->data = val;
        new_node->prev = bef;
        new_node->next = ptr;
        bef->next = new_node;
    }
    return start;
}

node_t *insert_after(node_t *start)
{
    node_t *ptr, *new_node, *oaft;
    int num, val;
    printf("\n Enter the num that you wanna find:");
    scanf("%d", &num);
    printf("\n Enter the data that you wanna insert after %d:", num);
    scanf("%d", &val);
    ptr = start;
    new_node = (node_t *)malloc(sizeof(node_t));
    if (new_node)
    {
        while (ptr->data != num)
        {
            printf("%d @", ptr->data);
            ptr = ptr->next;
        }
        new_node->data = val;
        new_node->prev = ptr;
        
        if(NULL != ptr->next)
        {
            oaft = ptr->next;
            new_node->next = oaft;
            oaft->prev = new_node;
        }else{
            new_node->next = NULL;
        }
        ptr->next = new_node;
        
    }
    return start;
}

#if 0
node_t *delete_beg(node_t *start)
{
    node_t *ptr, *old;
    ptr = start;
    if(ptr)
    {
        if(ptr->next)
        {
            old = ptr;
            ptr = ptr->next;
            old->next = NULL;
            ptr->prev = NULL;
            printf("\n free data:%d", old->data);
            free(old);
            start = ptr;
        }else{
            printf("\n Only one linkedLists Cannot delete!");
        }
    }else{
        printf("\n Already is NULL linkedLists!");
    }
    return start;
}

#else
node_t *delete_beg(node_t *start)
{
    node_t *ptr;
    ptr = start;
    start = start->next;
    start->prev = NULL;
    free(ptr);
    return start;
}
#endif


node_t *delete_end(node_t *start)
{
    node_t *ptr;
    ptr = start;
    if(ptr)
    {
        while(ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        printf("\n >>%d", ptr->data);
        if(ptr)
        {
            ptr->prev->next = NULL;
            free(ptr);
        }else{
            printf("\n Only one linkedLists Cannot delete!");
        }
    }else{
        printf("\n Already is NULL linkedLists!");
    }
    return start;
}

node_t *delete_before(node_t *start)
{
    node_t *ptr, *bef;
    int num, ok = 0;
    printf("\n Enter the num that you wanna delete before:");
    scanf("%d", &num);
    ptr = start;
    while(ptr->next != NULL)
    {
        if(ptr->data == num)
        {
            ok = 1;
            break;
        }
        ptr = ptr->next;
    }
    if(ok)
    {
        bef = ptr->prev;
        bef->prev->next = ptr;
        ptr->prev = bef->prev;
        bef->prev = NULL;
        bef->next = NULL;
        free(bef);
    }
    return start;
}

node_t *delete_after(node_t *start)
{
    node_t *ptr, *aft;
    int num, ok = 0;
    printf("\n Enter the num that you wanna delete after:");
    scanf("%d", &num);

    ptr = start;
    while(ptr->next != NULL)
    {
        if(ptr->data == num)
        {
            ok = 1;
            break;
        }
        ptr = ptr->next;
    }
    if(ok)
    {
        aft = ptr->next;
        aft->prev->next = aft->next;
        aft->next->prev = aft->prev;
        aft->prev = NULL;
        aft->next = NULL;
        free(aft);
    }
    return start;
}

node_t *delete_list(node_t *start)
{
    while(NULL != start)
        start = delete_beg(start);
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
        printf("\n 5: Add a node before a given node");
        printf("\n 6: Add a node after a given node");

        printf("\n 7: Delete a node from the beginning");
        printf("\n 8: Delete a node from the end");
        printf("\n 9: Delete a node before a given node");
        printf("\n 10: Delete a node after a given node");
        printf("\n 11: Delete the entire list");
        printf("\n 12: EXIT");
        printf("\n Enter your option : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            start = create_dll(start);
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
            start = delete_before(start);
            break;
        case 10:
            start = delete_after(start);
            break;
        case 11:
            start = delete_list(start);
            break;
        default:

            break;
        }

    } while (12 != option);

    return 0;
}

#endif