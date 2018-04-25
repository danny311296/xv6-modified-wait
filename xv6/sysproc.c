#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  int status;
  if (argint(0,&status) < 0)
    return -1;
  else
    exit(status);
  return 0;  // not reached
}

int
sys_wait(void)
{
  int *status;
  return argptr(0,(char **) &status, sizeof(status)) < 0 ? -1 : wait(status);
}

int
sys_set_priority(void)
{
  int priority;

  if (argint(FIRSTARG, &priority) < 0)
    return -1;

  return set_priority(priority);
}

int
sys_waitpid(void)
{
  int *status;
  int options;
  int pid;

  if (argint(FIRSTARG, &pid) < 0)
    return -1;
  if (argptr(SECONDARG,(char **) &status, sizeof(status)) < 0)
    return -1;
  if (argint(THIRDARG, &options) < 0)
    return -1;

  return waitpid(pid, status, options);
}

int
sys_wait_stat(void)
{
  int *wtime;
  int *iotime;
  int *rtime;
  int *status;

  if (argptr(FIRSTARG,(char **) &wtime, sizeof(wtime)) < 0)
    return -1;
  if (argptr(SECONDARG,(char **) &rtime, sizeof(rtime)) < 0)
    return -1;
  if (argptr(THIRDARG,(char **) &iotime, sizeof(iotime)) < 0)
    return -1;
  if (argptr(FOURTHARG,(char **) &status, sizeof(status)) < 0)
    return -1;

  return wait_stat(wtime,rtime,iotime,status);
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid, 15);
}

int
sys_getpid(void)
{
  return proc->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = proc->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;
  
  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(proc->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;
  
  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}