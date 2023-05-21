#include "RR.h"

#include <iostream>
#include <queue>
#include <list>

#define QUANTUM 2

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

    if(processList.getNumProcesses() == 0)
    {
        return;
    }
    
    for(int i = 0; i < processList.getNumProcesses(); i++)
    {
        remainingTime.push_back(processList.getDuration(i));
    }

    while(incompleteProcesses > 0)
    {
        if(processQueue.empty())
        {
            bool processAvailable = false;
            for(int i = 0; i < processList.getNumProcesses(); i++)
            {
                if((!scheduled[i])&&(processList.getArrivalTime(i) <= currentTime))
                {
                    processQueue.push(i);
                    scheduled[i] = true;
                    processAvailable = true;
                    break;
                }
            }

            // if no processes are available, increment time
            if(!processAvailable)
            {
                for(int i = 0; i < processList.getNumProcesses(); i++)
                {
                    if(!scheduled[i])
                    {
                        currentTime = processList.getArrivalTime(i);
                        break;
                    }
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
