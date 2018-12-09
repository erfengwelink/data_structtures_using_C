#include <stdio.h>
#include <stdlib.h>


#if 1

typedef struct node{
    int data;
    struct node *next;
}node_t;

node_t *start = NULL;

node_t *create_cll(node_t* node)
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
            new_node->next = new_node;
            node = new_node;
            //printf("NULL\n");
        }
        else
        {
            ptr = node;
            while (ptr->next != node)
            {
                ptr = ptr->next;
            }
            ptr->next = new_node;
            new_node->next = node;
            //printf("certain\n");
        }
        printf("\n Enter the data:");
        scanf("%d", &num);
    }
    return node;
}

node_t *display(node_t* node)
{
    printf("\ Display:\n");
    node_t *ptr;
    ptr = node;
    while(ptr->next != node)
    {
        printf("\t%d", ptr->data);
        ptr = ptr->next;
    }
    return node;
}

node_t *insert_beg(node_t* node)
{

    return node;
}

node_t *insert_end(node_t* node)
{

    return node;
}

node_t *delete_beg(node_t* node)
{

    return node;
}

node_t *delete_end(node_t* node)
{

    return node;
}

node_t *delete_after(node_t* node)
{

    return node;
}

node_t *delete_list(node_t* node)
{

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
            start = create_cll(start);
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
            start = delete_after(start);
            break;
        case 8:
            start = delete_list(start);
            break;
        default:

            break;
        }

    } while (9 != option);
    //getch();
    //printf("\n Marks: %d", stud.marks);
    return 0;
}

#endif