#include <iostream>
#include <string>
#include <unordered_map>

class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;
    int count;

    TrieNode() : count(0) {}
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() : root(new TrieNode()) {}

    void insert(const std::string& word) {
        TrieNode* node = root;

        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];

            node->count++;
        }
    }

    int countwords(const std::string& prefics) {
        TrieNode* node = root;
        for (char ch : prefics) {
            if (node->children.find(ch) == node->children.end()) {
                return 0;
            }
            node = node->children[ch];
        }
        return node->count;
    }
};

int main() {
    Trie tree;

    tree.insert("hide");
    tree.insert("hello");
    tree.insert("apple");
    tree.insert("ihihihi");
    tree.insert("idol");

    std::cout << "words with i - " << tree.countwords("i") << std::endl;

    return 0;
}
