#include <iostream>
using namespace std;

class node {
public:
    int data;
    node *next;
    node *prev;
    node(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};

class queue {
public:
    node *front = nullptr;
    node *back = nullptr;
    int current_size = 0;  // To track the current number of elements
    int capacity;          // Maximum allowed size of the queue

    queue(int cap) {       // Initialize queue with a capacity
        front = nullptr;
        back = nullptr;
        capacity = cap;
        current_size = 0;
    }

    bool isempty() {
        return (front == nullptr);
    }

    bool isfull() {        // Check if the queue is full
        return current_size == capacity;
    }

    void frontinsert(int value) {
        if (isfull()) {
            cout << "The queue is full, cannot insert." << endl;
            return;
        }
        node *newnode = new node(value);
        if (isempty()) {
            front = newnode;
            back = newnode;
        } else {
            newnode->next = front;
            front->prev = newnode;
            front = newnode;
        }
        current_size++;    // Increment the size after insertion
    }

    void backinsert(int value) {
        if (isfull()) {
            cout << "The queue is full, cannot insert." << endl;
            return;
        }
        node *newnode = new node(value);
        if (isempty()) {
            front = newnode;
            back = newnode;
        } else {
            back->next = newnode;
            newnode->prev = back;
            back = newnode;
        }
        current_size++;    // Increment the size after insertion
    }

    void frontdelete() {
        if (isempty()) {
            cout << "The queue is already empty." << endl;
            return;
        }
        node *temp = front;
        if (front == back) {
            front = back = nullptr;
        } else {
            front = front->next;
            front->prev = nullptr;
        }
        delete temp;
        current_size--;    // Decrement the size after deletion
    }

    void backdelete() {
        if (isempty()) {
            cout << "The queue is already empty." << endl;
            return;
        }
        node *temp = back;
        if (front == back) {
            front = back = nullptr;
        } else {
            back = back->prev;
            back->next = nullptr;
        }
        delete temp;
        current_size--;    // Decrement the size after deletion
    }

    void display() {
        if (isempty()) {
            cout << "The queue is empty." << endl;
            return;
        }
        node *temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    queue q1(3);  // Create a queue with a capacity of 3
    q1.frontinsert(10);
    q1.frontinsert(20);
    q1.backinsert(30);
    q1.display();
    q1.frontinsert(40);  // This should print "The queue is full"
    q1.display();
    q1.frontdelete();
    q1.display();
    q1.backdelete();
    q1.display();
    return 0;
}
