#include <stdio.h>

#define LIST_ELEMENT(type) \
    struct \
    { \
        void *pvNext; \
        type value; \
    }

#define ASSERT_POINTER_TO_LIST_ELEMENT(type, pElement) \
    do { \
        (void)(&(pElement)->value  == (type *)&(pElement)->value); \
        (void)(sizeof(*(pElement)) == sizeof(LIST_ELEMENT(type))); \
    } while(0)

#define SET_POINTER_TO_LIST_ELEMENT(type, pDest, pSource) \
    do { \
        ASSERT_POINTER_TO_LIST_ELEMENT(type, pSource); \
        ASSERT_POINTER_TO_LIST_ELEMENT(type, pDest); \
        void **pvDest = (void **)&(pDest); \
        *pvDest = ((void *)(pSource)); \
    } while(0)

#define LINK_LIST_ELEMENT(type, pDest, pSource) \
    do { \
        ASSERT_POINTER_TO_LIST_ELEMENT(type, pSource); \
        ASSERT_POINTER_TO_LIST_ELEMENT(type, pDest); \
        (pDest)->pvNext = ((void *)(pSource)); \
    } while(0)

#define TERMINATE_LIST_AT_ELEMENT(type, pDest) \
    do { \
        ASSERT_POINTER_TO_LIST_ELEMENT(type, pDest); \
        (pDest)->pvNext = NULL; \
    } while(0)

#define ADVANCE_POINTER_TO_LIST_ELEMENT(type, pElement) \
    do { \
        ASSERT_POINTER_TO_LIST_ELEMENT(type, pElement); \
        void **pvElement = (void **)&(pElement); \
        *pvElement = (pElement)->pvNext; \
    } while(0)

typedef struct { int a; int b; } mytype;

int main(int argc, char **argv)
{
    LIST_ELEMENT(mytype) el1;
    LIST_ELEMENT(mytype) el2;
    LIST_ELEMENT(mytype) *pEl = NULL;
    el1.value.a = 1;
    el1.value.b = 2;
    el2.value.a = 3;
    el2.value.b = 4;
    LINK_LIST_ELEMENT(mytype, &el1, &el2);
    TERMINATE_LIST_AT_ELEMENT(mytype, &el2);
    printf("Testing.\n");
    SET_POINTER_TO_LIST_ELEMENT(mytype, pEl, &el1);
    if (pEl->value.a != 1)
        printf("pEl->value.a != 1: %d.\n", pEl->value.a);
    ADVANCE_POINTER_TO_LIST_ELEMENT(mytype, pEl);
    if (pEl->value.a != 3)
        printf("pEl->value.a != 3: %d.\n", pEl->value.a);
    ADVANCE_POINTER_TO_LIST_ELEMENT(mytype, pEl);
    if (pEl != NULL)
        printf("pEl != NULL.\n");
    printf("Done.\n");

    //race_thread_code();

    return 0;
}


// race thread source code
// -fsanitize=threads
#if defined(__has_feature)
#  if __has_feature(thread_sanitizer)
// code that builds only under ThreadSanitizer
//    printf("jaj");
#  endif
#endif

#include <threads.h>
int Global;
void *Thread1(void *x) {
  Global = 42;
 return x;
}

int race_thread_code() {
  thrd_t t;
  thrd_create(&t, Thread1, NULL);
  Global = 43;
  thrd_join(t, NULL);
  return Global;
}

