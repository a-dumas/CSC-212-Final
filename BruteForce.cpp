#include "StringSearch.h"

std::vector<int> Search::BF(std::string wordInText, std::string text){
    std::vector<int> positions;

    int len_word = wordInText.length();
    int len_text = text.length();
    int i = 0;

    while(i <= len_text - len_word){
        int j;

        // for a current index of i, check if the pattern matches
        for(j = 0; j < len_word; j++){
            if(text[i + j] != wordInText[j]){
                break;
            }
        }

        if(j == len_word){ //if we have a continuous match
            positions.push_back(i);
        }
        else if(j == 0){
            i += 1;
        }
        else{
            i += j; //shifts pattern by j
        }
    }
    return positions;
}
