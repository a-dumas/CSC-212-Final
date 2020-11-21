#include "StringSearch.h"

//fills an array with a longest possible prefix/ suffix for a given pattern
void Search::getLPS(std::vector<int> &lpsVec, std::string wordInText){

    int i = 0;  //to keep track of the positions of lpsVec and compare them
    int j = 1;

    lpsVec[0] = 0;
    while(j != lpsVec.size()){
        if(wordInText[i] != wordInText[j]){
            if(i == 0){
                lpsVec[j] = 0;
                j++;
            }
            else{
                i = lpsVec[i - 1];
            }
        }

        else if(wordInText[i] == wordInText[j]){
            lpsVec[j] = i + 1;
            i++;
            j++;
        }
    }
    return;
}
std::vector<int> Search::KMPHelper(std::string wordInText, std::string text){
    std::vector<int> lpsVec(wordInText.size());

    std::vector<int>positions;

    getLPS(lpsVec,wordInText);

    int i = 0;      //index i of text
    int j = 0;      //index j of wordInText

    KMP(wordInText,text,i,j,positions,lpsVec);
    return positions;
}
void Search::KMP(std::string wordInText, std::string text,int i, int j, std::vector<int> &positions, std::vector<int> lpsVec){
    if(i == text.size()){
        return;
    }
    if(text[i] == wordInText[j]){
        i++;
        j++;
        if(j == wordInText.size()){
            positions.push_back(i - j);
            std::cout<<(i - j)<<" ";
            j = 0;
        }
        KMP(wordInText,text,i,j,positions,lpsVec);
    }
    else if(text[i] != wordInText[j]){
        if(lpsVec[j - 1] == 0){
            KMP(wordInText,text,i + 1,0,positions,lpsVec);
        }
        else{
            KMP(wordInText,text,i,lpsVec[j - 1],positions,lpsVec);
        }

    }
}