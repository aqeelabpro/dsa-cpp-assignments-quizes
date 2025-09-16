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
        Node* getMiddle();
        Node* reverse(Node* head);
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
        return true;
    }
    Node* secondHalf = reverse(getMiddle());
    Node* firstHalf = head;
    while(secondHalf) {
        int firstData = firstHalf->data;
        int secondData = secondHalf->data;
        if(firstHalf->data != secondHalf->data) {
            return false;
        }
        secondHalf = secondHalf->next;
        firstHalf = firstHalf->next;
    }
    return true;
}

Node* LinkedList::reverse(Node* node) {
    if(isEmpty()) {
        cout << "List Empty, Can't be reversed";
        return nullptr;
    }
    Node* prev = nullptr;
    Node* next = nullptr;
    Node* current = node;
    while(current != nullptr) {
        int data = current->data;
        // cout << current->data << "  ";
        next = current->next; // point to next element
        current->next = prev; // current->next in reverse
        prev = current;
        current = next;
    }
    return prev;
}

Node *LinkedList::getMiddle() {
    if(isEmpty()) {
        return nullptr;
    }
    Node* slow = head;
    Node* fast = head;
    while(fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}



int main() {
    LinkedList list1;
    list1.insertNodeAtBeginning(1);
    list1.insertNodeAtBeginning(2);
    list1.insertNodeAtBeginning(3);
    list1.insertNodeAtBeginning(2);
    list1.insertNodeAtBeginning(1);

    cout << "List 1: ";
    list1.display();
    cout << "Is Palindrome? " << (list1.isPalindrome() ? "Yes" : "No") << endl;

    LinkedList list2;
    list2.insertNodeAtBeginning(1);
    list2.insertNodeAtBeginning(2);
    list2.insertNodeAtBeginning(3);
    list2.insertNodeAtBeginning(2);
    list2.insertNodeAtBeginning(1);

    cout << "\nList 2: ";
    list2.display();
    cout << "Is Palindrome? " << (list2.isPalindrome() ? "Yes" : "No") << endl;

    LinkedList list3;
    list3.insertNodeAtBeginning(1);
    list3.insertNodeAtBeginning(2);
    list3.insertNodeAtBeginning(3);

    cout << "\nList 3: ";
    list3.display();
    cout << "Is Palindrome? " << (list3.isPalindrome() ? "Yes" : "No") << endl;

    return 0;
}