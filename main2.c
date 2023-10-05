#include  <stdio.h>
#include  <sys/types.h>
#include <unistd.h> 
#include <time.h>
#include <stdlib.h> 
#include <sys/wait.h>

#define   MAX_COUNT  200

void  ChildProcess(void);                /* child process prototype  */
void  ParentProcess(void);               /* parent process prototype */

int main(void)
{
     pid_t  pid, pid2;
     int status1, status2;

     srand(time(NULL));

     pid = fork();
     if (pid == 0) 
          ChildProcess();
     else 
     {
      pid2 = fork(); // Create the second child process

      if (pid2 == 0)

      {
        ChildProcess(); 
      }

      else
      {
        //This is the parent process 
        waitpid (pid1, &status1, 0); 
        waitpid (pid2, &status2, 0);

        ParentProcess();
      }
     
     }
     return 0   
}

void  ChildProcess(void)
{
     int   i;
     pid_t pid = getpid();
     pid_t ppid = getppid(); 

     for (i = 1; i <= MAX_COUNT; i++)
     {
      printf ("Child Pid: %d is going to sleep!\n", pid);
      sleep(rand() % 10); 
      printf ("Child Pid: %d is awake! \nWhere is my Parent: %d?\n", pid, ppid);

     }

     exit (0);
     
}

void  ParentProcess(void)
{
     int status1, status2;

     printf ("Parent is waiting for children to complete...\n")

     wait(&status1);
     wait(&status2);

     printf ("Child Pid: %d has completed\n", getpaid());
     printf ("Child Pid: %d has completed\n", getpid());

     printf("*** Parent is done ***\n"); 

}