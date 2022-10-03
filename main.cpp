#include <iostream>
#include "Processor.h"
#include "Util.h"
using namespace std;
using namespace Lrmakode;
int main(int argc, char**argv)
{
    cout<<"Wordlist inserter :"<<endl;
    if(argc < 4)
    {
        cout<<"Usage:"<<argv[0]<<" <inputfile> <wordlistfilepath> <outputfile>"<<endl;
        return 0;
    }
    Lrmakode::Processor p;
    p.initFromFile(argv[1]);
    auto map = Util::getMapOfWordWithOuccrence(argv[2]);
    cout<<"WordList Size::" <<map->size()<<endl;
    //Util::printMap(std::move(map));
    p.insertWordsFromMap(std::move(map));
    p.saveToFile(argv[3]);
    //p.print();
    return 0;
}
