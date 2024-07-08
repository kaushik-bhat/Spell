#include"../include/trie.h"

Trie::Trie(){
    root = new trieNode();
}

void Trie::insert(const std::string& word){
    trieNode* current =root;
    for(char c:word){
        if(current->children.find(c) == current->children.end()){
            current->children[c] = new trieNode();
        }
        current = current->children[c];
    }
    current->isEndOfWord = true;
}

void Trie::suggestHelper(trieNode* current, std::string prefix, std::vector<std::string>& suggestions){
    if(current->isEndOfWord){
        suggestions.push_back(prefix);
    }
    for(auto it: current->children){
        suggestHelper(it.second,prefix+it.first,suggestions);
    }
}

std::vector<std::string> Trie::suggest(const std::string& prefix){
    trieNode* current = root;
    std::vector<std::string> suggestions;
    for(char c:prefix){
        if(current->children.find(c) == current->children.end()){
            return suggestions;
        }
        current = current->children[c];
    }
    suggestHelper(current,prefix,suggestions);
    return suggestions;
}