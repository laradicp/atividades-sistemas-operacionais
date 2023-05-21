#ifndef OTM_H
#define OTM_H

#include "PagesList.h"

using namespace std;

class OTM
{
    private:
        int faults;
        vector<pair<int, int>> frames; // <page, nextUsed>

        int findPage(int page);

    public:
        OTM(PagesList pagesList);
        void print();
};

#endif
