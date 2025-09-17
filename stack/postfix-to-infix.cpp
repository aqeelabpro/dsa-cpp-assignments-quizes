#include <iostream>
using namespace std;

struct Node {
    string data;
    Node* next;
    Node(string d) : data(d), next(nullptr) {}
};

class Stack {
    Node* top;
public:
    Stack() { top = nullptr; }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(string s) {
        Node* n = new Node(s);
        n->next = top;
        top = n;
    }

    string pop() {
        if (isEmpty()) return "";
        string s = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return s;
    }

    string peek() {
        if (isEmpty()) return "";
        return top->data;
    }
};

class Number {
public:
    static bool isOperator(char c) {
        return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' ||
                c == '<' || c == '>' || c == '=' || c == '!' ||
                c == '&' || c == '|' || c == '^');
    }
};

string convertPostfixToInfix(string expression) {
    Stack stack;

    for (int i = 0; i < expression.length(); i++) {
        char ch = expression[i];

        if (!Number::isOperator(ch)) {
            // operand → push as string
            stack.push(string(1, ch));
        }
        else {
            // operator → pop two operands
            string op2 = stack.pop(); // right operand
            string op1 = stack.pop(); // left operand
            string result = "(" + op1 + ch + op2 + ")";
            stack.push(result);
        }
    }

    return stack.pop(); // final expression
}

int main() {
    cout << convertPostfixToInfix("AB+C*") << endl;  
    cout << convertPostfixToInfix("ABC*+") << endl;  
}
