#include <iostream>
#include <spawn.h>
#include <errno.h>
#include <sys/wait.h>

class PosixProcess {
public:

    PosixProcess(const std::string &path, char **argv, char **envp) :
        path(path), argv(argv), envp(envp) {

        posix_spawnattr_init(&attr);
        posix_spawn_file_actions_init(&actions);

    }

    PosixProcess(const std::string &path, char **argv, char **envp,
                 posix_spawnattr_t &attr, posix_spawn_file_actions_t &actions) :
    path(path), argv(argv), envp(envp), attr(attr), actions(actions) {

        posix_spawnattr_init(&attr);
        posix_spawn_file_actions_init(&actions);
    }

    void run() { posix_spawn(&pid, path.c_str(), &actions, &attr, argv, envp); }
    void processWait(int w) { wait(&w); }

private:

    pid_t pid;
    // Number of process
    // Atribution of process
    posix_spawnattr_t attr;
    // Information about process
    posix_spawn_file_actions_t actions;
    std::string path;
    char **argv;
    char **envp;
};


int main(int argc, char *argv[], char *envp[]) {

    int status = 0;
    PosixProcess child("/bin/sh", argv, envp);
    child.run();
    child.processWait(status);

    std::cout << "Status: " << status << std::endl;

    /*    pid_t pid;
    posix_spawnattr_t attr;
    posix_spawn_file_actions_t action;

    int status = 0;
    status = posix_spawnattr_init(&attr);
    if(status != 0) {
        perror("can't initialize spawnattr");
        exit(status);
    }

    status = posix_spawn_file_actions_init(&action);
    if(status != 0) {
        perror("can't initialize posix_spawn_file_actions_t");
        exit(status);
    }

    status = posix_spawn(&pid, "/bin/sh", &action, &attr, argv, envp);
    if(status != 0) {
        perror("posix_spawn");
        std::cout << "spawned PID: " << pid << std::endl;
        exit(status);
    }

    std::cout << "child pid: " << pid << std::endl;
    if (waitpid(pid, &status, 0) != -1) {
        std::cout << "Child exited with status: \n" <<  status << std::endl;
    } else {
        perror("waitpid");
    }
*/

    return 0;
}
