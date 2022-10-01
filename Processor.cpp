#include "Processor.h"
#include <iostream>
#include <fstream>
using namespace Lrmakode;
using namespace std;
RETURN_CODES Processor::initFromFile(std::string pstrFilePath)
{
    string word, t, q, filename;
    fstream file;
    // opening file
    file.open(pstrFilePath.c_str());
    // extracting words from the file
    while (file >> word)
    {
        mFileWordList->push_back(word);
        //cout << word << endl;
    }
    //cout<<"Size of List::"<<mFileWordList->size()<<endl;
    return RETURN_CODES::SUCESS;
}

RETURN_CODES Processor::saveToFile(std::string pstrOutPutFile)
{
    fstream file;
    file.open(pstrOutPutFile.c_str());
    for(auto var: *mFileWordList)
    {
        file << var;
        cout<<var<<" ";
    }
    file.close();
    return  RETURN_CODES::FAILED;
}
