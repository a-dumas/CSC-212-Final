#include "StringSearch.h"

int main(){
    std::string text = "this is a this test this";
    std::string word = "this";

    Search obj;
    std::vector<int> ah = obj.KMP(word,text);
    std::cout<<ah[0]<<"\n";
}