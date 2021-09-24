#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
using namespace std;

struct Node {
    Node *left, *right;
    int key;
    int data;
    Node *next;
};

struct BST {
    Node *_root;
    unsigned int _size;

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

private:

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

    int height(Node* node)
    {
        if (node == NULL)
            return 0;
        else
        {
            /* compute the height of each subtree */
            int lheight = height(node->left);
            int rheight = height(node->right);
    
            /* use the larger one */
            if (lheight > rheight)
                return(lheight + 1);
            else return(rheight + 1);
        }
    }

    void levelOrder(Node* root){
        int h = height(root);
        if (root == NULL) return ;

        queue<Node*> q;
        q.push(root);
        q.push(NULL);
    
        int min = 1000000;
        int max = 0;
        int level = 0;
    
        while (q.empty() == false) {
            Node* node = q.front();
            q.pop();

            if (node == NULL) {
                if (h%2 != 0){
                    if (level%2 == 0) push(min);
                    else push(max);
                }
                else{
                    if (level%2 == 0) push(max);
                    else push(min);
                }

                if (q.empty())break;
    
                q.push(NULL);
                level++;

                min = 1000000;
                max = 0;
    
                continue;
            }
    
            if (max < node->key)
                max = node->key;

            if (min > node->key)
                min = node->key;
    
            if (node->left != NULL) {
                q.push(node->left);
            }
    
            if (node->right != NULL) {
                q.push(node->right);
            }
        }
    }
};

int main()
{
    BST set;
    set.init();

    Stack myStack;
    myStack.init();

    int P, Ai;
    cin >> P;
    for(int i=0; i<P; i++){
        cin >> Ai;
        set.insert(Ai);
    }

    myStack.levelOrder(set._root);
    while (!myStack.isEmpty())
    {
        cout << myStack.top() << " ";
        myStack.pop();
    }
 
    return 0;
}
