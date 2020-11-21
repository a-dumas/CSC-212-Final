#include "StringSearch.h"

int main(){
    std::string text = "AABAACAADAABAABA";
    std::string word = "AABA";

    Search obj;
    std::vector<int> print = obj.KMPHelper(word,text);
    // for (int i = 0; i < print.size(); i++) {
    //     std::cout<<print[i]<<" ";
    // }
}