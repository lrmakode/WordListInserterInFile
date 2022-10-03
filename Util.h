#pragma once
#include <list>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
//#include <bits/stdc++.h>

#include <iostream>
#include <map>
using namespace std;
typedef list<string> fileWordList;
typedef fileWordList::iterator fileWordListIterator;
typedef map<string,int> wordMap;
typedef unique_ptr<fileWordList> fileWordListUPtr;
typedef unique_ptr<wordMap> wordMapUPtr;
namespace Lrmakode
{
    class Util{
        public:
            static fileWordListUPtr getListOfWordFromFile(std::string& pstrFilePath)
            {
                fileWordListUPtr lTmp(new fileWordList);
                string word;
                fstream file;
                // opening file
                file.open(pstrFilePath.c_str());
                // extracting words from the file
                while (file >> word)
                {
                    lTmp->push_back(word);
                    //cout << word << endl;
                }
                return lTmp;
            }

            static wordMapUPtr getMapOfWordWithOuccrence(std::string pstrFilePath)
            {
                wordMapUPtr lTmp(new wordMap);
                string word;
                ifstream file;
                // opening file
                file.open(pstrFilePath.c_str());
                // extracting words from the file
                while (getline(file, word))
                {
                    stringstream ss(word);
                    vector<string> v;
                    while (ss.good()) 
                    {
                        string substr;
                        getline(ss, substr, ',');
                        v.push_back(substr);
                    }
                    lTmp->insert(pair<string,int>(v[0],stoi(v[1])));
                }
                return lTmp;
            }

            static void printMap(wordMapUPtr ptr)
            {
                for(auto a:*ptr)
                {
                    cout<<a.first<<" "<<a.second<<endl;
                }
            }
    };
}
