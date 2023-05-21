#include "ProcessList.h"

#include <fstream>
#include <algorithm>

bool ProcessList::sortByFirst(const pair<int,int> &p1, const pair<int,int> &p2)
{
    return (p1.first < p2.first);
}

ProcessList::ProcessList(string path)
{
    // read path which is a file with arrival times and durations of processes, the file is formatted as follows:
    // 0 20
    // 0 10
    // 4 6
    // 4 8
    // where the first number is the arrival time and the second number is the duration, and each line is a process
    // fill arrivalTimesNDurations vector with the arrival times and durations of the processes
    ifstream file;
    file.open(path);
    int arrivalTime, duration;
    numProcesses = 0;
    while (file >> arrivalTime >> duration)
    {
        numProcesses++;
        arrivalTimesNDurations.push_back(make_pair(arrivalTime, duration));
    }
    file.close();

    sort(arrivalTimesNDurations.begin(), arrivalTimesNDurations.end(), sortByFirst);
}

int ProcessList::getNumProcesses()
{
    return numProcesses;
}

int ProcessList::getArrivalTime(int process)
{
    return arrivalTimesNDurations[process].first;
}

int ProcessList::getDuration(int process)
{
    return arrivalTimesNDurations[process].second;
}
