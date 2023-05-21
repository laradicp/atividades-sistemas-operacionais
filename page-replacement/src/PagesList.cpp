#include "PagesList.h"
#include <fstream>

PagesList::PagesList(string path)
{
    ifstream file(path);
    string line;

    getline(file, line);
    numFrames = stoi(line);

    if(numFrames < 1)
    {
        cout << "Invalid number of frames" << endl;
        exit(1);
    }

    while(getline(file, line))
    {
        pages.push_back(stoi(line));
    }
}

int PagesList::getNumFrames()
{
    return numFrames;
}

int PagesList::getPage(int i)
{
    return pages[i];
}

int PagesList::getNumPages()
{
    return pages.size();
}
