#include<iostream>
using namespace std;


class Node {
    public:
        int data;
        Node* next;
        Node(int data) {
            this->data = data;
            this->next = nullptr;
        }    
};


class Stack {
    private:
        Node* top;
    public:
    Stack() {
        top = nullptr;
    }
        bool push(int data) {
            Node* toPush = new Node(data);
            toPush->next = top;
            top = toPush;
            return true;
        }
        bool isEmpty() {
            return top == nullptr;
        }
        bool pop() {
            if(isEmpty()) {
                cout << "Stack Underflow";
                return false;
            }
            Node* temp = top;
            top = top->next;
            delete temp;
            temp = nullptr;
            return true;
        }

        int peek() {
            if(isEmpty()) {
                cout << "Stack Underflow";
                return -1;
            }
            return top->data;
        }
        int eval(string expression) {
            Stack stack;
            for(int i = 0; i < expression.length(); i++) {
                int digit = expression[i] - '0';
                bool isDig = isDigit(expression[i]);
                if(isDig) {
                    stack.push(digit);
                }
                else {
                    int operand2 = stack.peek();
                    stack.pop();
                    
                    int operand1 = stack.peek();
                    stack.pop();
                    
                    int result = getResult(expression[i], operand2, operand1);
                    stack.push(result);
                }
            }
            return stack.peek();
        }
        int isDigit(char digit) {
            return (digit >= '0' && digit <= '9');
        }

        int getResult(char op, int op1, int op2) {
            switch(op) {
                case '+':
                    return op1 + op2;
                break;
                case '-':
                    return op1 - op2;
                break;
                case '/':
                    return op1 / op2;
                break; 
                case '*':
                    return op1 * op2;
                break;  
                case '%':
                    return op1 % op2;
                break;    
            }
        }
};


int main() {
    Stack s;
    int result = s.eval("236*+");
    cout << result;
}