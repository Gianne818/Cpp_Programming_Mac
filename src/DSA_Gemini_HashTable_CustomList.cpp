#include <iostream>
#include <string>

using namespace std;

// ===================================================================
// Step 1: Define our own custom LinkedList to store strings.
// This replaces `std::list`.
// ===================================================================

// Node for a singly linked list storing strings
struct Node {
    string data;
    Node* next;

    Node(string val) : data(val), next(nullptr) {}
};

// A simple LinkedList class to manage a chain of nodes
class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    // Destructor to prevent memory leaks by cleaning up all nodes.
    // This is automatically called when the hash table array goes out of scope.
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nodeToDelete = current;
            current = current->next;
            delete nodeToDelete;
        }
    }

    // Adds a new value to the end of the list (our "chain")
    void addNodeToList(string value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Searches for a value in the list. Returns true if found, false otherwise.
    bool contains(string value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // A helper to display the contents of the list for visualization
    void display() const {
        Node* current = head;
        if (current == nullptr) {
            cout << "empty" << endl;
            return;
        }
        while (current != nullptr) {
            cout << " -> \"" << current->data << "\"";
            current = current->next;
        }
        cout << endl;
    }
};

// ===================================================================
// Step 2: Implement the Hash Table using our custom LinkedList.
// ===================================================================

const int SIZE = 10;
LinkedList myHashSet[SIZE]; // Each index is our custom linked list – an array of lists

int hashFunction(string value) {
    int sum = 0;
    for (char c : value)
        sum += int(c);
    return sum % SIZE;
}

void add(string value) {
    int index = hashFunction(value);
    // To handle collisions, we just add the new value to the linked list at that index.
    // First, check for duplicates using our list's `contains` method.
    if (myHashSet[index].contains(value)) {
        return; // Avoid duplicates
    }
    // If it's not a duplicate, add it to the chain.
    myHashSet[index].addNodeToList(value);
}

bool search(string value) {
    int index = hashFunction(value);
    // The search is delegated to our custom list's `contains` method.
    return myHashSet[index].contains(value);
}

int main() {
    add("Lisa");
    add("Stuart"); // Causes a collision with "Lisa" at index 3
    cout << "Contains Stuart? " << (search("Stuart") ? "Yes" : "No") << endl;

    cout << "\nVisualizing the hash table state:" << endl;
    for (int i = 0; i < SIZE; ++i) {
        cout << "Bucket " << i << ":";
        myHashSet[i].display();
    }
    return 0;
}