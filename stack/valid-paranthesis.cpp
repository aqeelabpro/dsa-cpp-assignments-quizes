#include<iostream>
using namespace std;


class Node {
    public:
        char data;
        Node* next;
        Node(char d) : data(d), next(nullptr) {}
};

class Stack {
    Node* top;
public:
    Stack() { top = nullptr; }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(char c) {
        Node* n = new Node(c);
        n->next = top;
        top = n;
    }

    char pop() {
        if (isEmpty()) return '\0';
        char c = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return c;
    }

    char peek() {
        if (isEmpty()) return '\0';
        return top->data;
    }

    bool isValidParanthesis(string paranthesis) {
        Stack stack;
        for(int i = 0; i < paranthesis.length(); i++) {
            char ch = paranthesis[i];
            if(ch == '(' || ch == '{' || ch == '[')
                stack.push(ch);
            else if(ch == ')' || ch == '}' || ch == ']') {
                if(stack.isEmpty()) return false;
                
                char top = stack.pop();
                if(top == '(' && ch != ')' || top == '{' && ch != '}' || top == '[' && ch != ']')
                return false;
            }    
        }
        return stack.isEmpty();
    }
};
int main() {
    Stack stack;
    cout << boolalpha << stack.isValidParanthesis("({[]}");
    return 0;
}