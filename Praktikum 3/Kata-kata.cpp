#include <stdlib.h>
#include <iostream>
#include <cstring>
using namespace std;

struct TrieNode
{
    struct TrieNode *children[26];
    bool isEndOfWord;
    //int node;
}*root;

void init() {
    root = new TrieNode(); 
    root->isEndOfWord = false; 
    //root->node = 0;
}

struct TrieNode *getNode()
{
    struct TrieNode *pNode =  new TrieNode;
    pNode->isEndOfWord = false;
    
    for (int i=0; i<26; i++){
        pNode->children[i] = NULL;
    }
    return pNode;
}
  
void insert(string key)
{
    struct TrieNode *temp = root;
    
    int l = key.length();
    for (int i=0; i<l; i++)
    {
        int index = key[i] - 'a';
        if (!temp->children[index]){
            temp->children[index] = getNode();
        }
        temp = temp->children[index];
    }
    temp->isEndOfWord = true;
}
  
bool search(string key)
{
    struct TrieNode *temp = root;
    int l = key.length();
    for (int i=0; i<l; i++)
    {
        int index = key[i] - 'a';
        if (!temp->children[index])
            return false;
  
        temp = temp->children[index];
    }
  
    return (temp != NULL && temp->isEndOfWord);
}

int main()
{
    init();
    string keys, find; 

    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> keys;
        insert(keys);
    }
    int q;
    cin >> q;
    for (int i=0; i<q; i++){
        cin >> find;
        if (search(find)==true) cout << "1" << endl;
        else cout << "0" << endl;
    }
    return 0;
}

