//============================================================================
// Name        : assignment9.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
using namespace std;

class stackmaker {
public:
    int top = -1;
    int arraysize;
    char* array;

    string inputarray() {
        string s;
        cout << "Enter the string: " << endl;
        cin >> s;
        cout << "Entered string is: " << s << endl;
        return s;
    }

    int countbracket(const string& s) {
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[' ||
                s[i] == ')' || s[i] == '}' || s[i] == ']') {
                count++;
            }
        }
        return count;
    }

    void initializearray(int size) {
        arraysize = size/2;
        array = new char[arraysize];
    }

    bool isfull() {
        if (top == arraysize - 1) {
            return true;
        } else {
            return false;
        }
    }

    bool isempty() {
        if (top == -1) {
            return true;
        } else {
            return false;
        }
    }

    void push(char data) {
        if (!isfull()) {
            array[++top] = data;
        } else {
            cout << "The stack is already full" << endl;
        }
    }

    char pop() {
        if (!isempty()) {
            return array[top--];
        } else {
            cout << "The stack is already empty" << endl;
            return '\0';
        }
    }

    bool checkbalanced(string &s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                push(s[i]);
            } else if (s[i] == ')' || s[i] == '}' || s[i] == ']') 
            {
                if (isempty()) return false;
                char ch = pop();
                if ((s[i] == ')' && ch != '(') ||
                    (s[i] == '}' && ch != '{') ||
                    (s[i] == ']' && ch != '[')) {
                    return false;
                }
        }
        }
        return isempty();
    }
};
int main() {
    stackmaker st;
    string s = st.inputarray();
    int size = st.countbracket(s);
    st.initializearray(size);
    if (st.checkbalanced(s)) {
        cout << "The equation is balanced" << endl;
    } else {
        cout << "The equation is not balanced" << endl;
    }
    return 0;
}