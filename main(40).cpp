#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

void appendNode(Node*& head, Node*& tail, int value) {
    Node* newNode = createNode(value);
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void printList(const Node* head) {
    if (head == nullptr) {
        cout << "Spysok porozhnii." << endl;
        return;
    }
    const Node* current = head;
    while (current != nullptr) {
        cout << current->data << " <-> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

void deleteNode(Node*& head, Node*& tail, Node* target) {
    if (target == nullptr) return;

    if (target->prev != nullptr) {
        target->prev->next = target->next;
    } else {
        head = target->next;
    }

    if (target->next != nullptr) {
        target->next->prev = target->prev;
    } else {
        tail = target->prev;
    }

    delete target;
}

void removeElementsAfterValue(Node*& head, Node*& tail, int targetValue) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == targetValue && current->next != nullptr) {
            deleteNode(head, tail, current->next);
        }
        current = current->next;
    }
}

void clearList(Node*& head, Node*& tail) {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = tail = nullptr;
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    int n, val;
    cout << "Vvedit kilkist elementiv spysku: ";
    cin >> n;
    cout << "Vvedit elementy: ";
    for (int i = 0; i < n; ++i) {
        cin >> val;
        appendNode(head, tail, val);
    }

    cout << "\nPochatkovyi spysok:" << endl;
    printList(head);

    int key;
    cout << "\nVvedit znachennia, pislia yakoho treba vydalyty elementy: ";
    cin >> key;
    removeElementsAfterValue(head, tail, key);

    cout << "\nSpysok pislia vydalennia:" << endl;
    printList(head);

    clearList(head, tail);
    return 0;
}
