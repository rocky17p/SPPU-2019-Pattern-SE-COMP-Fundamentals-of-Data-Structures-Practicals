#include<iostream>
using namespace std;

class Queue {
public:
    int *q;
    int maxSize;
    int currentsize = 0;
    int start = -1;
    int end = -1;

    Queue(int size) {  
        maxSize = size;
        q = new int[maxSize];
    }

    ~Queue() {   
        delete[] q;
    }

    void push(int x) {
        if (currentsize == maxSize) {
            cout << "Queue is already full" << endl;
            return;
        }
        if (currentsize == 0) {
            start = 0;
            end = 0;
        } else {
            end = (end + 1) % maxSize;
        }
        q[end] = x;
        currentsize++;
    }

    int pop() {
        if (currentsize == 0) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int temp = q[start];
        if (currentsize == 1) {
            start = -1;
            end = -1;
        } else {
            start = (start + 1) % maxSize;
        }
        currentsize--;
        return temp;
    }

    int top() {
        if (currentsize == 0) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return q[start];
    }

    int getSize() {
        return currentsize;
    }

    void display() {
        if (currentsize == 0) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = 0; i < currentsize; i++) {
            cout << q[(start + i) % maxSize] << " ";
        }
        cout << endl;
    }
};

int main() {
    int choice, queueSize;

    cout << "Enter the size of the queue: ";
    cin >> queueSize;

    Queue q1(queueSize);  

    do {
        cout << "Menu" << endl;
        cout << "1. Add" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cin >> choice;
        switch (choice) {
            case 1: {
                int x;
                cout << "Enter the element to be added: ";
                cin >> x;
                q1.push(x);
                break;
            }
            case 2:
                q1.pop();
                break;
            case 3:
                q1.display();
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid choice, please enter from (1-4)" << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}
