#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

// Node structure
struct SListNode 
{
    int data;
    SListNode *next;
}; 

struct SinglyList
{
    SListNode *_head;
    unsigned _size;

    void init() {
        _head = NULL;
        _size = 0;
    }

    bool isEmpty() {
        return (_head == NULL);
    }
    void push(int value)
    {
        SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
        if (value%2 == 0){
            if (newNode) {
                _size++;
                newNode->data = value;
            
                if (isEmpty()) newNode->next = NULL;
                else newNode->next = _head;
                _head = newNode;
            }
        }
        else{
            if (newNode) {
                _size++;
                newNode->data = value;
                newNode->next = NULL;
            }
            if (isEmpty()) 
                _head = newNode;
            else {
                SListNode *temp = _head;
                while (temp->next != NULL) 
                    temp = temp->next;
                temp->next = newNode;
            }
        }
    }
    
};

void print(SListNode *temp){
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    SinglyList myList;

    myList.init();
    
    int N, n;
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> n;
        myList.push(n);
    }
    //myList.EvenOdd();
    cout << "Urutan Mobil Roy : ";
    print(myList._head);
    
    return 0;
}