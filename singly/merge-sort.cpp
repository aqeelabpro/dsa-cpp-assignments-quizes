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
        void insertNodeInMiddle(int data, int key); 
        void insertNodeAtEnd(int data);
        bool deleteFirstNode();
        bool deleteNode(int key);
        bool deleteLastNode();

        void display();
        bool search(int data);
        Node* mergeSort(Node*);
        bool isEmpty();

        Node* merge(Node* left, Node* right);
        Node* getMiddle(Node* head);
        void mergeSort();
};

// Insert A Node At Head
// Worst Case Time Complexity: O(1)
void LinkedList::insertNodeAtBeginning(int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

// Insert A Node At End
// Worst Case Time Complexity: O(n)
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


// Delete At Head
// Worst Case Time Complexity: O(1)
bool LinkedList::deleteFirstNode() {
    if(isEmpty()) {
        cout << "List is Empty Cannot delete";
        return false;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    temp = nullptr;
    return true;
}

// Deletes Last Node
// Worst Case Time Complexity: O(n)
bool LinkedList::deleteLastNode() {
    if(isEmpty()) {
        cout << "List is Empty Cannot delete";
        return false;
    }
    if(head->next == nullptr) { // only single element
        delete head;
        head = nullptr;
        return true;
    }
    Node* current = head;
    while(current->next->next != nullptr) { // check for element before the node to delete so we can delete the curren's next
        current = current->next;
    }
    Node* temp = current->next;
    delete temp;
    temp = nullptr;
    return true;
}

bool LinkedList::isEmpty() {
    return head == nullptr;
}

// Print List
// Worst Case Time Complexity: O(n)
void LinkedList::display() {
    Node* current = head;
    while(current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL\n";
}


// Search for an element
// Worst Case Time Complexity: O(n)
bool LinkedList::search(int key) {
    if(isEmpty()) {
        return false; // List is Empty, Not Found
    }
    Node* current = head;
    while(current != nullptr) {
        if(current->data == key) {
            return true; // Found
        }
        current = current->next;
    }
    return false;
}

Node* LinkedList::mergeSort(Node* head) {
    if(!head) return nullptr;
    if(head->next == nullptr) return head;

    Node* middle = getMiddle(head);
    Node* nextToMiddle = middle->next;
    middle->next = nullptr;

    Node* left = mergeSort(head);
    Node* right = mergeSort(nextToMiddle);

    return merge(left,right);
}

void LinkedList::mergeSort() {
    head = mergeSort(head);
}


Node* LinkedList::merge(Node* left, Node* right) {
    if(!left) return right;
    if(!right) return left;

    Node* lead = nullptr;

    if(left->data <= right->data) {
        lead = left; // if left is less than right, we make left as head
        left->next = merge(left->next, right);
    }
    else {
        lead = right;
        right->next = merge(left, right->next);
    }
    return lead;
}



// Add In Middle
// Worst Case Time Complexity: O(n)
void LinkedList::insertNodeInMiddle(int data, int key) {
    if(isEmpty()) {
        // list empty, so no element found, no insertion
        return;
    }
    Node* current = head;
    while( current != nullptr) {
        Node* newNode = new Node(data);
        if(current->data == key) {
            // we found the element we have to insert after
            newNode->next = current->next;
            current->next = newNode;
            return;
        }
        current = current->next;
    }
    // if we reach here, key was not found
    cout << "Key " << key << " not found. No insertion." << endl;
}

// Delete Node By Searching For A Key
// Worst Case Time Complexity: O(n)
bool LinkedList::deleteNode(int key) {
    if(isEmpty()) {
        // list empty, so no element found, no deletion
        return false;
    }
    Node* current = head;
    while(current != nullptr) {
        if(current->data == key) {
            // we found the element we have to delete
            delete current;
            return true;
        }
        current = current->next;
    }
    // if we reach here, key was not found
    cout << "Key " << key << " not found. No insertion." << endl;
    return false;
}

int main() {
    LinkedList l1;
    l1.insertNodeAtEnd(1);
    l1.insertNodeAtEnd(3);
    l1.insertNodeAtEnd(5);
    l1.insertNodeAtEnd(7);
    l1.insertNodeAtEnd(2);
    l1.insertNodeAtEnd(4);
    l1.insertNodeAtEnd(6);
    l1.insertNodeAtEnd(8);
    l1.mergeSort();
    l1.display();

    return 0;
}

Node* LinkedList::getMiddle(Node* head) {
    if(isEmpty()) {
        return nullptr;
    }
    Node* slow = head;
    Node* fast = head->next;
    while(fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}