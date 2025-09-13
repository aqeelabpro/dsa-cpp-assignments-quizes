#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node* prev;
    public:
        Node(int data) {
            next = prev =  nullptr;
            this->data = data;
        }
};


class DoublyLinkedList {
    private:
        Node* head;
        Node* tail;
    public:
        DoublyLinkedList() {
            head = tail = nullptr;
        }   
        
        // Check whether the list is empty.
        // true if the list is empty, false otherwise.
        bool isEmpty() {
            return head == nullptr;
        }
        // push a node by value
        void push_front(int data) {
            Node* newNode = new Node(data);
            if(isEmpty()) {
                head = tail = newNode;
                return;
            }
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        // push a node
        void push_front(Node* node) {
            node->next = head; 
            head->prev = node;
            head = node;
        }

        // move recently accessed element to front
        void access(int val) {
            if(isEmpty()) {
                cout << "List Empty"; // cannot access element
                return;
            }
            Node* current = head;
            while(current != nullptr) {
                if(current->data == val) { // element found to be moved to front
                    
                    if(current == head) return; // no need to move to front as its already head

                    // unlink nodes
                    if(current->prev != nullptr) current->prev->next = current->next; // only update if prev not nullptr
                    if(current->next != nullptr) current->next->prev = current->prev; // only update if next not nullptr

                    if(current == tail) tail = current->prev; // if we are end
                    push_front(current);
                    return;
                }
                current = current->next;
            }
        }
        void printList() {
            Node* temp = head;
            while (temp) {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
    }
};

int main() {
    DoublyLinkedList list;
    list.push_front(7);
    list.push_front(1);
    // list.push_front(2);
    // list.push_front(8);
    // list.push_front(5);

    cout << "Original list: ";
    list.printList();

    cout << "Access 2:" << endl;
    list.access(7);
    list.printList();

    cout << "Access 7:" << endl;
    list.access(7);
    list.printList();

    cout << "Access 8:" << endl;
    list.access(8);
    list.printList();
}