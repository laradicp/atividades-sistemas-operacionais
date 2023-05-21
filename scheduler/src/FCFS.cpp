#include "FCFS.h"

#include <iostream>

FCFS::FCFS(ProcessList processList)
{
    // processList is sorted by arrival time, therefore we can just simulate the processes in order
    int currentTime = 0;
    avgCompletionTime = 0;
    avgResponseTime = 0;
    avgWaitingTime = 0;

    if(processList.getNumProcesses() == 0)
    {
        return;
    }

    for(int i = 0; i < processList.getNumProcesses(); i++)
    {
        currentTime = max(currentTime, processList.getArrivalTime(i));

        avgCompletionTime += currentTime + processList.getDuration(i) - processList.getArrivalTime(i);
        avgResponseTime += currentTime - processList.getArrivalTime(i);
        // no preemption, so waiting time is equal to response time
        avgWaitingTime += currentTime - processList.getArrivalTime(i);

        currentTime += processList.getDuration(i);
    }

    avgCompletionTime /= processList.getNumProcesses();
    avgResponseTime /= processList.getNumProcesses();
    avgWaitingTime /= processList.getNumProcesses();
}

void FCFS::print()
{
    printf("FCFS %.1f %.1f %.1f\n", avgCompletionTime, avgResponseTime, avgWaitingTime);
}
