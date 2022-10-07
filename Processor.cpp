#include "Processor.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace Lrmakode;
using namespace std;
RETURN_CODES Processor::initFromFile(std::string pstrFilePath)
{
    mFileWordList = std::move(Util::getListOfWordFromFile(pstrFilePath));
    return RETURN_CODES::SUCESS;
}

RETURN_CODES Processor::saveToFile(std::string pstrOutPutFile)
{
    ofstream outFile(pstrOutPutFile);
    int i = 0;
    for(auto var: *mFileWordList)
    {
        outFile << var << " ";
        if(i%15 == 0)
            outFile << endl;
    }
    outFile.close();
    return  RETURN_CODES::FAILED;
}

RETURN_CODES Processor::insertWordsFromMap(wordMapUPtr pUptr)
{
    cout<<mFileWordList->size()<<endl;
    srand((unsigned int)time(0));
    for(auto item: *pUptr)
    {
        for(int i=0; i < item.second ;i++)
        {
            int index = rand()%(mFileWordList->size()-1);
            fileWordListIterator it = mFileWordList->begin(); 
            advance(it, index);
            mFileWordList->insert(it,item.first); 
        }
    }
    cout<<mFileWordList->size()<<endl;
    return RETURN_CODES::SUCESS;
}

RETURN_CODES Processor::print()
{
    for(auto item: *mFileWordList)
    {
        cout<<item<<endl;
    }
    return RETURN_CODES::SUCESS;
}
