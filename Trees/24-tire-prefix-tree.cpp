#include <iostream>
#include <string>
#include <vector>

using namespace std;
struct TrieNode {
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the Trie
    void insert(string word) {
        TrieNode* current = root;

        for (int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';

            if (current->children[index] == nullptr) {
                current->children[index] = new TrieNode();
            }
            current = current->children[index];
        }

        current->isEndOfWord = true;
    }

    // Returns true if the word is in the Trie
    bool search(string word) {
        TrieNode* current = root;

        for (int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';

            if (current->children[index] == nullptr) {
                return false;
            }
            current = current->children[index];
        }

        return current->isEndOfWord;
    }
    bool startsWith(string prefix) {
        TrieNode* current = root;

        for (int i = 0; i < prefix.length(); i++) {
            int index = prefix[i] - 'a';

            if (current->children[index] == nullptr) {
                return false;
            }
            current = current->children[index];
        }

        return true;
    }
};
