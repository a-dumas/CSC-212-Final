#include "StringSearch.h"

// void Search::preprocess(int *shift, int* pos, char *word, int size){

//     word[size] = size + 1;

//     while(size > 0){
//         while(pos + 1 <= size && word[size-1] != word[pos-1]){

//             if(shift[pos] == 0)
//                 shift[pos] = pos-size

//             pos = word[pos]
//         }

//         size--;
//         pos--;
//         word[size] = pos;
//     }
// }

void Search::badChar(std::string text, int size, int badChar[table]){
     
    int table = 256; //represents ascii table
    int i;

    for(i = 0; i< table ; i++)
        badChar[i] = -1;

    for(i = 0; i < size; i++)
        badChar[(int) text[i]] = i
}

// void goodChar(){

//     //do the stuff
// }

void Search::BM(std::string wordInText, std::string text){
    
    std::vector<int>positions;
    int badChar[256];
    int shift = 0;
    
    badChar(wordInText, text.size, badchar)
    
    while(shift < = (text.size() - wordInText.size()){
        int j = wordInText.size() -1;
        
        while(j > 0 && wordInText[j] == text[size + j]){
            j--
        }
        
        if(j < 0 ){
            positions.push_back(shift)
        }
        
    }
}