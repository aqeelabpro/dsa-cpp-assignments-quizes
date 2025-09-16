#include<iostream>
using namespace std;


class Node {
    public:
        int data;
        Node* next;
    public:
        Node(int data) {
            next = nullptr;
            this->data = data;
        }
};
class CircularLinkedList {
    private:
        Node* head;
    public:    
        CircularLinkedList() {
            head = nullptr;
        }
        void insertNodeAtEnd(int data);
        void display();
        bool isEmpty();
};

void CircularLinkedList::insertNodeAtEnd(int data) {
    Node* newNode = new Node(data);
    if(isEmpty()) {
        head = newNode;
        head->next = head;
        return;
    }
    Node* current = head;
    while(current->next != head) {
        current = current->next;
    }
    current->next = newNode;
    newNode->next = head;
}

bool CircularLinkedList::isEmpty() {
    return head == nullptr;
}

void CircularLinkedList::display() {
    Node* current = head;
    do {
        cout << current->data << " -> ";
        current = current->next;
    }
    while(current != head);
    cout << "NULL\n";
}


int main() {


    CircularLinkedList cll;
    cll.insertNodeAtEnd(10);
    cll.insertNodeAtEnd(20);
    cll.insertNodeAtEnd(30);
    cll.display();
}