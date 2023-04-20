#include "RR.h"

#include <iostream>
#include <queue>
#include <list>

#define QUANTUM 2

RR::RR(ProcessList processList)
{
    list<pair<int, int>> idxRemainingTime; // first is idx, second is corresponding remaining time
    for(int i = 0; i < processList.getNumProcesses(); i++)
    {
        idxRemainingTime.push_back(make_pair(i, processList.getDuration(i)));
    }
    
    list<pair<int, int>>::iterator it = idxRemainingTime.begin();
    int currentTime = 0;
    avgCompletionTime = 0;
    avgResponseTime = 0;
    avgWaitingTime = 0;
    while(!idxRemainingTime.empty())
    {
        if(it == idxRemainingTime.end())
        {
            it = idxRemainingTime.begin();
        }
        
        if(currentTime < processList.getArrivalTime(it->first))
        {
            it++;
            continue;
        }

        if(it->second == processList.getDuration(it->first))
        {
            currentTime = max(currentTime, processList.getArrivalTime(it->first));
            avgResponseTime += currentTime - processList.getArrivalTime(it->first);
        }
        
        if(it->second > QUANTUM)
        {
            it->second -= QUANTUM;
            currentTime += QUANTUM;
        }
        else
        {
            currentTime += it->second;
            avgCompletionTime += currentTime - processList.getArrivalTime(it->first);
            avgWaitingTime += currentTime - processList.getArrivalTime(it->first) - processList.getDuration(it->first);

            list<pair<int, int>>::iterator aux = it;
            it++;
            idxRemainingTime.erase(aux);

            continue;
        }

        it++;
    }

    avgCompletionTime /= processList.getNumProcesses();
    avgResponseTime /= processList.getNumProcesses();
    avgWaitingTime /= processList.getNumProcesses();
}

void RR::print()
{
    printf("RR %.1f %.1f %.1f\n", avgCompletionTime, avgResponseTime, avgWaitingTime);
}
