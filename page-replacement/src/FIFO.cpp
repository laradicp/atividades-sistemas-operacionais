#include "FIFO.h"

FIFO::FIFO(PagesList pagesList)
{
    faults = 0;
    frames.resize(pagesList.getNumFrames(), -1);

    for(int i = 0; i < pagesList.getNumPages(); i++)
    {
        if(isFault(pagesList.getPage(i)))
        {
            frames[faults++ % frames.size()] = pagesList.getPage(i);
        }
    }
}

bool FIFO::isFault(int page)
{
    for(unsigned int i = 0; i < frames.size(); i++)
    {
        if(frames[i] == page)
        {
            return false;
        }
    }

    return true;
}

void FIFO::print()
{
    cout << "FIFO " << faults << endl;
}
