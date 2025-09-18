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
        void insertNodeInMiddle(int data, int key); // Searches for 'key' and inserts a node after it
        void insertNodeAtEnd(int data);
        bool deleteFirstNode();
        bool deleteNode(int key);
        bool deleteLastNode();

        void display();
        bool search(int data);
        Node* mergeSort(Node* head); // Function to sort the linked list using Merge Sort
        bool isEmpty();

        Node* merge(Node* left, Node* right);
        Node* getMiddle(Node* head);
        Node* getHead();
        void setHead(Node* h);
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
    while(current->next->next != nullptr) { // check for element before the node to delete so we can delete the current's next
        current = current->next;
    }
    Node* temp = current->next;
    current->next = nullptr;
    delete temp;
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
    if(head == nullptr || head->next == nullptr)    
        return head;

    Node* middle = getMiddle(head);
    Node* nextOfMiddle = middle->next;  
    middle->next = nullptr;

    Node* left = mergeSort(head);
    Node* right = mergeSort(nextOfMiddle);
    
    Node* sorted = merge(left,right);
    return sorted;  
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
        if(current->data == key) {
            // we found the element we have to insert after
            Node* newNode = new Node(data);
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
    if(head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
    }
    Node* current = head;
    while(current->next != nullptr) {
        if(current->next->data == key) {
            // we found the element we have to delete
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
            return true;
        }
        current = current->next;
    }
    // if we reach here, key was not found
    cout << "Key " << key << " not found. No deletion." << endl;
    return false;
}

Node *LinkedList::getMiddle(Node* head) {
    if(head == nullptr) {
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


Node* LinkedList::getHead() { return head; }
void LinkedList::setHead(Node* h) { head = h; }


// ====================== MAIN ======================
int main() {
    LinkedList list;

    cout << "Inserting at end: 10, 20, 30\n";
    list.insertNodeAtEnd(10);
    list.insertNodeAtEnd(20);
    list.insertNodeAtEnd(30);
    list.display();

    cout << "Inserting at beginning: 5\n";
    list.insertNodeAtBeginning(5);
    list.display();

    cout << "Inserting 15 after 10\n";
    list.insertNodeInMiddle(15, 10);
    list.display();

    cout << "Searching for 20: " << (list.search(20) ? "Found" : "Not Found") << endl;
    cout << "Searching for 99: " << (list.search(99) ? "Found" : "Not Found") << endl;

    cout << "Deleting first node\n";
    list.deleteFirstNode();
    list.display();

    cout << "Deleting last node\n";
    list.deleteLastNode();
    list.display();

    cout << "Deleting node with key 15\n";
    list.deleteNode(15);
    list.display();

    cout << "Adding unsorted elements: 40, 25, 5, 60\n";
    list.insertNodeAtEnd(40);
    list.insertNodeAtEnd(25);
    list.insertNodeAtEnd(5);
    list.insertNodeAtEnd(60);
    list.display();

    cout << "Sorting list using merge sort...\n";
    Node* newHead = list.mergeSort(list.getHead());
    list.setHead(newHead);
    list.display();

    return 0;
}