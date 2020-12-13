#include "StringSearch.h"

//finds a pattern within of a word. For example,the word onomatopoeia will have 001000101000
void Search::getLPS(std::vector<int> &lpsVec, std::string wordInText){

    int i = 0;  //to keep track of the positions of lpsVec and compare them
    int j = 1;

    lpsVec[0] = 0;                              //All lps vectors begin with 0 because there is nothing to compare it to
    while(j != lpsVec.size()){
        if(wordInText[i] != wordInText[j]){
            if(i == 0){                         //Kind of like a base case to keep 'i' from going into the negatives
                lpsVec[j] = 0;
                j++;
            }
            else{
                i = lpsVec[i - 1];              // If 'i' doesnt equal j, set 'i' to the value of lpsVec at 'i' -1 postion
            }                                   //The base case also keeps this line from seg faulting
        }

        else if(wordInText[i] == wordInText[j]){
            lpsVec[j] = i + 1;                  //If the characters match, everything gets increased by one
            i++;
            j++;
        }
    }
    return;
}
std::vector<int> Search::KMP(std::string wordInText, std::string text,std::string iterativeOrRecursive){
    //This is the KMP helper function.

    std::vector<int> lpsVec(wordInText.size());

    std::vector<int>positions;

    getLPS(lpsVec,wordInText);                  //calls getLPS to create lpsVec

    int i = 0;      //index i of text
    int j = 0;      //index j of wordInText



    if(iterativeOrRecursive == "5"){
        KMPIterative(wordInText,text,i,j,positions,lpsVec);
    }
    else if(iterativeOrRecursive == "6"){
        KMPRecursive(wordInText,text,i,j,positions,lpsVec);
    }
    return positions;
}




void Search::KMPRecursive(std::string wordInText, std::string text,int i, int j, std::vector<int> &positions, std::vector<int> lpsVec){

    if(i == text.size()){                       //Base case for if we have reached the end of the text.
        return;
    }
    if(text[i] == wordInText[j]){               //If characters match
        i++;
        j++;
        if(j == wordInText.size()){             //If j is the size of the word, that means the algorithm found the whole word.
            positions.push_back(i - j);         //We push back at index 'i'-'j' to show where the word starts.
            j = lpsVec[j - 1];                  //Instead of setting j to zero, we set it back one in lpsVec which will then loop until there is a match or j = 0 on the else if.
        }
        KMPRecursive(wordInText,text,i,j,positions,lpsVec);
    }
    else if(text[i] != wordInText[j]){
        if(j != 0){                             //if j didnt just start a new round, take it back a notch in lpsVec
            KMPRecursive(wordInText,text,i,lpsVec[j - 1],positions,lpsVec);
        }
        else{                                   //otherwise compare 'j' with 'i + 1', the next character in the text
            KMPRecursive(wordInText,text,i + 1,j,positions,lpsVec);
        }

    }
}




void Search::KMPIterative(std::string wordInText, std::string text,int i, int j, std::vector<int> &positions, std::vector<int> lpsVec){
    while (i < text.size()){                    //Checks to see if we have reached the end of the text.
        if (wordInText[j] == text[i]) {         //If character matches.
            j++;
            i++;

            if (j == wordInText.size()){        //If j is the size of the word, that means the algorithm found the whole word.
                positions.push_back(i - j);     //We push back at index 'i'-'j' to show where the word starts.
                j = lpsVec[j - 1];              //Instead of setting j to zero, we set it back one in lpsVec which will then loop until there is a match or j = 0 on te else if
            }
        }

        else if (i < text.size() && wordInText[j] != text[i]){
            if (j != 0){                        //if j didnt just start a new round, take it back a notch in lpsVec
                j = lpsVec[j - 1];
            }
            else{
                i++;                            //if j didnt just start a new round, take it back a notch in lpsVec
            }
        }
    }
}