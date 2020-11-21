#include <iostream> //may not need
#include <string>
#include <vector>

class Search{

    private:

        std::string wordInText;
        std::string text;

    public:
        std::vector<int> KMPHelper(std::string wordInText, std::string text);
        void KMP(std::string wordInText, std::string text, int i, int j, std::vector<int> &positions, std::vector<int> lpsVec);
        void getLPS(std::vector<int> &lpsVec, std::string wordInText);
        std::vector<int> BM(std::string wordInText, std::string text);
};