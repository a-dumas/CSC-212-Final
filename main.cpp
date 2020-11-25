#include "StringSearch.h"

int main(){
    std::string text = "this is a this thing this bye";
    std::string word = "bye";

    Search obj;
    std::vector<int> print = obj.KMPHelper(word,text);

    if(print.size() == 0){
        std::cout<<"'"<<word<<"' was not found in the text";
    }
    else if(print.size() == 1){
        std::cout<<"'"<<word<<"' was found in the text at index "<<print[0];
    }
    else{
        std::cout<<"'"<<word<<"' was found in the text at indexes ";
        for (int i = 0; i < print.size() - 1; i++) {
            std::cout<<print[i]<<", ";
        }
        std::cout<<"and "<<print[print.size() - 1];
    }
}