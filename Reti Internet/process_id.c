#include <stdio.h>
#include <unistd.h>

int main ()
{

 printf ("The process id is %d\n", (int) getpid ());
 //printf ("The parent process id is %d\n", (int) getppid ());

 pid_t pid = fork();
 printf("main program id is %d\n", (int) getpid());

 if (pid == 0){
 // fork is called in parent, so in child process pid is 0 
 printf("Child process\n");
 printf("C: child ID is %d\n", (int) getpid());
 } 
 else {
 // parent called fork, so pid is the ID of the child
 printf("Parent process\n");
 printf("P: parent ID is %d\n", (int) getpid());
 printf("P: child ID is %d\n", (int) pid); 
 } 
 sleep(1); // to properly exit from prompt
 return 0;

}
