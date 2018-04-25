# Code for task 1.4
# supporting implicitly calling exit system call from user programs
# by injecting the exit system call forcefully

#include "syscall.h"
#include "traps.h"

        .text
.globl injectexit
.globl start_injectexit
start_injectexit:
        pushl   %eax
        movl $SYS_exit, %eax
        int $64
.globl end_injectexit
end_injectexit:
        ret
