#include "StringSearch.h"

std::vector<int> Search::BF(std::string wordInText, std::string text){
    std::vector<int> positions;

    int M = wordInText.size();
    int N = text.size();

    /* A loop to slide wordInText[] one by one */
    for (int i = 0; i <= N - M; i++) {
        int j;

        /* For current index i, check for wordInTexttern match */
        for (j = 0; j < M; j++)
            if (text[i + j] != wordInText[j])
                break;

        if (j == M) // if wordInText[0...M-1] = text[i, i+1, ...i+M-1]
            positions.push_back(i);
    }
    return positions;
}
