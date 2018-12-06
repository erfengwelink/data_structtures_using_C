#include <stdio.h>
//#include <conio.h>

#if 0
int main()
{
    int i, n, arr[20];
    //clrscr();
    printf("\n Enter the number of elements in the array : ");
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        printf("\n arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    printf("\n the elements are ");
    for(i=0; i<n; i++)
        printf("\t %d", arr[i]);
    return 0;
}
#endif

#if 0

int main()
{
    int i, n, num, pos, arr[5];
    //clrscr();
    printf("\n Enter the number of elements in the array : ");
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        printf("\n arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    printf("\n Enter the number to be inserted : ");
    scanf("%d", &pos);
    for(i = n-1; n>=pos; n--)
        arr[i+1] = arr[i];
    arr[pos] = num;
    n = n + 1;


    printf("\n the elements after insertion of %d are ", num);
    for(i=0; i<n; i++)
        printf("\t %d", arr[i]);
    return 0;
}

#endif

#if 1

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int *ptr1, *ptr2;
    ptr1 = arr;
    ptr2 = arr + 2;
    printf("%ld", ptr2 - ptr1);
    return 0;
}

#endif
