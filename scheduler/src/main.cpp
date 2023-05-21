#include <iostream>
#include "ProcessList.h"
#include "FCFS.h"
#include "SJF.h"
#include "RR.h"

using namespace std;

int main(int argc, char** argv)
{
    // check if the user provided a path to a file
    if (argc != 2)
    {
        cout << "Usage: ./main <path to file>" << endl;
        return 1;
    }

    ProcessList processList(argv[1]);
    FCFS fcfs(processList);
    SJF sjf(processList);
    RR rr(processList);

    fcfs.print();
    sjf.print();
    rr.print();
    
    return 0;
}
