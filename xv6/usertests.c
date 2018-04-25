#include "param.h"
#include "types.h"
// #include "stat.h"
#include "user.h"
// #include "fs.h"
// #include "fcntl.h"
// #include "syscall.h"
// #include "traps.h"
// #include "memlayout.h"
// #include "proc.h"
int status;
int stdout = 1;
void
exitwait(void)
{
	int i, pid;
	int status;
	for(i = 0; i < 10; i++){
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
			else {
				  printf(1,"Status: %d\n",status);
				  if(WIFEXITED(status))
					printf(1,"WEXITSTATUS : %d\n",WEXITSTATUS(status));
			}
		} 
		else {
		  exit(29);
		}
	}
	printf(1, "exitwait ok\n");
}

// try to find any races between exit and wait
void exitkillwait(void) {
  int i, pid;
  
  for(i = 0; i < 1; i++){
	pid = fork();
	// if(pid == 0) {
		// printf(1, "PID: %d\n", getpid());
		// sleep(100);
		
		// exit(99);
	// }
	
	if(pid == 0) {
		// kill(getpid(), 100);
		printf(1, "PID: %d\n", getpid());
	}	
	
	if(pid < 0){
		printf(1, "fork failed\n");
		return;
	}
	if(pid){
		if(wait(&status) != pid){
			printf(1, "wait wrong pid\n");
			return;
		}
		else {
			  printf(1,"Status: %d\n",status);
			  if(WIFSIGNALED(status))
				printf(1,"WEXITSTATUS : %d\n",WTERMSIG(status));
		}
	}
	
	// if(pid){
		// int to_kill_pid = fork();
		
		// if(to_kill_pid) {
			// if(wait(&status) != pid){
				// printf(1, "wait wrong pid\n");
				// return;
			// }
				// printf(1,"Status: %d\n",status);
				// if(WIFSIGNALED(status))
					// printf(1,"WEXITSTATUS : %d\n",WTERMSIG(status));
		// }
		
		// if(to_kill_pid == 0) {
			// kill(pid, 15);
			// sleep(1000);
			// // exit(0);
		// }
		// // if(to_kill_pid) {
			// // wait(0);	
		// // }
	// } 
	
	
	else {
		exit((15 << 8) + 177);
	}
  }
  printf(1, "exitwait ok\n");
}


int main(int argc, char *argv[]) {
	printf(1, "usertests starting\n");

	exitwait();
	// exitkillwait();

	exit(0);
}
