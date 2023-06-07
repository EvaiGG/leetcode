//
// Created by Tony on 2023/6/7.
//

#include "Trie.h"

TrieNode::TrieNode() {
    this->isEndOfWord = false;
}

Trie::Trie() {
    this->root = new TrieNode();
}

void Trie::insert(const std::string &word) {
    TrieNode *current = root;

    for (char c : word) {
        if(current->children.find(c)  == current->children.end()) {
            current->children[c] = new TrieNode();
        }
        current = current->children[c];
    }
    current->isEndOfWord = true;
}

bool Trie::search(const std::string &word) {
    TrieNode* current = root;

    for (char c : word) {
        if (current->children.find(c) == current->children.end()) {
            return false;
        }

        current = current->children[c];
    }

    return current->isEndOfWord;
}

bool Trie::startsWith(const std::string &prefix) {

    TrieNode* current = root;

    for (char c : prefix) {
        if (current->children.find(c) == current->children.end()) {
            return false;
        }

        current = current->children[c];
    }

    return true;
}

int main() {
    Trie trie;

    // 插入单词
    trie.insert("apple");
    trie.insert("banana");
    trie.insert("orange");

    // 查找单词
    std::cout << "Search 'apple': " << (trie.search("apple") ? "Found" : "Not Found") << std::endl;
    std::cout << "Search 'banana': " << (trie.search("banana") ? "Found" : "Not Found") << std::endl;
    std::cout << "Search 'grape': " << (trie.search("grape") ? "Found" : "Not Found") << std::endl;

    // 判断前缀
    std::cout << "Starts with 'app': " << (trie.startsWith("app") ? "Yes" : "No") << std::endl;
    std::cout << "Starts with 'ora': " << (trie.startsWith("ora") ? "Yes" : "No") << std::endl;

    return 0;
}