#include <iostream> //may not need
#include <string>
#include <vector>

class Search{

    private:

        std::string wordInText;
        std::string text;//maybe make this a vector

    public:
        std::vector<int> KMP(std::string wordInText, std::string text);
        void KMPRecursive(std::string wordInText, std::string text, int i, int j, std::vector<int> &positions, std::vector<int> lpsVec);
        void getLPS(std::vector<int> &lpsVec, std::string wordInText);
        std::vector<int> BM(std::string wordInText, std::string text);
        void badChar(std::string text, int size, int badChar[table]);
};