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
class LinkedList {
    private:
        Node* head;
    public:    
        LinkedList() {
            head = nullptr;
        }
        void insertNodeAtBeginning(int data);
        void display();
        bool isEmpty();
        bool isPalindrome();
        Node* reverse();
};

// Insert A Node At Head
void LinkedList::insertNodeAtBeginning(int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

bool LinkedList::isEmpty() {
    return head == nullptr;
}

// Print List
void LinkedList::display() {
    Node* current = head;
    while(current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL\n";
}

bool LinkedList::isPalindrome() {
    if(isEmpty()) {
    }
    Node* original = head;
    Node* reversed = reverse();
    while(original != nullptr && reversed != nullptr) {
        if(original->data != reversed->data)
            return false;
        original = original->next;
        reversed = reversed->next;    
    }
    reverse();// restore the linkedlist back
    return true;
}

Node* LinkedList::reverse() {
    if(isEmpty()) {
        cout << "List Empty, Can't be reversed";
        return nullptr;
    }
    Node* prev = nullptr;
    Node* next = nullptr;
    Node* current = head;
    while(current != nullptr) {
        next = current->next; // point to next element
        current->next = prev; // current->next in reverse
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}
