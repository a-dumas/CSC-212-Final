#include"StringSearch.h"

//fills an array with a longest possible prefix/ suffix for a given pattern
void Search::getLPS(std::vector<int> &lpsVec, std::string wordInText){

    int i = 0;  //to keep track of the positions of lpsVec and compare them
    int j = 1;

    lpsVec[0] = 0;
    //std::cout<<lpsVec.size();
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

std::vector<int> Search::KMP(std::string wordInText, std::string text){

    std::vector<int> lpsVec(wordInText.size());

    std::vector<int>positions;

    getLPS(lpsVec,wordInText);

    return lpsVec;


    //set index i for text iteration
    //set index j for pattern iteration

    //while text iteration < length of text
        //if the pattern[j] == text[i]
            //increase both iters

        //if pattern[j] is equal to the length of text
            //match found
            // set j to last lps element

        //else if there's a mismatch
            //if j isn't 0
                //set j to last lps element
            //else
                //increment i


}