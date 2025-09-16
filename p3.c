#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>


int main(int argc, char *argv[])
{
    printf("hello world (pid:%d)\n", (int) getpid());
    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
        printf("hello, I am child (pid:%d)\n", (int) getpid());
        char *myargs[3];
        myargs[0] = strdup("wc");   // program: "wc" (word count)
        myargs[1] = strdup("p3.c"); // argument: file to count
        myargs[2] = NULL;           // marks end of array

        //exec("/bin/ls");
        //Does nothing
      
        execl("/bin/ls",NULL);
        // returns the list of files in the directory
        
        //execle("/bin/ls",NULL);
        //does nothing
      
        //execlp("/bin/ls",NULL);
        // also returns the list of files in the directory

        //execv("/bin/ls",NULL);
        // also returns the list of files in the directory

        //execvp("/bin/ls",NULL);
        // also returns the list of files in the directory

        //execvpe("/bin/ls",NULL);
        //does nothing
        
        
      
        execvp(myargs[0], myargs);  // runs word count
        printf("this shouldn't print out");
    } else {
        // parent goes down this path (original process)
        int wc = wait(NULL);
        printf("hello, I am parent of %d (wc:%d) (pid:%d)\n",
	       rc, wc, (int) getpid());
    }
    return 0;
}
