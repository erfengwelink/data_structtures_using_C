#include <stdio.h>
#include <stdlib.h>

#if 1
typedef struct node
{
    int num;
    int coeff;
    struct node *next;
} node_t;

node_t *s1 = NULL;
node_t *s2 = NULL;
node_t *s3 = NULL;
node_t *s4 = NULL;

node_t *create_poly(node_t *s)
{
    int num, co;
    node_t *ptr = s;
    node_t *new_node = NULL;

    printf("\n Enter the number:");
    scanf("%d", &num);

    printf("\n Enter the coefficient:");
    scanf("%d", &co);
    while (-1 != num)
    {

        new_node = (node_t *)malloc(sizeof(node_t));
        if (NULL == new_node)
        {
            printf(" 'new_node' mem allocate fail!\n");
            return s;
        }
        new_node->next = NULL;
        new_node->num = num;
        new_node->coeff = co;
        if (NULL == s)
        {
            s = new_node;
        }
        else
        {
            ptr = s;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = new_node;
        }

        printf("\n Enter the number:");
        scanf("%d", &num);
        if (-1 == num)
        {
            break;
        }
        printf("\n Enter the coefficient:");
        scanf("%d", &co);
    }
    return s;
}

node_t *display_poly(node_t *s)
{
    node_t *ptr = s;
    while (ptr != NULL)
    {
        printf("\n %d  X  %d \t", ptr->num, ptr->coeff);
        ptr = ptr->next;
    }

    return s;
}

node_t *add_node(node_t *s, int n, int c)
{
    node_t *ptr, *new_node;
    if(NULL == s)
    {
        new_node = (node_t*)malloc(sizeof(node_t));
        new_node->num = n;
        new_node->coeff = c;
        new_node->next = NULL;
        s = new_node;
    }
    else
    {
        ptr = s;
        while(ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        new_node = (node_t*)malloc(sizeof(node_t));
        new_node->num = n;
        new_node->coeff = c;
        new_node->next = NULL;
        ptr->next = new_node;
    }
    return s;
}


node_t *add_poly(node_t *s1, node_t *s2, node_t *s3)
{
    node_t *p1, *p2;
    int sn;
    p1 = s1;
    p2 = s2;
    while(p1 != NULL && p2 != NULL)
    {
        if(p1->coeff == p2->coeff)
        {
            sn = p1->num + p2->num;
            s3 = add_node(s3, sn, p1->coeff);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if(p1->coeff > p2->coeff)
        {
            s3 = add_node(s3, p1->num, p1->coeff);
            p1 = p1->next;
        }
        else if(p1->coeff < p2->coeff)
        {
            s3 = add_node(s3, p2->num, p2->coeff);
            p2 = p2->next;
        }
    }
    if( NULL != p1 )
    {
        while(p2 != NULL)
        {
            s3 = add_node(s3, p2->num, p2->coeff);
            p2 = p2->next;
        }
    }
    if( NULL != p2 )
    {
        while(p1 != NULL)
        {
            s3 = add_node(s3, p1->num, p1->coeff);
            p1 = p1->next;
        }
    }
    return s3;
}

node_t *sub_poly(node_t *s1, node_t *s2, node_t *s4)
{
    node_t *p1, *p2;
    int sn;
    p1 = s1;
    p2 = s2;
    do
    {
        if(p1->coeff == p2->coeff)
        {
            sn = p1->num - p2->num;
            s4 = add_node(s4, sn, p1->coeff);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if(p1->coeff > p2->coeff)
        {
            s4 = add_node(s4, p1->num, p1->coeff);
            p1 = p1->next;
        }
        else if(p1->coeff < p2->coeff)
        {
            s4 = add_node(s4, p2->num, p2->coeff);
            p2 = p2->next;
        }
    }while(p1 != NULL || p2 != NULL);

    if( NULL == p1 )
    {
        while(p2->next != NULL)
        {
            s4 = add_node(s4, p2->num, p2->coeff);
            p2 = p2->next;
        }
    }
    if( NULL == p2 )
    {
        while(p1->next != NULL)
        {
            s4 = add_node(s4, p1->num, p1->coeff);
            p1 = p1->next;
        }
    }
    return s4;
}


int main()
{
    int option = 0;
    do
    {
        printf("\n\n ********* Main Menu **********");
        printf("\n 1: Enter the 1st polynomial");
        printf("\n 2: Display the 1st polynomial");

        printf("\n 3: Enter the 2nd polynomial");
        printf("\n 4: Display the 2nd polynomial");

        printf("\n 5: Add the polynomial");
        printf("\n 6: Display the result");

        printf("\n 7: Subtract the polynomial");
        printf("\n 8: Display the result");

        printf("\n 9: EXIT");
        printf("\n Enter your option : ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            s1 = create_poly(s1);
            break;
        case 2:
            s1 = display_poly(s1);
            break;
        case 3:
            s2 = create_poly(s2);
            break;
        case 4:
            s2 = display_poly(s2);
            break;
        case 5:
            s3 = add_poly(s1, s2, s3);
            break;
        case 6:
            s3 = display_poly(s3);
            break;
        case 7:
            s4 = sub_poly(s1, s2, s4);
            break;
        case 8:
            s4 = display_poly(s4);
            break;
        }

    } while (9 != option);
    return 0;
}
#endif
