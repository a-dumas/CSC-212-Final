#include <iostream> //may not need
#include <string>
#include <vector>

class Search{

    private:

        std::string wordInText;
        std::string text;

    public:
        std::vector<int> KMP(std::string wordInText, std::string text);
        void getLPS(std::vector<int> &lpsVec, std::string wordInText);
        std::vector<int> BM(std::string wordInText, std::string text);
};