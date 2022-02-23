#include <stdio.h>

int main(int argc, char *argv[])
{
    // Static lenght array
    char string[] = "Hello world";
    printf("%s %c %s %s %s\n", string, string[0], string, &string[0], string);

    char *pp = NULL;
    pp = string;
    for (unsigned int i = 0; i < sizeof (string) / sizeof (string[0]); i++) {
        printf("Value = %c, Address = %p\n", *pp, pp);
        pp = pp + 1;
    }

    int *p = NULL;
    int arr[] = {200,600,900,2000,3000};
    p = arr;
    for (unsigned int i = 0; i < sizeof (arr) / sizeof (arr[0]); i++) {
        printf("Value = %d, Address = %p\n", *p, p);
        p = p + 1;
    }

    return 0;
}
