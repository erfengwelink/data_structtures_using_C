#include <stdio.h>
#include <conio.h>


int main()
{
    int i, n, arr[20];
    clrscr();
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