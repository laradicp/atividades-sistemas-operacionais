#include "SJF.h"

#include <iostream>
#include <queue>

SJF::SJF(ProcessList processList)
{
    priority_queue<pair<int, int>> minDurationIdx; // first is -duration, second is corresponding idx
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
        while(!minDurationIdx.empty() && currentTime < processList.getArrivalTime(i))
        {
            int idx = minDurationIdx.top().second;
            minDurationIdx.pop();

            currentTime = max(currentTime, processList.getArrivalTime(idx));

            avgCompletionTime += currentTime + processList.getDuration(idx) - processList.getArrivalTime(idx);
            avgResponseTime += currentTime - processList.getArrivalTime(idx);
            // no preemption, so waiting time is equal to response time
            avgWaitingTime += currentTime - processList.getArrivalTime(idx);

            currentTime += processList.getDuration(idx);
        }

        minDurationIdx.push(make_pair(-processList.getDuration(i), i));
    }

    while(!minDurationIdx.empty())
    {
        int idx = minDurationIdx.top().second;
        minDurationIdx.pop();

        currentTime = max(currentTime, processList.getArrivalTime(idx));

        avgCompletionTime += currentTime + processList.getDuration(idx) - processList.getArrivalTime(idx);
        avgResponseTime += currentTime - processList.getArrivalTime(idx);
        // no preemption, so waiting time is equal to response time
        avgWaitingTime += currentTime - processList.getArrivalTime(idx);

        currentTime += processList.getDuration(idx);
    }

    avgCompletionTime /= processList.getNumProcesses();
    avgResponseTime /= processList.getNumProcesses();
    avgWaitingTime /= processList.getNumProcesses();
}

void SJF::print()
{
    printf("SJF %.1f %.1f %.1f\n", avgCompletionTime, avgResponseTime, avgWaitingTime);
}
