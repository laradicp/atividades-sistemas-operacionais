#ifndef FCFS_H
#define FCFS_H

#include "ProcessList.h"

using namespace std;

class FCFS
{
    private:
        float avgCompletionTime;
        float avgResponseTime;
        float avgWaitingTime;

    public:
        FCFS(ProcessList processList);
        void print();
};

#endif
