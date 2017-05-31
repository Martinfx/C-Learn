#include <stdio.h>

#define size_array(x) (int)( sizeof(x) / sizeof(x[0]) )

char *words_data[3];			// some integers

int main(int argc, char **argv) {
    char *p_char;
    char **pp_char;

    printf ("multiple indirection example\n");

    words_data[0] = "zero";
    words_data[1] = "one";
    words_data[2] = "two";
    for (unsigned int i = 0; i < size_array(words_data); i++)
    {
        printf("%s\n", words_data[i]);
    }

     printf("\n Print chars in each string..... \n");
     pp_char = words_data;

     for (unsigned int i = 0; i < size_array(words_data); i++)
     {
        pp_char = words_data  + i;
        p_char = *pp_char;

        while (*p_char != 0)
        {
            printf("%c ", *p_char);
            p_char += 1;
        }
        printf("\n");
     }

    return 0;
}
