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
        void insertNodeAtEnd(int data);
        void display();
        bool isEmpty();
        Node **splitIntoKParts(Node *head, int k);
        int getLength(Node *head);
        Node* getHead();
};

Node* LinkedList::getHead() { return head; }
void LinkedList::insertNodeAtBeginning(int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}


void LinkedList::insertNodeAtEnd(int data) {
    Node* newNode = new Node(data);
    if(isEmpty()) {
        head = newNode;
        return;
    }
    Node* current = head;
    while(current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
}

bool LinkedList::isEmpty() {
    return head == nullptr;
}


void LinkedList::display() {
    Node* current = head;
    while(current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL\n";
}

Node** LinkedList::splitIntoKParts(Node* head, int k) {
    int n = getLength(head);
    int maxSizeOfEachPart = n / k;
    int remainder = n % k;
    Node** result = new Node*[k];
    Node* current = head;
    for(int i = 0; i < k; i++) {
        int size = maxSizeOfEachPart + (i < remainder ? 1 : 0);
        if(size == 0) {
            result[i] = nullptr;
            continue;
        }
        result[i] = current;
        for(int j = 1; j < size; j++) {
            if(current) current = current->next;
        }

        if(current) {
            Node* nextPart = current->next;
            current->next = nullptr;
            current = nextPart;
        }
    }
    return result;
}


int LinkedList::getLength(Node* head) {
    int n = 0;
    Node* current = head;
    while (current != nullptr) {
        n++;
        current = current->next;
    }
    return n;
}


int main() {
    LinkedList list;

    // Insert nodes into the linked list
    for (int i = 1; i <= 10; i++) {
        list.insertNodeAtEnd(i);
    }

    cout << "Original List: ";
    list.display();

    int k = 3;  // number of parts
    Node** parts = list.splitIntoKParts(list.getHead(), k);

    cout << "\nSplitting into " << k << " parts:\n";
    for (int i = 0; i < k; i++) {
        cout << "Part " << i + 1 << ": ";
        Node* current = parts[i];
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL\n";
    }

    delete[] parts; // free array of pointers
    return 0;
}
