#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

/* Node structure */

struct BSTNode {
    BSTNode *left, *right;
    int key;
};

/* uniqueBST */

struct BST {
    // Member
    BSTNode *_root;
    unsigned int _size;

    // Function
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

    void insert(int value) {
        if (!find(value)) {
            _root = __insert(_root, value);
            _size++;
        }
    }

    void connect(int L, int R){
        int sum = 0;
        __sumconnect(_root, L, R, sum);
        cout << sum << endl;
    }
private:
    // Utility Function
    BSTNode* __createNode(int value) {
        BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
        newNode->key = value;
        newNode->left = newNode->right = NULL;
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

    BSTNode* __insert(BSTNode *root, int value) {
        if (root == NULL)
            return __createNode(value);
        
        if (value < root->key)
            root->left = __insert(root->left, value);
        else if (value > root->key)
            root->right = __insert(root->right, value);
        
        return root;
    }

    BSTNode* __findMinNode(BSTNode *node) {
        BSTNode *currNode = node;
        while (currNode && currNode->left != NULL)
            currNode = currNode->left;
        
        return currNode;
    }

    void __sumconnect(BSTNode *root, int L, int R, int &sum){
        if (root->key < L){
            __sumconnect(root->right, L, R, sum);
        }
        else if (root->key > R){
            __sumconnect(root->left, L, R, sum);
        }
        else{
            _sumRecursion(root, sum);
        }        
    }
    void _sumRecursion(BSTNode *root, int &sum){
        if (root != NULL){
            sum += root->key;
            _sumRecursion(root->left, sum);
            _sumRecursion(root->right, sum);
        }
    }
};

int main()
{
    BST set;
    set.init();

    int N, Q;
    cin >> N >> Q;

    for (int i=0; i<N; i++){
        int A;
        cin >> A;
        set.insert(A);
    }
    int L, R;
    for (int i=0; i<Q; i++){
        
        cin >> L >> R;
        if (R < L) {
            int temp = R;
            R = L;
            L = temp;
        }
        if (set.find(L)==true && set.find(R)==true){
            set.connect(L, R);
        }
        else{
            cout << "-1" << endl;
        }
    }

    return 0;
}