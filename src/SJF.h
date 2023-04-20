#ifndef SJF_H
#define SJF_H

#include "ProcessList.h"

using namespace std;

class SJF
{
    private:
        float avgCompletionTime;
        float avgResponseTime;
        float avgWaitingTime;

    public:
        SJF(ProcessList processList);
        void print();
};

#endif
