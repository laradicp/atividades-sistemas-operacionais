#ifndef LRU_H
#define LRU_H

#include "PagesList.h"

using namespace std;

class LRU
{
    private:
        int faults;
        vector<pair<int, int>> frames; // <page, lastUsed>

        int findPage(int page);

    public:
        LRU(PagesList PagesList);
        void print();
};

#endif
