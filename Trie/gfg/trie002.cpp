// Longest Common Prefix
// https://leetcode.com/problems/longest-common-prefix/description/


/*
Longest Common Prefix

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.
*/

// Approach 2

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    int childCount;
    bool isTerminal;

    TrieNode(char ch) {
        this->data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        childCount = 0;
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie(char ch) {
        root = new TrieNode(ch);
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
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->childCount++;
            root->children[index] = child;
        }

        // recursion 
        insertUtil(child, word.substr(1));
    }

    void insert(string word) {
        insertUtil(root, word);
    }

    void lcp(string str, string &ans) {
        TrieNode* currentNode = root;

        for (int i = 0; i < str.length(); i++) {
            char ch = str[i];
            if (currentNode->childCount == 1) {
                ans.push_back(ch);
                // move forward in the trie
                int index = ch - 'a';
                currentNode = currentNode->children[index];
            } else {
                break;
            }
            if (currentNode->isTerminal) {
                break;
            }
        }
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        Trie *t = new Trie('\0');
        // insert all strings into trie
        for (int i = 0; i < strs.size(); i++) {
            if (strs[i].empty()) return ""; // if any string is empty, return ""
            t->insert(strs[i]);
        }

        string first = strs[0];
        string ans = "";

        t->lcp(first, ans);
        return ans;
    }
};


// Apprach 1
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Handle the edge case where the input vector is empty
        if (strs.empty()) return "";

        // Number of strings in the vector
        int n = strs.size();
        // Variable to store the longest common prefix
        string ans = "";

        // Loop through each character of the first string
        for (int i = 0; i < strs[0].length(); i++) {
            // Get the current character to compare
            char ch = strs[0][i];
            bool match = true;

            // Compare the character with the rest of the strings
            for (int j = 1; j < n; j++) {
                // If the current string is shorter or the characters don't match
                if (i >= strs[j].length() || strs[j][i] != ch) {
                    match = false;
                    break;
                }
            }

            // If all strings matched the current character, add it to the answer
            if (match) {
                ans += ch;
            } else {
                // If a mismatch was found, return the answer so far
                break;
            }
        }

        return ans;
    }
};
