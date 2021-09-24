#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;

struct AVLNode {
    char data[1001];
    AVLNode *left, *right;
    int height;
};

struct AVL
{
    AVLNode *_root;
    unsigned _size;
private:

    AVLNode* _avl_createNode(char value[]) {
        AVLNode *newNode = (AVLNode*) malloc(sizeof(AVLNode));
        strcpy(newNode->data, value);
        newNode->height =1;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    AVLNode* _search(AVLNode *root, char value[]) {
        while (root != NULL) {
            if (strcmp(value, root->data)<0)
                root = root->left;
            else if (strcmp(value, root->data)>0)
                root = root->right;
            else
                return root;
        }
        return root;
    }

    int _getHeight(AVLNode* node){
        if(node==NULL)
            return 0; 
        return node->height;
    }

    int _max(int a,int b){
        return (a > b)? a : b;
    }

    AVLNode* _rightRotate(AVLNode* pivotNode){
        AVLNode* newParrent=pivotNode->left;
        pivotNode->left=newParrent->right;
        newParrent->right=pivotNode;

        pivotNode->height=_max(_getHeight(pivotNode->left),
                        _getHeight(pivotNode->right))+1;
        newParrent->height=_max(_getHeight(newParrent->left),
                        _getHeight(newParrent->right))+1;
        
        return newParrent;
    }

    AVLNode* _leftRotate(AVLNode* pivotNode) {
        AVLNode* newParrent=pivotNode->right;
        pivotNode->right=newParrent->left;
        newParrent->left=pivotNode;

        pivotNode->height=_max(_getHeight(pivotNode->left),
                        _getHeight(pivotNode->right))+1;
        newParrent->height=_max(_getHeight(newParrent->left),
                        _getHeight(newParrent->right))+1;
        
        return newParrent;
    }

    AVLNode* _leftCaseRotate(AVLNode* node){
        return _rightRotate(node);
    }

    AVLNode* _rightCaseRotate(AVLNode* node){
        return _leftRotate(node);
    }

    AVLNode* _leftRightCaseRotate(AVLNode* node){
        node->left=_leftRotate(node->left);
        return _rightRotate(node);
    }

    AVLNode* _rightLeftCaseRotate(AVLNode* node){
        node->right=_rightRotate(node->right);
        return _leftRotate(node);
    }

    int _getBalanceFactor(AVLNode* node){
        if(node==NULL)
            return 0;
        return _getHeight(node->left)-_getHeight(node->right);
    }

    AVLNode* _insert_AVL(AVLNode* node, char value[]) {
        
        if(node==NULL)
            return _avl_createNode(value);
        if(strcmp(value, node->data)<0)
            node->left = _insert_AVL(node->left,value);
        else if(strcmp(value, node->data)>0)
            node->right = _insert_AVL(node->right,value);
        
        node->height= 1 + _max(_getHeight(node->left),_getHeight(node->right)); 

        int balanceFactor=_getBalanceFactor(node);
        
        if(balanceFactor > 1 && strcmp(value, node->left->data)<0)
            return _leftCaseRotate(node);
        if(balanceFactor > 1 && strcmp(value, node->left->data)>0)
            return _leftRightCaseRotate(node);
        if(balanceFactor < -1 && strcmp(value, node->right->data)>0)
            return _rightCaseRotate(node);
        if(balanceFactor < -1 && strcmp(value, node->right->data)>0)
            return _rightLeftCaseRotate(node);
        
        return node;
    }

    AVLNode* _findMinNode(AVLNode *node) {
        AVLNode *currNode = node;
        while (currNode && currNode->left != NULL)
            currNode = currNode->left;
        return currNode;
    }
    void _inorderUrutan(AVLNode *node, int &Number) {
        if (node){
            _inorderUrutan(node->left, Number);
            cout << Number << ". " << node->data << endl;
            Number++;
            _inorderUrutan(node->right, Number);
        }
    }

    void _inorderFormat(AVLNode *node, int &Number){
        if (node){
            _inorderFormat(node->left, Number);
            if (Number == 1){
                cout << node->data;
            }
            else{
                cout << "--<3--" << node->data;
            }
            Number++;
            _inorderFormat(node->right, Number);
        }
    }

public:
    void init() {
        _root = NULL;
        _size = 0U;
    }

    bool isEmpty() {
        return _root == NULL;
    }

    bool find(char value[]) {
        AVLNode *temp = _search(_root, value);
        if (temp == NULL)
            return false;
        
        if (temp->data != value) return false;
        else return true;
    }

    void insert(char value[]) {
        if (!find(value)) {
            _root = _insert_AVL(_root, value);
            _size++;
        }
    }
    void inorderUrutan(){
        int number = 1;
        _inorderUrutan(_root, number);
    }
    void inorderFormat(){
        int number = 1;
        _inorderFormat(_root, number);
    }
};



int main()
{
    AVL set;
    set.init();

    char keys[1001]; 
    int count;

    while (true){            
        count = scanf("%s", keys);
        if (count==EOF) break;
        set.insert(keys);
    }

    set.inorderUrutan();
    set.inorderFormat();

    return 0;
}