#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node* head;
public:
    CircularLinkedList() : head(nullptr) {}

    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            head->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }

    void shiftRight(int k) {
        if (!head) return;
        int n = 1;
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
            n++;
        }
        k = ((k % n) + n) % n;
        if (k == 0) return;

        int steps = n - k;
        Node* newTail = head;
        for (int i = 1; i < steps; i++)
            newTail = newTail->next;

        head = newTail->next;
        newTail->next = head;
    }

    void print(int rounds = 1) {
        if (!head) return;
        Node* temp = head;
        for (int i = 0; i < rounds; i++) {
            do {
                cout << temp->data << " ";
                temp = temp->next;
            } while (temp != head);
            cout << endl;
        }
    }
};

int main() {
    CircularLinkedList cll;
    cll.insert(1);
    cll.insert(2);
    cll.insert(3);

    cout << "Original List:" << endl;
    cll.print();

    cout << "\nShift Right by 2:" << endl;
    cll.shiftRight(2);
    cll.print();

    return 0;
}
