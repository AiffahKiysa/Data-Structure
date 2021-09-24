#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

// Node structure
struct StackNode {
    int data;
    StackNode *next;
};

struct Stack
{
    StackNode *_top;
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
        StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
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
            StackNode *temp = _top;
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
    
    void reverse(){
        StackNode *prev, *curr, *temp;
        curr = prev = _top;
        curr = curr->next;
        prev->next = NULL;
        while (curr != NULL) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        _top = prev;
    }
};

int main()
{
    Stack myStack;
    myStack.init();

    short T, P;
    int Q, i;
    cin >> T;

    for(i = 1; i <= T; i++)
    {
        cin >> P; 
        for (int i = 1; i <= P; i++){
            cin >> Q;
            if (myStack.isEmpty()) myStack.push(Q);       
            else {
                while(!myStack.isEmpty() && Q > myStack.top()) { 
                    myStack.pop();                      
                }   
                myStack.push(Q);
            }
        }
        cout << "Susunan blok yang disusun Nadut dan Cayo adalah : ";
        myStack.reverse();
        while (!myStack.isEmpty()) {
            cout << myStack.top() << " ";
            myStack.pop();
        }
        cout << endl;
    }
    return 0;
}
