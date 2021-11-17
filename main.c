#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
int main(){
  srand(time(NULL));
  int f;
  int g=1;
  int r1=(rand()%5)+1;
  int r2=(rand()%5)+1;
  int c;
  int status;
  printf("Time to have some children\n");
  f=fork();
  if(f){
    g=fork();
  }
  if(f&&g){
    c=wait(&status);
    printf("%d was asleep for %d seconds\n", c, WEXITSTATUS(status));
    c=wait(&status);
    printf("%d was asleep for %d seconds\n", c, WEXITSTATUS(status));
    printf("Time to go to bed\n");
  }
  if(!f){
    printf("%d\t",getpid());
    printf("%d\n",r1);
    sleep(r1);
    printf("Child 1 has woken up!\n");
    return r1;
  }
  if(!g){
    printf("%d\t",getpid());
    printf("%d\n",r2);
    sleep(r2);
    printf("Child 2 has woken up!\n");
    return r2;
  }
  return 0;
}
