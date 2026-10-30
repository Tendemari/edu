#include <stdio.h>

int main()
{
    int word_count = 0;
    int number_count = 0;
    
    char c_before = ' ';
    char c;

    while((c = getchar()) != '\n')
    {
        if (c >= '0' && c <= '9' && (c_before == ' ' || c_before == '\t'))
            ++number_count;
        if ((c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') && (c_before == ' ' || c_before == '\t'))
            ++word_count;
        c_before = c;
    }

    printf("Word count: %d\nNumber count: %d\n", word_count, number_count);

    return 0;
}