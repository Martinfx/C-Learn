#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    time_t t;

    int status = 0;
    /*int *shared_ptr = NULL;
    int *r1 = NULL, *r2 = NULL;
    int shared_id = 0;

    // Shared memory segment
    shared_id = shmget(IPC_PRIVATE, 2 * sizeof(int), 0660);
    shared_ptr = (int*)shmat(shared_id, NULL, 0);

    r1 = shared_ptr;
    r2 = (shared_ptr + 1);

    // Move values to pointers
    *r1 = 0;
    *r2 = 0;*/

    pid = fork();
    if(pid == -1) {
        perror("Bad call fork() \n");
        exit(EXIT_FAILURE);
    }

    if(pid == 0) {
        printf("first child pid %d: \n", getpid());
    } else {
        do {
            pid = waitpid(pid, &status, WNOHANG);
            if(pid == -1) {
                printf("waitpid error, status: %d \n ", status);
            } else if (pid == 0) {
                time(&t);
                printf("child is still running at %s \n", ctime(&t));
                sleep(1);
            } else {
                if (WIFEXITED(status)) {
                    printf("child exited with status of %d\n", WEXITSTATUS(status));
                } else {
                    printf("child did not exit successfully \n");
                }
            }
        } while (pid == 0);
    }
    return 0;
}
