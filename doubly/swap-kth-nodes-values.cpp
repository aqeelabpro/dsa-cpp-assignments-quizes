#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int data) {
        next = prev = nullptr;
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

    bool isEmpty() {
        return head == nullptr;
    }

    void push_front(int data) {
        Node* newNode = new Node(data);
        if (isEmpty()) {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void swapNodeValues(int k) {
        if (isEmpty()) return;
        if (head->next == nullptr) return;

        Node* currentHead = head;
        for (int i = 1; i < k && currentHead; i++) {
            currentHead = currentHead->next;
        }

        Node* currentTail = tail;
        for (int i = 1; i < k && currentTail; i++) {
            currentTail = currentTail->prev;
        }

        if (!currentHead || !currentTail) return; 

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

int main() {
    DoublyLinkedList list;

    // Insert values: 1 -> 2 -> 3 -> 4 -> 5
    list.push_front(5);
    list.push_front(4);
    list.push_front(3);
    list.push_front(2);
    list.push_front(1);

    cout << "Original List:" << endl;
    list.printList();

    // Swap 2nd node from start with 2nd node from end
    list.swapNodeValues(2);

    cout << "\nAfter Swapping 2nd node from start and end:" << endl;
    list.printList();

    // Swap 1st node from start with 1st from end
    list.swapNodeValues(1);

    cout << "\nAfter Swapping 1st node from start and end:" << endl;
    list.printList();

    return 0;
}
