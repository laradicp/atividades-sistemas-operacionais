#ifndef PAGES_LIST_H
#define PAGES_LIST_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class PagesList
{
    private:
        int numFrames;
        vector<int> pages;

    public:
        PagesList(string path);

        int getNumFrames();
        int getPage(int i);
        int getNumPages();
};

#endif
