#include "StringSearch.h"



// get the shift for good suffix rule
std::vector<int> Search::goodSuffix(std::string wordInText, std::vector<int> &shiftTable, std::vector<int> &borderTable) {
    int i = wordInText.length();
    int j = wordInText.length() + 1;

    for (int i = 0; i < wordInText.length() + 1; i++) {
        shiftTable.push_back(0); // filling the shift table with all zero values
        borderTable.push_back(-1); // filling the border position table with -1
    }

    borderTable[i] = j; // initalizing the border table to the end of the pattern

    while (i > 0) {
        // if the current character at pos i-1 is not a match to the character at j-1, search the rightmost position on the border table
        while (j <= wordInText.length() && wordInText[i - j] != wordInText[j - 1]) {
            // shift the shift the pattern from i to j
            if (shiftTable[j] == 0) {
                shiftTable[j] = j - i;
            }

            // update the position of the next border
            j = borderTable[j];
        }

        // When the border is found, store the begining position of the border
        i--;
        j--;
        borderTable[i] = j;
    }

    j = borderTable[0];
    for (i = 0; i <= wordInText.length(); i++) {
        // if the shift has not been set yet
        if (shiftTable[i] == 0) {
            shiftTable[i] = j;
        }

        if (i == j) {
            // move to the next border
            j = borderTable[j];
        }
    }
}

// returns an array of the locations for mismatches
std::vector<int> Search::badChar(std::string wordInText) { //we're only comparing one car of the text
    std::vector<int> badCharTable;
    int size = 256; // number of possible ASCII values

    for (int i = 0; i < 256; i++) {
        badCharTable.push_back(-1); // filling the table with negative values that will be replaced later
    }
    for (int i = 0; i < wordInText.length(); i++) {
        badCharTable[(int)wordInText[i]] = i; // pushing the last occurance of a particular character in the patterm
    }

    return badCharTable;
}

// function that returns the maximum value between two integers
int max(int a, int b) {
    return a >= b ? a : b;
}

std::vector<int> Search::BM(std::string wordInText, std::string text) {
    std::vector<int> positions;

    if (text.length() < wordInText.length()) {
        return positions;
    }

    int mismatch = 0;

    //initializing vectors to hold shift values
    std::vector<int> badCharTable = badChar(wordInText);

    std::vector<int> shiftTable;
    std::vector<int> borderTable;

    goodSuffix(wordInText, shiftTable, borderTable);

    int i = 0;
    int len_word = wordInText.length();
    int len_text = text.length();

    while (i <= (len_text - len_word)) {
        int j = len_word - 1;
        while (j >= 0 && (text[i + j] == wordInText[j])) {
            // looking for a sutiable suffix match
            j--;
        }
        if (j < 0) { // match found
            positions.push_back(i);
            i += shiftTable[0]; //implement an appropriate shift
        }
        else {
            int badCharOffset = badCharTable[text[i + j]];
            int goodSuffixOffset = shiftTable[j + i];
            // implement either the good suffix or bad character rule depending on which produces a larger shift
            i += max(goodSuffixOffset, j - badCharOffset);
        }
    }

    return positions;
}