#include"../include/spell_checker.h"
#include<fstream>
#include<algorithm>

spellChecker::spellChecker(const std::string& filepath){
    auto words = loadWords(filepath);
    for(const auto& word : words){
        trie.insert(word);
    }
}

std::vector<std::string> spellChecker::loadWords(const std::string& filepath){
    std::vector<std::string> words;
    std::ifstream file(filepath);
    std::string word;
    while(file >> word){
        words.push_back(word);
    }
    return words;
}

std::vector<std::string> spellChecker::getSuggestions(const std::string& word){
    std::vector<std::string> suggestions = trie.suggest(word);
    std::sort(suggestions.begin(),suggestions.end(),[word](const std::string& a, const std::string& b){
        return levenshtein::distance(word,a) < levenshtein::distance(word,b);
    });
    if(suggestions.size()>3){
        suggestions.resize(3);
    }
    return suggestions;
}