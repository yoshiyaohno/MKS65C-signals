#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

static void sighandler(int signo)
{
    if( signo == SIGSEGV ) {
        printf("you died\n");
    }
    else if( signo == SIGUSR1 ) {
        printf("haha pp %d\n", getppid());
    }
    else if( signo == SIGINT ) {
        int log;
        if( log = open("fail.log", O_CREAT ^ O_APPEND ^ O_WRONLY, 0755)
                == -1 ) {
            // error opening log file
        }
        write( log, strerror(errno), 256 );
    }
}

int main()
{
    signal(SIGSEGV, sighandler);
    signal(SIGUSR1, sighandler);
    signal(SIGINT,  sighandler);
    while("yahoo") {
        printf("hello it is I, %d\n", getpid());
        sleep(1);
    }
    return 0;
}
