#include <iostream>
using namespace std;
class StackInt {
private:
    int* stack;
    int top;
    int maxSize;

public:
    StackInt(int size) {
        maxSize = size;
        stack = new int[maxSize];
        top = -1;
    }
    StackInt() {
        delete[] stack;
    }
    bool isEmpty() {
        return top == -1;
    }
    bool isFull() {
        return top == maxSize - 1;
    }
    void push(int value) {
        if (isFull()) {
            cout << "Stack is full!" << endl;
        } else {
            stack[++top] = value;
        }
    }
    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        } else {
            return stack[top--];
        }
    }
    int peek() {
        if (isEmpty()) {
            return -1;
        } else {
            return stack[top];
        }
    }
    void clear() {
        top = -1;
    }
};
class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};
class LinkedStackInt {
private:
    Node* top;
public:
    LinkedStackInt() {
        top = nullptr;
    }
    bool isEmpty() {
        return top == nullptr;
    }
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }
    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        } else {
            int value = top->data;
            Node* temp = top;
            top = top->next;
            delete temp;
            return value;
        }
    }
    int peek() {
        if (isEmpty()) {
            return -1;
        } else {
            return top->data;
        }
    }
    void clear() {
        while (!isEmpty()) {
            pop();
        }
    }
};
void decimalToBinary(int n) {
    StackInt stack(100);
    while (n > 0) {
        stack.push(n % 2);
        n /= 2;
    }
    while (!stack.isEmpty()) {
        cout << stack.pop();
    }
    cout << endl;
}
bool isPalindrome(string str) {
    LinkedStackInt stack;
    for (char c : str) {
        stack.push(c);
    }
    for (char c : str) {
        if (c != stack.pop()) {
            return false;
        }
    }
    return true;
}
int main() {
    StackInt stack(10);
    stack.push(1);
    stack.push(2);
    stack.push(3);
    cout << "Top element: " << stack.peek() << endl;
    LinkedStackInt linkedStack;
    linkedStack.push(1);
    linkedStack.push(2);
    linkedStack.push(3);
    cout << "Top element in linked stack: " << linkedStack.peek() << endl;
    decimalToBinary(10);
    string str = "madam";
    if (isPalindrome(str)) {
        cout << str << " is a palindrome." << endl;
    } else {
        cout << str << " is not a palindrome." << endl;
    }
    return 0;
}

