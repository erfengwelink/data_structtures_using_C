#include <stdio.h>

/**
 * write a program to read multiple lines of text and then count 
 * the number of characters, words, and lines in the text.
 * 
 * */
#if 1

static int prog()
{
    char str[100];
    int i=0, word_count = 1, line_count = 1, char_count = 1;

    printf("\n Enter a '*' to end");
    printf("\n **************");
    printf("\n Enter a text : ");
    scanf("%c", &str[i]);
    while(str[i] != '*')
    {
        i++;
        scanf("%c", &str[i]);
    }
    str[i] = '\0';
    i=0;
    while(str[i] != '\0')
    {
        if(str[i] == '\n' || i == 79)
            line_count++;
        if(str[i] == ' ' && str[i+1]!=' ')
            word_count++;
        char_count++;
        i++;
    }
    printf("\n The total count of words is : %d", word_count);
    printf("\n The total count of lines is : %d", line_count);
    printf("\n The total count of characters is : %d", char_count);
    return 0;
}
int main()
{
    prog();
    return 0;
}

#endif

