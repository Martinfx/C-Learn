#include <stdio.h>

int fibonacci(int i)
{
	if(i < 2)
	{
        return i;
	}
	else
	{
        return fibonacci(i - 1) + fibonacci(i - 2);
	}
}

int factorial(int i)
{
    if(i == 0)
    {
        return 1;
    }
    else
    {
        return i * factorial(i - 1);
    }
}

int main(int argc, char *argv[])
{
    printf("fibonacci is: %d \n", fibonacci(10));
    printf("factorial is: %d \n", factorial(2));

    return 0;
}
