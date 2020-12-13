#include "StringSearch.h"

std::vector<int> Search::BF(std::string wordInText, std::string text){
    std::vector<int> positions;

    int len_word = wordInText.length();
    int len_text = text.length();

    // a loop that will shift the pattern by one
    for (int i = 0; i < len_text - len_word ; i++){
        int j;

        // for a current index of i, check if the pattern matches
        for(j = 0; j < len_word; j++){
            if(text[i + j] != wordInText[j]){
                break;
            }
        }

        if(j == len_word){
            positions.push_back(i);
        }
    }
    return positions;
}
