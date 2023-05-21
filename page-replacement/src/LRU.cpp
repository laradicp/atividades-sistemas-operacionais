#include "LRU.h"

LRU::LRU(PagesList pagesList)
{
    faults = 0;
    frames.resize(pagesList.getNumFrames(), make_pair(-1, -1));

    for(int i = 0; i < pagesList.getNumPages(); i++)
    {
        int idx = findPage(pagesList.getPage(i));
        if(idx == -1)
        {
            faults++;
            
            idx = 0;
            int min = frames[0].second;

            for(unsigned int j = 1; j < frames.size(); j++)
            {
                if(frames[j].second < min)
                {
                    min = frames[j].second;
                    idx = j;
                }
            }

            frames[idx].first = pagesList.getPage(i);
            frames[idx].second = i;
        }
        else
        {
            frames[idx].second = i;
        }
    }
}

int LRU::findPage(int page)
{
    for(unsigned int j = 0; j < frames.size(); j++)
    {
        if(frames[j].first == page)
        {
            return j;
        }
    }

    return -1;
}

void LRU::print()
{
    cout << "LRU " << faults << endl;
}
