#ifndef TRIE_H
#define TRIE_h

#include<unordered_map>
#include<string>
#include<vector>

class trieNode{
    public:
        bool isEndOfWord;
        std::unordered_map<char,trieNode*> children;

        trieNode() : isEndOfWord(false) {}
};

class Trie{
    private:
        trieNode* root;

        void suggestHelper(trieNode* current, std::string prefix, std::vector<std::string>& suggestions);
    
    public:
        Trie();
        void insert(const std::string& word);
        std::vector<std::string> suggest(const std::string& prefix);
};

#endif