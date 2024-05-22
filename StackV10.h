#ifndef STACK_H
#define STACK_H

struct POS {
    int x, y;
};

struct Node {
    POS data;
    Node* next;
};

class Stack {
private:
    Node* top;
public:
    Stack() : top(nullptr) {}

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(POS pos) {
        Node* newNode = new Node;
        newNode->data = pos;
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (isEmpty()) return;
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    POS peek() {
        if (isEmpty()) {
            return { -1, -1 }; // Return an invalid position if stack is empty
        }
        return top->data;
    }
};

#endif
