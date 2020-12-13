#include "StringSearch.h"

int main(){
    Search obj;
    std::vector<int> print;
    std::string text;
    std::string oneOrTwo;

    std::cout<<"Enter '1' if you want to enter a text file name and '2' if you want to enter plain text:\n";
    std::cin>>oneOrTwo;
    while((oneOrTwo != "1") && (oneOrTwo != "2")){
        std::cout<<"Incorrect input. Input was not '1' or '2'. Please try again:\n";
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
            temp.append(" ");
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


    std::string threeOrFour;
    std::cout<<"Awesome! Enter '3' for the Knuth–Morris–Pratt algorithm and '4' for Boyer-Moore algorithm\n";
    std::cin>>threeOrFour;
    while((threeOrFour != "3") && (threeOrFour != "4")){
        std::cout<<"Incorrect input. Input was not '3' or '4'. Please try again:\n";
        std::cin>>threeOrFour;
    }
    if(threeOrFour == "3"){
        std::string fiveOrSix;

        std::cout<<"Enter '5' if you want to do the Knuth–Morris–Pratt algorithm iteratively and '6' if you want to do it recursively\n";
        std::cin>>fiveOrSix;
        while((fiveOrSix != "5") && (fiveOrSix != "6")){
            std::cout<<"Incorrect input. Input was not '5' or '6'. Please try again:\n";
            std::cin>>fiveOrSix;
        }
        if(fiveOrSix == "5"){
            //timer for .csv file
            std::ofstream out;
            out.open("KMP_Pattern.csv",std::ios::app);
            std::clock_t start;

            start = std::clock();
            //end of timer
            print = obj.KMP(word,text,"5");
            out<<text.size()<<","<<(std::clock() - start ) / (double) CLOCKS_PER_SEC<<"\n";
            out.close();
        }
        else if(fiveOrSix == "6"){
            print = obj.KMP(word,text,"6");
        }
    }
    else if(threeOrFour == "4"){
            //timer for .csv file
            std::ofstream out;
            out.open("BMoore_Pattern.csv",std::ios::app);
            std::clock_t start;

            start = std::clock();
            //end of timer
        print = obj.BM(word,text);
        out<<text.size()<<","<<(std::clock() - start ) / (double) CLOCKS_PER_SEC<<"\n";
        out.close();
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
        std::cout<<"and "<<print[print.size() - 1]<<"\n"<<"'"<<word<<"' was found "<<print.size()<<" times\n";
    }
    std::string sevenOrEight;

    std::cout<<"\nPress '7' if you would like to output this to an easy to read file and '8' to end the program:\n";
    std::cin>>sevenOrEight;
    while((sevenOrEight != "7") && (sevenOrEight != "8")){
        std::cout<<"Incorrect input. Input was not '7' or '8'. Please try again:\n";
        std::cin>>sevenOrEight;
    }
    if(sevenOrEight == "7"){
        std::ofstream out;
        out.open("output.html");
        std::string html = "<style>p{font-family:Calibri;font-size:200%;text-align:center;background-color:white;}.double-space {line-height: 2;}</style><p class = double-space>";
        text.insert(0,html);
        for (int i = 0; i < print.size(); i++){
            text.insert(print[i] + 7 * i + html.size(),"<b>");
            text.insert(print[i] + word.size() + (7 * i) + 3 + html.size(),"</b>");
        }
        text.insert(text.size(),"</p>");
        out<<text;
        out.close();
    }
}