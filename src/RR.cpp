#include "RR.h"

#include <iostream>
#include <queue>
#include <list>

#define QUANTUM 2

/*
    Brainstorm
    - if process arrives at same time as another process finishes executing in quantum,
        process arriving has greater priority
    - queue of processes
    - if the queue is empty, then time max(first arrival time, 0)
    - push processes with arrival time == current time into queue
    - pop process from queue, execute for quantum time
    - if process is not finished, check if there is no new arrivals, then push back
*/
RR::RR(ProcessList processList)
{
    queue<int> processQueue;
    vector<int> remainingTime;
    vector<bool> scheduled(processList.getNumProcesses(), false); // check if process has been included in queue
    int incompleteProcesses = processList.getNumProcesses();
    int currentTime = 0;
    avgCompletionTime = 0;
    avgResponseTime = 0;
    avgWaitingTime = 0;
    
    for(int i = 0; i < processList.getNumProcesses(); i++)
    {
        remainingTime.push_back(processList.getDuration(i));
    }

    while(incompleteProcesses > 0)
    {
        if(processQueue.empty())
        {
            for(int i = 0; i < processList.getNumProcesses(); i++)
            {
                if((!scheduled[i])&&(processList.getArrivalTime(i) <= currentTime))
                {
                    processQueue.push(i);
                    scheduled[i] = true;
                    break;
                }
            }
        }
        else
        {
            if(remainingTime[processQueue.front()] == processList.getDuration(processQueue.front()))
            {
                avgResponseTime += currentTime - processList.getArrivalTime(processQueue.front());
            }

            if(remainingTime[processQueue.front()] > QUANTUM)
            {
                currentTime += QUANTUM;
                remainingTime[processQueue.front()] -= QUANTUM;

                for(int i = processQueue.front() + 1; i < processList.getNumProcesses(); i++)
                {
                    if(!scheduled[i])
                    {
                        if(processList.getArrivalTime(i) <= currentTime)
                        {
                            processQueue.push(i);
                            scheduled[i] = true;
                        }
                        else
                        {
                            break;
                        }
                    }
                }

                processQueue.push(processQueue.front());
                processQueue.pop();
            }
            else
            {
                currentTime += remainingTime[processQueue.front()];
                avgCompletionTime += currentTime - processList.getArrivalTime(processQueue.front());
                avgWaitingTime += currentTime - processList.getArrivalTime(processQueue.front()) -
                    processList.getDuration(processQueue.front());

                remainingTime[processQueue.front()] = 0;
                processQueue.pop();

                incompleteProcesses--;
            }
        }

    }

    avgCompletionTime /= processList.getNumProcesses();
    avgResponseTime /= processList.getNumProcesses();
    avgWaitingTime /= processList.getNumProcesses();
}

void RR::print()
{
    printf("RR %.1f %.1f %.1f\n", avgCompletionTime, avgResponseTime, avgWaitingTime);
}
