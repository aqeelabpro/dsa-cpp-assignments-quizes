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

Node* LinkedList::reverse() {
    if(isEmpty()) {
        cout << "List Empty, Can't be reversed";
        return nullptr;
    }
    Node* prev = nullptr;
    Node* next = nullptr;
    Node* current = head;
    while(current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

int main() {
    LinkedList list;

    // Insert some nodes at the beginning
    list.insertNodeAtBeginning(10);
    list.insertNodeAtBeginning(20);
    list.insertNodeAtBeginning(30);
    list.insertNodeAtBeginning(40);
    list.insertNodeAtBeginning(50);

    cout << "Original List:\n";
    list.display();

    // Reverse the list
    list.reverse();

    cout << "Reversed List:\n";
    list.display();

    return 0;
}