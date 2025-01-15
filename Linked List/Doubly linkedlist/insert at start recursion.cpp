#include <iostream>
using namespace std;

class Node {
public:
    Node* prev;
    int data;
    Node* next;

    Node(int value) {
        data = value;
        prev = NULL;
        next = NULL;
    }
};

Node* insertstart(int arr[], int index, int size, Node* back) {
    if (index == size) {
        return back; // Base case: return the current head of the list
    }

    Node* temp = new Node(arr[index]); // Create a new node
    temp->next = back; // Point new node's 'next' to the current head

    if (back != NULL) {
        back->prev = temp; // Update the previous pointer of the current head
    }

    return insertstart(arr, index + 1, size, temp); // Recurse with the next index
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    Node* head = NULL;

    // Build the doubly linked list
    head = insertstart(arr, 0, 5, NULL);

    // Print the list
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}
