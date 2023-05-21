#ifndef PROCESS_LIST_H
#define PROCESS_LIST_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ProcessList
{
    private:
        int numProcesses;
        vector<pair<int, int>> arrivalTimesNDurations;

        static bool sortByFirst(const pair<int,int> &p1, const pair<int,int> &p2);

    public:
        ProcessList(string path);

        int getNumProcesses();
        int getArrivalTime(int process);
        int getDuration(int process);
};

#endif
