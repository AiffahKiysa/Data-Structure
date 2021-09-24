#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

// Node structure
struct Node {
    int data;
    Node *next;
    Node *left, *right;
    int key;
};

/* Structure of Stack using List */
struct Stack
{
    Node *_top;
    unsigned _size;

    void init() 
    {
        _size = 0;
        _top = nullptr;
    }

    bool isEmpty() {
        return (_top == nullptr);
    }

    void push(int value)
    {
        Node *newNode = (Node*) malloc(sizeof(Node));
        if (newNode) {
            _size++;
            newNode->data = value;

            if (isEmpty()) newNode->next = NULL;
            else newNode->next = _top;
            _top = newNode;
        }
    }

    void pop()
    {
        if (!isEmpty()) {
            Node *temp = _top;
            _top = _top->next;
            free(temp);
            _size--;
        }
    }
    int top()
    {
        if (!isEmpty())
            return _top->data;
        exit(-1);
    }
};

struct BST {
    // Member
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

    void traverseInorder() {
        __inorder(_root);
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

    void __inorder(Node *root) {
        if (root) {
            __inorder(root->left);
            printf("%d ", root->key);
            __inorder(root->right);
        }
    }
};

int main()
{
    Stack myStack;
    myStack.init();

    BST set;
    set.init(); 

    int N, n;
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> n;
        if (n%2==0) myStack.push(n);
        else{
            myStack.pop();
        }
    }
    
    while (!myStack.isEmpty())
    {
        set.insert(myStack.top());
        myStack.pop();
    }

    if(set.isEmpty() == false){
        set.traverseInorder();
        puts("");
    }
    else{
        cout << "Tree Kosong!" << endl;
    }
    return 0;
}