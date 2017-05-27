#include <stdio.h>

int main(int argc, char *argv[])
{
    // Static lenght array
    char str1[] = "Hello world";
    printf("%s %c %d %d %d\n", str1, str1[0], &str1, &str1[0], str1);


    int *p = NULL;
    int a[] = {200,600,900,2000};
    p = a;
    for (unsigned int i = 0; i < sizeof (a) / sizeof (a[0]); i++)
    {
        printf("Value = %d, Address = %p\n", *p, p);
        p = p + 1;
    }

       return 0;
}
