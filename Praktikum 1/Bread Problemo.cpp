#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;

struct StackNode {
    int data;
    StackNode *next;
};

struct Stack
{
    StackNode *_top;
    unsigned _size;
};
    
void init(Stack *ray, Stack *temp) 
{
    ray->_size = temp->_size = 0;
    ray->_top = temp->_top = NULL;
}

bool isEmpty(Stack *current) {
    return (current->_top == nullptr);
}

void push(Stack *PUSH, int value)
{
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode) {
        PUSH->_size++;
        newNode->data = value;
        newNode->next = NULL;

        if (isEmpty(PUSH)) PUSH->_top = newNode;
        else {
            StackNode *temp = PUSH->_top;
            PUSH->_top = newNode;
            newNode->next = temp;
        }
    }
}

void pop(Stack *POP)
{
    if (!isEmpty(POP)) {
        StackNode *temp = POP->_top;
        POP->_top = temp->next;
        free(temp);
        POP->_size--;
    }
}

int top(Stack *TOP)
{
    if (!isEmpty(TOP))
        return TOP->_top->data;
    exit(-1);
}


void pushpop(Stack *PUSH, Stack *pop){
    if (pop->_top != NULL){
        push(PUSH, pop->_top->data);

        StackNode *temp = pop->_top;
        pop->_top = temp->next;
        free(temp);
        pop->_size--;
    }
}

int main()
{
    Stack myStack;
    Stack temp;
    init(&myStack, &temp);
    
    int N, T;
    int Ai, Bi, i;
    cin >> N;

    if (N == 0){
        cout << "Ray SangaT MaraH!" << endl;
    }
    for (i = N; i > 0; i--){
        push(&myStack, i);
    }

    cin >> T;
    for (i=0; i<T; i++){
        cin >> Ai >> Bi;
        if (Ai==1){
            for (int j=0; j<Bi; j++){
                pushpop(&temp, &myStack);
            }
        } 
        else if (Ai==2){
            for (int j=0; j<Bi; j++){
                pushpop(&myStack, &temp);
            }
        }
        else{
            cout << "TumpukAnnya saLah! :(" << endl;
            return 0;
        }
    }

    int count = 0;
    int x;
    if (myStack._size > temp._size){
        x = myStack._size;
    }
    else{
        x = temp._size;
    }

    for (int i=0; i<x; i++){
        if (myStack._size > 0){
            cout << top(&myStack) << " ";
            pop(&myStack);
        }
        else{
            if (myStack._size <= 0 && !count){
                cout << "- ";
                count++;
            }
            else{
                cout << " ";
            }
        }

        if (temp._size > 0){
            cout << top(&temp) << endl;
            pop(&temp);
        }
        else{
            if (temp._size <= 0 && !count){
                cout << ":(" << endl;
                count++;
            }
            else{
                cout << endl;
            }
        }
    }
    return 0;
}
