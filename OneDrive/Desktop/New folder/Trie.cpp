#include<bits/stdc++.h>
using namespace std;
class TrieNode{

    public:
        char data;
        TrieNode* children[26];
        bool terminal;

    TrieNode(char ch){
        this->data = ch;
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        this->terminal = false;
    }
};

class Trie{
    public:
    TrieNode* root;

    Trie(){
        root = new TrieNode('\0');
    }

    // Assuming that string is capital

    void insertUtil(TrieNode* root, string word){
        if(word.length() == 0){
            root->terminal = true;
            return;
        }

        TrieNode* child;
        int index = word[0] - 'A';

        if(root->children[index] != NULL){
            // Present
            child = root->children[index];

        }else{
            // Absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursion
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word){
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode* root, string word){
        if(word.length() == 0){
            return root->terminal;
        }

        TrieNode* child;
        int index = word[0] - 'A';

        if(root->children[index] != NULL){
            // Present
            child = root->children[index];
        }else{
            // Absent
            return false;
        }
        // Recursion
        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word){
        return searchUtil(root, word);
    }
};

int main(){

    Trie* t = new Trie();
    t->insertWord("ABCD");
    t->insertWord("ABCDE");
    t->insertWord("SPD");
    cout << "Word Present or Not: " << t->searchWord("WWW") << endl;
    cout << "Word Present or Not: " << t->searchWord("ABCD") << endl;
    cout << "Word Present or Not: " << t->searchWord("ABC") << endl;
    cout << "Word Present or Not: " << t->searchWord("SPD") << endl;

    return 0;
}