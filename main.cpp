#include<iostream>
#include "../include/spell_checker.h"

int main(){
    spellChecker spellChecker("data/words_3000.txt");
    std::string input;
    std::cout<<"Enter a word:";
    std::cin>>input;
    std::vector<std::string> suggestions = spellChecker.getSuggestions(input);
    std::cout<<"Suggestions:\n";
    for(const std::string& word : suggestions){
        std::cout<<word<<"\n";
    }

    return 0;
}