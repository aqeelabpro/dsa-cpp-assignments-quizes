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
        
        Node* getHead() {
            return head;
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

        // swap the kth node values (not nodes) as given
        void swapNodeValues(Node* head, int k) {
            if(isEmpty()) return; // cannot swap as list empty
            if(head->next == nullptr) return; // only single, no need for swap
            
            // find kth node from beginning
            Node* currentHead = head;
            for(int i = 1; i < k; i++) {
                currentHead = currentHead->next;
            }
            
            // find kth node from end
            Node* currentTail = tail;
            for(int i = 1; i < k; i++) {
                currentTail = currentTail->prev;
            }

            int temp = currentHead->data;
            currentHead->data = currentTail->data;
            currentTail->data = temp;
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


Node* mergeSorted(Node* head1, Node* head2) {
    if(!head1) return head2;
    if(!head2) return head1;

    Node* head = nullptr;

    if(head1->data <= head2->data) {
        head = head1;
        head->next = mergeSorted(head1->next, head2);
        if(head->next) head->next->prev = head;
    }
    else {
        head = head2;
        head->next = mergeSorted(head1, head2->next);
        if(head->next) head->next->prev = head;
    }
    return head;
}

int main() {
    DoublyLinkedList l1;
    l1.push_front(5);
    l1.push_front(3);
    l1.push_front(1);

    DoublyLinkedList l2;
    l2.push_front(6);
    l2.push_front(4);
    l2.push_front(2);

    
    Node* merged = mergeSorted(l1.getHead(),l2.getHead());


    while(merged) {
        cout << merged->data << " -> ";
        merged = merged->next;
    }
    cout << " NULL ";

    // list.printList();

    // list.swapNodeValues(list.getHead(), 2);

    // list.printList();
}