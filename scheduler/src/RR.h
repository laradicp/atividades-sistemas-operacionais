#ifndef RR_H
#define RR_H

#include "ProcessList.h"

using namespace std;

class RR
{
    private:
        float avgCompletionTime;
        float avgResponseTime;
        float avgWaitingTime;

    public:
        RR(ProcessList processList);
        void print();
};

#endif
