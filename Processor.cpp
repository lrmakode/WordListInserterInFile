#include "Processor.h"
#include <iostream>
#include <cstdlib>
using namespace Lrmakode;
using namespace std;
RETURN_CODES Processor::initFromFile(std::string pstrFilePath)
{
    mFileWordList = std::move(Util::getListOfWordFromFile(pstrFilePath));
    return RETURN_CODES::SUCESS;
}

RETURN_CODES Processor::saveToFile(std::string pstrOutPutFile)
{
    for(auto var: *mFileWordList)
    {
        cout<<var<<" ";
    }
    return  RETURN_CODES::FAILED;
}

RETURN_CODES Processor::insertWordsFromMap(wordMapUPtr pUptr)
{
    cout<<mFileWordList->size()<<endl;
    srand(time(0));
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
}

RETURN_CODES Processor::print()
{
    for(auto item: *mFileWordList)
    {
        cout<<item<<endl;
    }

}
