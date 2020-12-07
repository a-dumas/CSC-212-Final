#include <iostream> //may not need
#include <string>
#include <vector>

class Search{

    private:

        std::string wordInText; //(pattern)
        std::string text;

    public:
        std::vector<int> KMP(std::string wordInText, std::string text);
        void KMPRecursive(std::string wordInText, std::string text, int i, int j, std::vector<int> &positions, std::vector<int> lpsVec);
        void getLPS(std::vector<int> &lpsVec, std::string wordInText);
        void BM(std::string wordInText, std::string text);
        int badChar(int j, char temp, std::string WordInText);
        int goodSuffix(int j, std::string& wordInText);

};