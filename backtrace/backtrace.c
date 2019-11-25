#include <stdio.h>
#include <stdlib.h>
#include <execinfo.h>
#include <unistd.h>
#include <dlfcn.h>

void backtrace__() {
    size_t size_backtrace = 20;
    size_t frames = 0;

    void *buffer[20] = {0};
    char **address = NULL;

    frames = backtrace(buffer, size_backtrace);
    printf("count of address: %zu \n", frames);

    address = backtrace_symbols(buffer, frames);
    if (!address) {
        perror("Cannot found backtrace symbols!");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < frames; i++) {
        printf("backtrace: %s\n", address[i]);
    }

    free(address);
}

void foo() {
    backtrace__();

    int *f = (int*) - 1;
    printf("%d \n", *f);
}

int main() {
    foo();

    return 0;
}
