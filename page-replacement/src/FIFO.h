#ifndef FIFO_H
#define FIFO_H

#include "PagesList.h"

using namespace std;

class FIFO
{
    private:
        int faults;
        vector<int> frames;

        bool isFault(int page);

    public:
        FIFO(PagesList pagesList);
        void print();
};

#endif
