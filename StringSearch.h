#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <vector>
#include <cstdio>
#include <ctime>

class Search {

private:

<<<<<<< HEAD
        std::string wordInText; //(pattern)
        std::string text;
        void KMPRecursive(std::string wordInText, std::string text,int i, int j, std::vector<int> &positions, std::vector<int> lpsVec);
        void KMPIterative(std::string wordInText, std::string text,int i, int j, std::vector<int> &positions, std::vector<int> lpsVec);
        void getLPS(std::vector<int> &lpsVec, std::string wordInText);

    public:
        std::vector<int> KMP(std::string wordInText, std::string text,std::string iterativeOrRecursive);

        std::vector<int> BM(std::string wordInText, std::string text);
        int badChar(int j, char temp, std::string WordInText);
        int goodSuffix(int j, std::string& wordInText);
=======
    std::string wordInText; //(pattern)
    std::string text;
    void KMPRecursive(std::string wordInText, std::string text, int i, int j, std::vector<int>& positions, std::vector<int> lpsVec);
    void KMPLinear(std::string wordInText, std::string text, int i, int j, std::vector<int>& positions, std::vector<int> lpsVec);
    void getLPS(std::vector<int>& lpsVec, std::string wordInText);
    std::vector<int> goodSuffix(std::string wordInText, std::vector<int>& shiftTable, std::vector<int>& borderTable);
    std::vector<int> badChar(std::string wordInText);
>>>>>>> 55461c56f29482f7ab7490dbcf8fdc6a69261f85

public:
    std::vector<int> KMP(std::string wordInText, std::string text, std::string linearOrRecursive);
    std::vector<int> BM(std::string wordInText, std::string text);
};