#include <stdio.h>

#if 1

typedef struct student
{
    union{
        char name[20];
        int roll_no;
    };
    int marks;
}st_t;


int main()
{
    st_t stud;
    char choice;
    printf("\n You can enter the name or roll number of the student");
    printf("\n Do you want to enter the name? (Y or N):");
    gets(&choice);

    if(choice == 'y' || choice == 'Y')
    {
        printf("\n Enter the name :");
        gets(stud.name);
    }else{
        printf("\n Enter the roll number: ");
        scanf("%d", &stud.roll_no);
    } 
    printf("\n Enter the marks: ");
    scanf("%d", &stud.marks);
    if(choice == 'y' || choice == 'Y')
    {
        printf("\n name: %s ", stud.name);
    }else{
        printf("\n ROLL number: %d ", stud.roll_no);
    }
    printf("\n Marks: %d", stud.marks);
    return 0;
}

#endif

