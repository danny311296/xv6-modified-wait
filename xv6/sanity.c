
#include "types.h"


#include "user.h"


int main(int argc, char *argv[])
{
    int pid_arr[20],exit_arr[20], pid, wtime_avg, run_avg, turn_around_time_avg;
    int creation_index = 0;

    while (creation_index < 20)
    {

        if ((pid = fork()) == 0){
            break;
        }
        pid_arr[creation_index] = pid;
        creation_index++;
    }


    if ( pid > 0 )
    {
        creation_index = 0;
        int wtime , rtime, turn_around_time;
        while ( creation_index < 20){
            pid_arr[creation_index] = wait_stat(&wtime,&rtime,&turn_around_time,&(exit_arr[creation_index]));
            printf(1, "pid index : %d \n", pid_arr[creation_index]);
            if (pid_arr[creation_index] == exit_arr[creation_index]) {
                printf(1, "child's waiting time : %d , running time: %d and turnaround time: %d \n", wtime, rtime,
                       turn_around_time);
            }
            wtime_avg = wtime_avg + wtime;
            run_avg = run_avg+rtime;
            turn_around_time_avg = turn_around_time_avg+turn_around_time;
            creation_index++;
        }
        printf(1," \n statistics: \n wait: %d , run %d and turn_around %d ", wtime_avg, run_avg, turn_around_time_avg);
        exit(0);
    }
    else {
        creation_index = 0;
        set_priority(creation_index % 3);
        while(creation_index < 500000000)
        {
            creation_index++;
        }
        exit(getpid());
    }
}