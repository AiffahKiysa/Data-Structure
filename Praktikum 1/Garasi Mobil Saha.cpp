#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

struct PQueueNode {
    int IN, OUT;
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

    void push(int timeIn, int timeOut)
    {
        PQueueNode *temp = _top;
        PQueueNode *newNode = \
            (PQueueNode*) malloc (sizeof(PQueueNode));
        newNode->IN = timeIn;
        newNode->OUT = timeOut;
        newNode->next = NULL;

        if (isEmpty()) {
            _top = newNode;
            return;
        }

        if (timeIn < _top->IN) {
            newNode->next = _top;
            _top = newNode;
        }
        else {
            while ( temp->next != NULL && 
                    temp->next->IN < timeIn)
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
        if (!isEmpty()) return _top->IN;
        else exit(-1);
    }

    unsigned size() {
        return _size;
    }
    
    void swapCar() {
        if (!isEmpty()) {
            PQueueNode *temp;
            temp = _top;

            while (temp->next != NULL) {
                if (temp->IN == temp->next->IN) {
                    if (temp->OUT > temp->next->OUT) {
                        swap(temp->OUT, temp->next->OUT);
                    }
                }
                temp = temp->next;
            }
        }
    }

    bool Renov() {
        PQueueNode *temp = _top;

        if (temp->IN == temp->OUT){
            return true;
        }
        if (temp->OUT <= temp->next->IN){
            return false;
        }
        while ( temp->next != NULL ){
            if (temp->next->IN == temp->next->OUT) {
                return true;
            }
            temp = temp->next;
            if (temp->IN >= _top->IN && temp->IN < _top->OUT && temp->OUT > _top->OUT)
                return true;
        }
        return false;
    }
};

int main()
{
    PriorityQueue pqueue;
    pqueue.init();

    int testcase;
    cin >> testcase;
    
    for (int i=0; i<testcase; i++)
    {
        int car, capacity;
		cin >> car >> capacity;

    	for (int j=0; j<car; j++) {
            int timeIn, timeOut;
    		cin >> timeIn >> timeOut;
    		pqueue.push(timeIn, timeOut);
		}

		pqueue.swapCar();
		if (pqueue.Renov()){
			cout << "Hmm harus renovasi garasi nich" << endl;
        }
		else {
			cout << "Hore gausah renov garasi" << endl;
        }

	    while (!pqueue.isEmpty()) {
	        pqueue.pop();
	    }
	}
    return 0;
}