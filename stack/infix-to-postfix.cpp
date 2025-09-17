#include<iostream>
using namespace std;



class Number {
    public:
        static int isOperator(char c) {
            return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' ||
            c == '<' || c == '>' || c == '=' || c == '!' ||
            c == '&' || c == '|' || c == '^');
        }
        static int precedence(char op) {
            switch (op) {
                case '*': case '/': case '%': return 5;
                case '+': case '-': return 4;
                case '<': case '>': return 3;
                case '=': case '!': return 2;
                case '&': return 1;
                case '^': return 0;
                case '|': return -1;
                default: return -100; // not an operator
            }
        }
         static bool hasHigherPrecedence(char stackOp, char currentOp) {
            return precedence(stackOp) >= precedence(currentOp);
        }
};


struct Node {
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
    string convertInfixToPostfix(string expression) {
        Stack stack;
        string postfix;

        for (int i = 0; i < expression.length(); i++) {
                char ch = expression[i];

                if (ch == ' ') continue; // skip spaces

                else if (!Number::isOperator(ch) && ch != '(' && ch != ')')
                    postfix += ch; // operand
                else if (ch == '(')
                    stack.push(ch);
                else if (ch == ')') {
                    while (!stack.isEmpty() && stack.peek() != '(') {
                        postfix += stack.pop();
                    }
                    if (!stack.isEmpty() && stack.peek() == '(') {
                        stack.pop(); // ✅ remove '('
                    }
                }
                else { // operator
                    while (!stack.isEmpty() && stack.peek() != '(' &&
                        Number::hasHigherPrecedence(stack.peek(), ch)) {
                        postfix += stack.pop();
                    }
                    stack.push(ch);
                }
            }

            while (!stack.isEmpty()) {
                postfix += stack.pop();
            }
        return postfix;
    }
};
int main() {
     Stack s;
    string infix;

    cout << "Enter infix expression: ";
    getline(cin, infix);   // read whole expression with spaces if needed

    cout << "Infix: " << infix << endl;
    cout << "Postfix: " << s.convertInfixToPostfix(infix) << endl;

    return 0;
}