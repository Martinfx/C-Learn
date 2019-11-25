#include <stdio.h>

#define UNW_LOCAL_ONLY
#include "/usr/local/include/libunwind.h"

#include <stdlib.h>
#include <execinfo.h>
#include <unistd.h>

/*
 * Simple implementation backtrace with execinfo library
 * and unwind library.
 */
void backtrace_execinfo() {
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

void backtrace_unwind() {
    unw_cursor_t cursor;
    unw_context_t context;

    if(unw_getcontext(&context) < 0) {
        perror("Cannot getcontext!");
        exit(EXIT_FAILURE);
    }

    if(unw_init_local(&cursor, &context) < 0) {
        perror("Cannot initialize local unwiding library!");
        exit(EXIT_FAILURE);
    }

    while (unw_step(&cursor) > 0) {
        unw_word_t offset, pc;
        char sym[4096];
        if(unw_get_reg(&cursor, UNW_REG_IP, &pc)) {
            perror("Cannot read program counter");
            exit(EXIT_FAILURE);
        }

        printf("0x%lx: ", pc);

        if (unw_get_proc_name(&cursor, sym, sizeof(sym), &offset) == 0) {
            printf("(%s+0x%lx)\n", sym, offset);
        } else {
            printf("-- no symbol name found\n");
        }
    }
}

void foo() {
    backtrace_execinfo();
    backtrace_unwind();

    int *f = (int*) - 1;
    printf("%d \n", *f);
}

int main() {
    foo();

    return 0;
}
