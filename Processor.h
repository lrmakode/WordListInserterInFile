#pragma once
#include <memory>
#include "RETURN_CODES.h"
#include "Util.h"
using namespace std;
namespace Lrmakode{
    class Processor
    {
        public:
            Processor()
            {
                mFileWordList = nullptr;
            }
            RETURN_CODES initFromFile(std::string pstrFilePath);
            RETURN_CODES saveToFile(std::string pstrOutPutFile);
            RETURN_CODES insertWordsFromMap(wordMapUPtr pUptr);
            RETURN_CODES print();
            virtual ~Processor(){}
        private:
            fileWordListUPtr mFileWordList;
    };

}
