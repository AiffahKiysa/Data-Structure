#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;

struct PQueueNode {
    int data;
    PQueueNode *next;
};

struct PriorityQueue
{
    PQueueNode *_top;
    unsigned _size;

    void init()
    {
        _top = NULL;
        _size = 0;
    }

    bool isEmpty() {
        return (_top == NULL);
    }

    void push(int value)
    {
        PQueueNode *temp = _top;
        PQueueNode *newNode = \
            (PQueueNode*) malloc (sizeof(PQueueNode));
        newNode->data = value;
        newNode->next = NULL;

        if (isEmpty()) {
            _top = newNode;
            return;
        }

        if (value < _top->data) {
            newNode->next = _top;
            _top = newNode;
        }
        else {
            while ( temp->next != NULL && 
                    temp->next->data < value)
                temp = temp->next;
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void pop()
    {
        if (!isEmpty()) {
            PQueueNode *temp = _top;
            _top = _top->next;
            free(temp);
        }
    }

    int top()
    {
        if (!isEmpty()) return _top->data;
        else exit(-1);
    }

    unsigned size() {
        return _size;
    }

    void remove(int value)
    {
        if (!isEmpty()) {
            PQueueNode *temp, *prev;
            temp = _top;

            if (temp->data == value) {
                pop();
                return;
            }
            while (temp != NULL && temp->data != value) {
                prev = temp;
                temp = temp->next;
            }

            if (temp == NULL) return;
            prev->next = temp->next;
            free(temp);
            _size--;
        }
    }
};

struct StackNode {
    int num;
    char mapel[16];
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

    void push(int num, char mapel[])
    {
        StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
        if (newNode) {
            _size++;
            newNode->num = num;
            strcpy(newNode->mapel, mapel);

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
            return _top->num;
        exit(-1);
    }

    char *topMapel(){
        if (!isEmpty())
            return _top->mapel;
        return 0;
    }
};


int main()
{
    PriorityQueue pqueue;
    pqueue.init();

    Stack stack;
    stack.init();

    int N;
    cin >> N;

    for(int i=0; i<N; i++){
        int num;
        char mapel[16];
        cin >> num;
        if (num == -1){
            int count = 0;
			while (pqueue.top() != stack.top()) {
				pqueue.remove(stack.top());
				stack.pop();
                count++;
			}
			if (stack.top() == pqueue.top()) {
				cout << count << " " << stack.topMapel() << endl;
				stack.pop();
				pqueue.pop();
			}
        }
        else{
            cin >> mapel;
            if (num == 0) continue;
            else{
                pqueue.push(num);
                stack.push(num, mapel);
            }
        }
    }

    return 0;
}

