#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
  int pid = fork();    //it creates a process
  int  child_pid ; // It's the pid of the child process
  if (pid < 0){ 
    printf("fork failed");	 //fork fails
    exit(0);
    }
  if (pid == 0) {	//child process
        child_pid = getpid();
        printf("\n I am the child with pid %d and my parent has ppid %d\n",child_pid, getppid());
        sleep(1);
        printf("\n Exitting child\n"); 
  } 
 
  else if (pid> 0) { //parent process
// non negative number == pid >0
    
    printf("\n I am the parent and my id is %d \n",getpid());

    sleep(25); // parent sleeps for 25 seconds
    printf("\n Exitting Parent\n");
  }
  
}

