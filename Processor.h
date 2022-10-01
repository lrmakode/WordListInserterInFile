#include <memory>
#include <list>
#include <string>
#include "RETURN_CODES.h"
namespace Lrmakode{
    using namespace std;
    typedef list<string> fileWordList;
    typedef unique_ptr<fileWordList> fileWordListUPtr;
    class Processor
    {
        public:
            Processor()
            {
                fileWordListUPtr lTmp(new fileWordList);
                mFileWordList = move(lTmp);
            }
            RETURN_CODES initFromFile(std::string pstrFilePath);
            RETURN_CODES saveToFile(std::string pstrOutPutFile);
            virtual ~Processor(){}
        private:
            fileWordListUPtr mFileWordList;
    };

}
