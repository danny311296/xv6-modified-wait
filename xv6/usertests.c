#include "param.h"
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "syscall.h"
#include "traps.h"
#include "memlayout.h"

char buf[8192];
char name[3];
char *echoargv[] = { "echo", "ALL", "TESTS", "PASSED", 0 };
int stdout = 1;

void
exitwait(void)
{
  int i, pid;
  int status;
  for(i = 0; i < 100; i++){
    pid = fork();
    if(pid < 0){
      printf(1, "fork failed\n");
      return;
    }
    if(pid){
      if(wait(&status) != pid){
        printf(1, "wait wrong pid\n");
        return;
      }
		else
		{
		      printf(1,"Status: %d\n",status);
		      if(WIFEXITED(status))
				printf(1,"WEXITSTATUS : %d\n",WEXITSTATUS(status));
		}
    } else {
      exit(29);
    }
  }
  printf(1, "exitwait ok\n");
}

int
main(int argc, char *argv[])
{
  printf(1, "usertests starting\n");

  if(open("usertests.ran", 0) >= 0){
    printf(1, "already ran user tests -- rebuild fs.img\n");
    exit(0);
  }
  close(open("usertests.ran", O_CREATE));

  // createdelete();
  // linkunlink();
  // concreate();
  // fourfiles();
  // sharedfd();

  // bigargtest();
  // bigwrite();
  // bigargtest();
  // bsstest();
  // sbrktest();
  // validatetest();

  // opentest();
  // writetest();
  // writetest1();
  // createtest();

  // openiputtest();
  // exitiputtest();
  // iputtest();

  // mem();
  // pipe1();
  // preempt();
  exitwait();

  // rmdot();
  // fourteen();
  // bigfile();
  // subdir();
  // linktest();
  // unlinkread();
  // dirfile();
  // iref();
  // forktest();
  // bigdir(); // slow
  // exectest();

  exit(0);
}
