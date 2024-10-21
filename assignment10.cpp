#include <iostream>
#include <vector>
#include <cctype> // for isdigit
#include <cstdlib> // for atoi
using namespace std;

class stackmaker {
public:
    int top = -1;
    int arraysize;
    int* array; // Change array to int for evaluation of numbers

    string inputarray() {
        string s;
        cout << "Enter the expression: " << endl;
        cin >> s;
        cout << "Entered expression is: " << s << endl;
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
        arraysize = (size/2)+5;
        array = new int[arraysize]; // Initialize array to handle integers
    }

    bool isfull() {
        return top == arraysize - 1;
    }

    bool isempty() {
        return top == -1;
    }

    void push(int data) { // Change data type to int for evaluation
        if (!isfull()) {
            array[++top] = data;
        } else {
            cout << "The stack is already full" << endl;
        }
    }

    int pop() { // Change return type to int
        if (!isempty()) {
            return array[top--];
        } else {
            cout << "The stack is already empty" << endl;
            return -1;
        }
    }

    bool checkbalanced(string &s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                push(s[i]);
            } else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
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

    int precedence(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;
    }

    void infixtopostfix(string &s, vector<char> &ans) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                push(s[i]);
            } else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
                while (array[top] != '(' && array[top] != '{' && array[top] != '[') {
                    char ch = pop();
                    ans.push_back(ch);
                }
                pop(); // remove '(' or '{' or '['
            } else if (s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*') {
                while (!isempty() && array[top] != '(' && array[top] != '{' && array[top] != '['
                       && precedence(array[top]) >= precedence(s[i])) {
                    char ch = pop();
                    ans.push_back(ch);
                }
                push(s[i]);
            } else {
                ans.push_back(s[i]); // if it's a number/variable
            }
        }

        while (!isempty()) {
            char ch = pop();
            ans.push_back(ch);
        }
    }

    int evaluatePostfix(vector<char> &postfix) {
        // Evaluate using the same stackmaker class but pushing integers now
        for (int i = 0; i < postfix.size(); i++) {
            if (isdigit(postfix[i])) {
                push(postfix[i] - '0'); // Convert char to int and push
            } else {
                int val2 = pop();
                int val1 = pop();

                switch (postfix[i]) {
                    case '+': push(val1 + val2); break;
                    case '-': push(val1 - val2); break;
                    case '*': push(val1 * val2); break;
                    case '/': push(val1 / val2); break;
                }
            }
        }
        return pop(); // The final result
    }
};

int main() {
    stackmaker st;
    string s = st.inputarray();
    int size = st.countbracket(s);
    st.initializearray(size);

    if (st.checkbalanced(s)) {
        cout << "The equation is balanced" << endl;
        vector<char> postfix;
        st.infixtopostfix(s, postfix);
        cout << "Postfix expression: ";
        for (char ch : postfix) {
            cout << ch;
        }
        cout << endl;

        int result = st.evaluatePostfix(postfix);
        cout << "Evaluation result: " << result << endl;
    } else {
        cout << "The equation is not balanced" << endl;
    }

    return 0;
}
