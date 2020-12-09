#include "StringSearch.h"
#include <fstream>

int main(){
    Search obj;
    std::vector<int> print;
    std::string text;
    std::string oneOrTwo;

    std::cout<<"Enter '1' if you want to enter a text file name and '2' if you want to enter plain text:\n";
    std::cin>>oneOrTwo;
    while((oneOrTwo != "1") && (oneOrTwo != "2")){
        std::cout<<"Incorrect input. Input was not 1 or 2. Please try again:\n";
        std::cin>>oneOrTwo;
    }
    if(oneOrTwo == "1"){
        std::cout<<"Enter text file name with '.txt' at the end:\n";
        std::string textName;
        std::cin>>textName;

        std::string temp;
        std::ifstream inFile;

        inFile.open(textName);
        if (!inFile) {
            std::cout << "Unable to open file";
            exit(1); // terminate with error
        }

        while (std::getline(inFile,temp)) {
            for (int i = 0; i < temp.size(); i++) {
                temp[i] = tolower(temp[i]);             //convert to lowercase to make search easier
            }
            text.append(temp);
            temp.clear();
        }

        inFile.close();
    }

    else if(oneOrTwo == "2"){
        std::cout<<"Enter plain text:\n";
        std::cin.ignore();
        std::getline(std::cin,text);
    }
    std::cout<<"Great! Now enter the word you would like to search for:\n";
    std::string word;
    std::cin>>word;
    for (int i = 0; i < word.size(); i++) {
        word[i] = tolower(word[i]);                     //convert to lowercase to make search easier
    }

    std::cout<<"Awesome! Enter '1' for the Knuth–Morris–Pratt algorithm and '2' for Boyer-Moore algorithm\n";
    std::cin>>oneOrTwo;
    while((oneOrTwo != "1") && (oneOrTwo != "2")){
        std::cout<<"Incorrect input. Input was not 1 or 2. Please try again:\n";
        std::cin>>oneOrTwo;
    }
    if(oneOrTwo == "1"){
        std::cout<<"Enter '1' if you want to do the Knuth–Morris–Pratt algorithm linearly and '2' if you want to do it recursively\n";
        std::cin>>oneOrTwo;
        while((oneOrTwo != "1") && (oneOrTwo != "2")){
            std::cout<<"Incorrect input. Input was not 1 or 2. Please try again:\n";
            std::cin>>oneOrTwo;
        }
        if(oneOrTwo == "1"){
            print = obj.KMP(word,text,"1");
        }
        else if(oneOrTwo == "2"){
            print = obj.KMP(word,text,"2");
        }
    }
    else if(oneOrTwo == "2"){
        print = obj.BM(word,text);
    }



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
        std::cout<<"and "<<print[print.size() - 1]<<"\n"<<"'"<<word<<"' was found "<<print.size()<<" times";
    }
}