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

class ProcFunctionDemo {
public:
    int processFunction(int base, std::function<int(int ,int)> func, int val1, int val2);
};

#endif //LEETCODE_TRIE_H
