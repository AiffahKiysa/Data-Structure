#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct BSTNode {
    BSTNode *left, *right, *parent;
    long long key, Minimum, top;
};

struct BST {
    BSTNode *_root;
    unsigned int _size;

    void init() {
        _root = NULL;
        _size = 0u;
    }

    bool isEmpty() {
        return _root == NULL;
    }

    bool find(int value) {
        BSTNode *temp = __search(_root, value);
        if (!temp)
            return false;
        
        if (temp->key == value)
            return true;
        else
            return false;
    }

    void insert(int value, int top) {
        if (!find(value)) {
            _root = __insert(_root, value, top);
            _size++;
        }
    }

    void top(){
        BST_top(_root);
    }

    void minimum(){
        BST_minimum(_root);
    }

    bool findmin(int value) {
        BSTNode *temp = __search(_root, value);
        if (temp == NULL)
            return false;

        if (temp->key == value) {
            cout << temp->Minimum;
            return true;
        } 
        else
            return false;
    }

private:
    BSTNode* __createNode(int value, int top) {
        BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
        newNode->top = top;
        newNode->key = value;
        newNode->Minimum = ULLONG_MAX;
        newNode->left = newNode->right = newNode->parent = NULL;
        return newNode;
    }
    
    BSTNode* __search(BSTNode *root, int value) {
        while (root != NULL) {
            if (value < root->key)
                root = root->left;
            else if (value > root->key)
                root = root->right;
            else
                return root;
        }
        return root;
    }

    BSTNode* __insert(BSTNode *root, int value, int top) {
        if (root == NULL)
            return __createNode(value, top);
        
        if (value < root->key){
            root->left = __insert(root->left, value, top);
            root->left->parent = root;
        }
        else if (value > root->key){
            root->right = __insert(root->right, value, top);
            root->right->parent = root;
        }
        return root;
    }

    void BST_top(BSTNode *root){
        if (root){
            if (root->parent != NULL && root->Minimum > root->parent->Minimum + root->top){
                root->Minimum = root->parent->Minimum + root->top;    
            }
            BST_top(root->left);
            BST_top(root->right);
        }
    }

    void BST_minimum(BSTNode *root) {
        if (root) {
            BST_minimum(root->left);
            BST_minimum(root->right);

            if (root->left == NULL && root->right == NULL){
                root->Minimum = 0;
            }
            if (root->parent != NULL && root->parent->Minimum > root->top + root->Minimum){ 
                root->parent->Minimum = root->top + root->Minimum;
            }
        }
    }

    
};

int main()
{
    BST set;
    set.init();

    long long K, R;
    cin >> K >> R;
    set.insert(R, 0);
    
    long long Ni, Ji;
    for (int i=0; i<K-1; i++){
        cin >> Ni >> Ji;
        set.insert(Ni, Ji);
    }

    set.minimum();
    set.top();
    long long T, P;
    cin >> T;
    for (int i=0; i<T; i++){
        cin >> P;
        if (set.find(P)){
            set.findmin(P);
        }
        else{
            cout << "0";
        }
        cout << endl;
    }
    return 0;
}