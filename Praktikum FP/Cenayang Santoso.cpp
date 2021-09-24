#include <bits/stdc++.h>  
using namespace std; 

vector<int> ps;
struct BSTNode {
    BSTNode *left, *right;
    bool cek = false;
    int key;
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

    void insert(int value) {
        if (!find(value)) {
            _root = __insert(_root, value);
            _size++;
        }
    }

    void traverseInorder() {
        __inorder(_root);
    }

    void right(){
        int level = 0;
        _right(_root, true, level);
    }
    void left(){
        int level = 0;
        _left(_root, true, level);
    }
private:
    
    BSTNode* __createNode(int value) {
        BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
        newNode->key = value;
        newNode->left = newNode->right = NULL;
        newNode->cek = false;
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

    void __inorder(BSTNode *root) {
        if (root != NULL) {
            __inorder(root->left);      
            if(!root->cek) {
                if(root->left || root->right) {
                    ps.push_back(root->key);        
                }
            }
            __inorder(root->right);     
        }
    }

    void _right (BSTNode *root, int area, int &level) {
        if (root){
            if (level<area && area!=0) {
                root->cek = true;
                level = area;
            }
            _right(root->right, area+1, level);       
            _right(root->left, area+1, level);       
        }
    }
    
    void _left (BSTNode *root, int area, int &level) {
        if (root){
            if (level<area && area!=0) {
                root->cek = true;
                level = area;
            }
            _left(root->left, area+1, level);     
            _left(root->right, area+1, level);    
        }
    }
};
 
int main() {
    BST set;
    set.init();    
    
    int testcase, angka;
    
    cin >> testcase;            
    for(int i=1; i<=testcase; i++) {
        cin >> angka;            
        set.insert(angka);      
    }
    set.right();
    set.left();           
    set.traverseInorder();
     
    if(ps.size()>0) {
        for(int i=0; i<ps.size(); i++) {
            cout << ps.at(i) << " ";
        }
    } 
    else {
        cout <<"Yah, gk ada posisi yang aman :(" << endl;      
    }

    return 0;
}