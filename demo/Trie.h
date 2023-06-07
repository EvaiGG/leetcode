//
// Created by Tony on 2023/6/7.
//

#ifndef LEETCODE_TRIE_H
#define LEETCODE_TRIE_H

#include <unordered_map>
#include "iostream"
class TrieNode{
public:
    std::unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode();
};

class Trie {
public:
    TrieNode *root;

    Trie();
    void insert(const std::string &word) ;

    bool search(const std::string &word);

    bool startsWith(const std::string& prefix) ;
};


#endif //LEETCODE_TRIE_H
