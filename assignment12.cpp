#include <iostream>
#include <algorithm>  // For std::sort

using namespace std;

const int MAX_SIZE = 10;  // Maximum size of the priority queue

// Template class for items in the priority queue
template <typename T>
class PriorityItem {
public:
    T data;
    int priority;

    // Constructor
    PriorityItem() : data(T()), priority(0) {}  // Default constructor
    PriorityItem(T d, int p) : data(d), priority(p) {}

    // Overloading <= operator for comparison based on priority
    bool operator<=(const PriorityItem& other) const {
        return this->priority >= other.priority;  // Higher priority comes first
    }
};

// Priority Queue class using a fixed-size array
template <typename T>
class PriorityQueue {
private:
    PriorityItem<T> queue[MAX_SIZE];  // Fixed-size array to store the queue
    int size;  // Current number of items in the queue

public:
    // Constructor to initialize the queue size
    PriorityQueue() : size(0) {}

    // Insert an item into the queue
    void enqueue(T data, int priority) {
        if (size == MAX_SIZE) {
            cerr << "Queue is full!\n";
            return;
        }
        // Insert the new item at the end
        queue[size] = PriorityItem<T>(data, priority);
        size++;

        // Sort the queue by priority (highest priority first)
        sort(queue, queue + size, [](const PriorityItem<T>& a, const PriorityItem<T>& b) {
            return a.priority > b.priority;
        });
    }

    // Remove and return the item with the highest priority
    T dequeue() {
        if (isEmpty()) {
            cerr << "Queue is empty!\n";
            exit(EXIT_FAILURE);
        }
        T highestPriorityItem = queue[0].data;  // Item at the front has the highest priority

        // Shift all elements to the left after removing the highest-priority item
        for (int i = 1; i < size; i++) {
            queue[i - 1] = queue[i];
        }

        size--;  // Decrease the size of the queue
        return highestPriorityItem;
    }

    // Check if the queue is empty
    bool isEmpty() const {
        return size == 0;
    }

    // Print the queue (for debugging purposes)
    void printQueue() const {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue (data, priority): ";
        for (int i = 0; i < size; i++) {
            cout << "(" << queue[i].data << ", " << queue[i].priority << ") ";
        }
        cout << endl;
    }
};

// Main function to test the priority queue
int main() {
    // Create a priority queue of strings
    PriorityQueue<string> pq;

    // Enqueue some items
    pq.enqueue("Task1", 2);
    pq.enqueue("Task2", 5);
    pq.enqueue("Task3", 1);
    pq.enqueue("Task4", 4);

    // Print the queue
    pq.printQueue();

    // Dequeue and print items
    cout << "Dequeued: " << pq.dequeue() << endl;
    pq.printQueue();

    cout << "Dequeued: " << pq.dequeue() << endl;
    pq.printQueue();

    return 0;
}
