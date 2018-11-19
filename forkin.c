#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>

int main() {
    srand( time NULL);
    printf("Hello, this is the parent speaking. I'm going to fork twice.\n");
    int f = fork();
    int f2 = 0;
    if (f) f2 = fork();
    int status;
    int r;
    if (!f) r = (rand() % 15) + 6;
    if (!f2) r = (rand() % 15) + 6;
    if (!f || !f2) {
        printf("Hello, I'm a child with pid %d.\n", getpid());
        sleep(r);
        printf("I'm child %d and I've just finished running!\n", getpid());
        return r;
    }
    int childpid = wait(&status);
    printf("The parent speaking - my child with pid %d was asleep for %d seconds.\n", childpid, WEXITSTATUS(status));
    return 0;
}
