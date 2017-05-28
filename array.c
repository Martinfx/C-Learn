#include <stdio.h>

int main(int argc, char *argv[])
{
    // Static lenght array
    char string[0] = "Hello world";
    printf("%s %c %d %d %d\n", string, string[0], &string, &string[0], string);


    int *p = NULL;
    int arr[] = {200,600,900,2000};
    p = arr;
    for (unsigned int i = 0; i < sizeof (arr) / sizeof (arr[0]); i++)
    {
        printf("Value = %d, Address = %p\n", *p, p);
        p = p + 1;
    }

       return 0;
}
