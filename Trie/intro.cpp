#include <iostream>
#include <string>

using namespace std;

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {
        this->data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word) {
        // base case
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        // present
        if (root->children[index] != nullptr) {
            child = root->children[index];
        } else {
            // absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // recursion
        insertUtil(child, word.substr(1));
    }

    void insert(string word) {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode* root, string word) {
        // base case
        if (word.length() == 0) {
            return root->isTerminal;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        // present
        if (root->children[index] != nullptr) {
            child = root->children[index];
        } else {
            return false;
        }

        // recursion
        return searchUtil(child, word.substr(1));
    }

    bool search(string word) {
        return searchUtil(root, word);
    }

    bool startsWithUtil(TrieNode* root, string prefix) {
        // base case
        if (prefix.length() == 0) {
            return true;
        }

        int index = prefix[0] - 'a';
        TrieNode* child;

        // present
        if (root->children[index] != nullptr) {
            child = root->children[index];
        } else {
            return false;
        }

        // recursion
        return startsWithUtil(child, prefix.substr(1));
    }

    bool startsWith(string prefix) {
        return startsWithUtil(root, prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main() {
    Trie* trie = new Trie();
    trie->insert("apple");
    trie->insert("app");

    cout << boolalpha; // print booleans as true/false instead of 1/0
    cout << "Searching for 'apple': " << trie->search("apple") << endl; // true
    cout << "Searching for 'app': " << trie->search("app") << endl; // true
    cout << "Searching for 'appl': " << trie->search("appl") << endl; // false
    cout << "Starts with 'app': " << trie->startsWith("app") << endl; // true
    cout << "Starts with 'appl': " << trie->startsWith("appl") << endl; // true
    cout << "Starts with 'banana': " << trie->startsWith("banana") << endl; // false

    delete trie;
    return 0;
}
