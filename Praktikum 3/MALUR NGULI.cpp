#include <stdlib.h>
#include<bits/stdc++.h>
#include <stdio.h>
#include <iostream>
using namespace std;

struct AVLNode {
    int data;
    AVLNode *left, *right;
    int height;
};

struct AVL {
    AVLNode *_root;
    unsigned _size;
private:
    
    AVLNode* _avl_createNode(int value) {
        AVLNode *newNode = (AVLNode*) malloc(sizeof(AVLNode));
        newNode->data = value;
        newNode->height =1;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
  
    AVLNode* _search(AVLNode *root, int value) {
        while (root != NULL) {
            if (value < root->data) {
                root = root->left;
            } else if (value > root->data) {
                root = root->right;
            } else {
                return root;
            }
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
        pivotNode->height=_max(_getHeight(pivotNode->left), _getHeight(pivotNode->right))+1;
        newParrent->height=_max(_getHeight(newParrent->left), _getHeight(newParrent->right))+1;
        return newParrent;
    }

    AVLNode* _leftRotate(AVLNode* pivotNode) {
        AVLNode* newParrent=pivotNode->right;
        pivotNode->right=newParrent->left;
        newParrent->left=pivotNode;
        pivotNode->height=_max(_getHeight(pivotNode->left), _getHeight(pivotNode->right))+1;
        newParrent->height=_max(_getHeight(newParrent->left), _getHeight(newParrent->right))+1;
        return newParrent;
    }

    AVLNode* _leftCaseRotate(AVLNode* node) {      
        return _rightRotate(node);
    }
    AVLNode* _rightCaseRotate(AVLNode* node) {      
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
        if(node==NULL) {
            return 0;
        }
        return _getHeight(node->left)-_getHeight(node->right);
    }

    AVLNode* _insert_AVL(AVLNode* node,int value) {
        if(node==NULL) {
            return _avl_createNode(value);
        }
        if(value < node->data) {
            node->left = _insert_AVL(node->left,value);
        } else if(value > node->data) {
            node->right = _insert_AVL(node->right,value);
        }
        node->height= 1 + _max(_getHeight(node->left),_getHeight(node->right)); 
        
        int balanceFactor=_getBalanceFactor(node);
        
        if(balanceFactor > 1 && value < node->left->data){
            return _leftCaseRotate(node);
        }
        if(balanceFactor > 1 && value > node->left->data){
            return _leftRightCaseRotate(node);
        }
        if(balanceFactor < -1 && value > node->right->data){
            return _rightCaseRotate(node);
        }
        if(balanceFactor < -1 && value < node->right->data){
            return _rightLeftCaseRotate(node);
        }
        return node;
    }

    AVLNode* _findMinNode(AVLNode *node) {
        AVLNode *currNode = node;
        while (currNode && currNode->left != NULL) {
            currNode = currNode->left;
        }
        return currNode;
    }
    
    
public:

    void init() {
        _root = NULL;
        _size = 0U;
    }

    bool isEmpty() {
        return _root == NULL;
    }

    bool find(int value) {
        AVLNode *temp = _search(_root, value);
        if (temp == NULL) {
            return false;
        }
        if (temp->data == value) {
            return true;
        } else {
            return false;
        }
    }
 
    void insert(int value) {
        if (!find(value)) {
            _root = _insert_AVL(_root, value);
            _size++;
        }
    }
};

int Partright[1001];
int Partleft[1001];
int kiri, kanan;

int CKiri(AVLNode *Node) {
    int count = 0;
    if (Node){
        while (Node->left != NULL) {     
            Node = Node->left;          
            count++;                  
        }                
    } 
    return count;
}

int CKanan(AVLNode *Node) {      
    int count = 0;   
    if (Node){ 
        while (Node->right != NULL) {       
            Node = Node->right;        
            count++;         
        }    
    }
    return count;
}

void totalNilai(AVLNode *Node, int count){
    if(Node) { 
        if (count==0){    
            Partright[0] += Node->data; 
        }   
        else if (count<0){
            if (abs(count)>kiri){ 
                kiri++;         
            }
            Partleft[abs(count)] += Node->data;  
        } 
        else {
            Partright[count] += Node->data;
        }

        totalNilai(Node->left, count-1);
        totalNilai(Node->right, count+1);
    }
}

void sumVertical(AVLNode *Node) {
    for(int i=0; i<=999; i++) {    
        Partright[i]=0;
        Partleft[i]=0;
    }
    totalNilai(Node, 0);
}


int main()
{
    AVL set;
    set.init();

    int N, X;
    string A;
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> A;
        if (A == "insert"){
            cin >> X;
            set.insert(X);
        }
        else if (A == "print"){
            kiri = CKiri(set._root);
            kanan = CKanan(set._root);
            sumVertical(set._root);

            for (int i=kiri; i>0; i--){
                cout << Partleft[i] << " ";
            }
            for (int i=0; i<=kanan; i++){
                cout << Partright[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}