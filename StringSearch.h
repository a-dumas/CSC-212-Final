#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

class Search {

private:

    std::string wordInText; //(pattern)
    std::string text;
    void KMPRecursive(std::string wordInText, std::string text, int i, int j, std::vector<int>& positions, std::vector<int> lpsVec);
    void KMPLinear(std::string wordInText, std::string text, int i, int j, std::vector<int>& positions, std::vector<int> lpsVec);
    void getLPS(std::vector<int>& lpsVec, std::string wordInText);
    std::vector<int> goodSuffix(std::string wordInText, std::vector<int>& shiftTable, std::vector<int>& borderTable);
    std::vector<int> badChar(std::string wordInText);

public:
    std::vector<int> KMP(std::string wordInText, std::string text, std::string linearOrRecursive);
    std::vector<int> BM(std::string wordInText, std::string text);
};