#include "StringSearch.h"

//get the shift for good suffix rule
int Search::goodSuffix(int j, std::string& wordInText){
    int endPos = wordInText.length() - 1;
    int index = -1;
    j--;

    while(j >= 0){
        if(wordInText[j] == wordInText[endPos]){
            index = j;
            break;
        }
        else
            j--;
    }
    return endPos - index;
}

//get shift for bad character rule
int Search::badChar(int j, char temp, std::string WordInText){ //we're only comparing one car of the text
    int index = -1;

    for(int i = j - 1; i >= 0; --i){
        if(WordInText[i] == temp){
            index = i;
            break;
        }
    }
    return j - index;
}

std::vector<int> Search::BM(std::string wordInText, std::string text){
    std::vector<int> positions;
    int mismatch = 0;

    if(text.length() < wordInText.length()){
        return positions;
    }

    int i = wordInText.length() - 1; //begin match from the end
    int j = text.length() -1;

    while(i < wordInText.length()){ //is there is a successful match
        if(text[i] == wordInText[j]){
            if(j == 0){
                positions.push_back(i);
            }
            i--;
            j--;
        }

        else{ // there is no match
            if(j == wordInText.length()-1){ //if the last character is not matched, apply bad character rule
                mismatch = badChar(j, text[i], wordInText);
                i = i + wordInText.length() - 1 - j + mismatch;
                j = wordInText.length();
            }

            else{//if there is a suffix, compare bad character and good suffix rules
                mismatch = badChar(j, text[i], wordInText);
                if(mismatch == -1){
                    mismatch = wordInText.length();
                    i = i + wordInText.length() - 1 - j + mismatch;
                    j = wordInText.length();
                }
            }

        }
    }
}
