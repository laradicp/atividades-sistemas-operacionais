#include <iostream>
#include "PagesList.h"
#include "FIFO.h"
#include "OTM.h"
#include "LRU.h"

using namespace std;

int main(int argc, char** argv)
{
    // check if the user provided a path to a file
    if (argc != 2)
    {
        cout << "Usage: ./main <path to file>" << endl;
        return 1;
    }

    PagesList pagesList(argv[1]);
    FIFO fifo(pagesList);
    OTM otm(pagesList);
    LRU lru(pagesList);

    fifo.print();
    otm.print();
    lru.print();
    
    return 0;
}
