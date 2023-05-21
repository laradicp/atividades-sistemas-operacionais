#include "OTM.h"

OTM::OTM(PagesList pagesList)
{
    faults = 0;
    frames.resize(pagesList.getNumFrames(), make_pair(-1, pagesList.getNumPages()));

    for(int i = 0; i < pagesList.getNumPages(); i++)
    {
        int idx = findPage(pagesList.getPage(i));
        if(idx == -1)
        {
            faults++;

            idx = 0;
            int max = frames[0].second;

            for(unsigned int j = 1; j < frames.size(); j++)
            {
                if(frames[j].second > max)
                {
                    max = frames[j].second;
                    idx = j;
                }
            }

            frames[idx].first = pagesList.getPage(i);
        }
        
        frames[idx].second = pagesList.getNumPages(); // if not used again
            
        // find the next time the page is used
        for(int j = i + 1; j < pagesList.getNumPages(); j++)
        {
            if(pagesList.getPage(j) == pagesList.getPage(i))
            {
                frames[idx].second = j;
                break;
            }
        }
    }
}

int OTM::findPage(int page)
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

void OTM::print()
{
    cout << "OTM " << faults << endl;
}
