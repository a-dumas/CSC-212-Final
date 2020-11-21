#include "StringSearch.h"

int main(){
    std::string text = "this is a this test this";
    std::string word = "this";

    Search obj;
    std::vector<int> print = obj.KMP(word,text);
    for (int i = 0; i < print.size(); i++) {
        std::cout<<print[i]<<" ";
    }
}