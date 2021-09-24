#include <stdlib.h>
#include <iostream>

using namespace std;

struct Node {
    Node *left, *right;
    int key;
};

struct BST {
    Node *_root;
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
        Node *temp = __search(_root, value);
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

    void remove(int value) {
        if (find(value)) {
            _root = __remove(_root, value);
            _size++;
        }
    }

    bool FindSum (Node *root, int sum){
        if (root == NULL) return false;

        else{   
            if(root->right != NULL){
                if (root->left != NULL){
                    if (root->key + root->right->key + root->left->key == sum) return true;
                }
            }
            if(root->right != NULL){
                if (root->right->right != NULL){
                    if (root->key + root->right->key + root->right->right->key == sum) return true;
                }
            }
            if(root->right != NULL){
                if (root->right->left != NULL){
                    if (root->key + root->right->key + root->right->left->key == sum) return true;
                }
            }
            if(root->left != NULL){
                if (root->left->right != NULL){
                    if (root->key + root->left->key + root->left->right->key == sum) return true;
                }
            }
            if(root->left != NULL){
                if (root->left->left != NULL){
                    if (root->key + root->left->key + root->left->left->key == sum) return true;
                }
            }
        }
        
        return (FindSum(root->right, sum) || FindSum(root->left, sum));
        
    }

private:
    // Utility Function
    Node* __createNode(int value) {
        Node *newNode = (Node*) malloc(sizeof(Node));
        newNode->key = value;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    
    Node* __search(Node *root, int value) {
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

    Node* __insert(Node *root, int value) {
        if (root == NULL)
            return __createNode(value);
        
        if (value < root->key)
            root->left = __insert(root->left, value);
        else if (value > root->key)
            root->right = __insert(root->right, value);
        
        return root;
    }

    Node* __findMinNode(Node *node) {
        Node *currNode = node;
        while (currNode && currNode->left != NULL)
            currNode = currNode->left;
        
        return currNode;
    }

    Node* __remove(Node *root, int value) {
        if (root == NULL) return NULL;

        if (value > root->key) 
            root->right = __remove(root->right, value);
        else if (value < root->key) 
            root->left = __remove(root->left, value);
        else {

            if (root->left == NULL) {
                Node *rightChild = root->right;
                free(root);
                return rightChild;
            }
            else if (root->right == NULL) {
                Node *leftChild = root->left;
                free(root);
                return leftChild;
            }

            Node *temp = __findMinNode(root->right);
            root->key     = temp->key;
            root->right   = __remove(root->right, temp->key);
        }
        return root;
    }
};

int main()
{
    BST set;
    set.init();

    int P, Q, N;
    cin >> P;
    for (int i=0; i<P; i++){
        cin >> Q;
        set.insert(Q);
    }
    cin >> N;
    if (set.FindSum(set._root, N)==true){
        cout << "Penjumlahan angka di tree yang menghasilkan " << N << " ditemukan";
    }
    else cout << "Tidak ditemukan penjumlahan angka di tree yang menghasilkan " << N;

    return 0;
}