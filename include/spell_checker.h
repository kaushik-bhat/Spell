#ifndef SPELLCHECKER_H
#define SPELLCHECKER_H

#include "trie.h"
#include "levenshtein.h"
#include<vector>
#include<string>

class spellChecker{
    private:
        Trie trie;
        std::vector<std::string> loadWords(const std::string& filepath);

    public:
        spellChecker(const std::string& filepath);
        std::vector<std::string> getSuggestions(const std::string& word); 
};

#endif