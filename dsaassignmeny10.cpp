//============================================================================
// Name        : assignment9.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <vector>
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
        arraysize = (size/2)+5;
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
    int precedence(char op) {
            if (op == '+' || op == '-') return 1;
            if (op == '*' || op == '/') return 2;
            return 0;
    }
    void infixtopostfix(string &s)
    {
    	vector<char> ans;
    	for(int i=0;i<s.size();i++)
    	{
    		if (s[i] == '(' || s[i] == '{' || s[i] == '[')
    		{
    			push(s[i]);
    		}
    		else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
			{
    			while (array[top] != '(' && array[top] != '{' && array[top] != '[')
    			{
    				char ch=pop();
    				ans.push_back(ch);
    			}
    			pop();
    		}
    		 else if (s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*') {
    			 while (!isempty() && array[top] != '(' && array[top] != '{' && array[top] != '['
    			                    && precedence(array[top]) >= precedence(s[i])) {
    		                    char ch = pop();
    		                    ans.push_back(ch);
    		                }
    		                push(s[i]);
    		            }
    		else{
    			ans.push_back(s[i]);
    		}
    	}
    	for(auto s:ans){
    		cout<<s<<"";
    	}
    }
};
int main() {
    stackmaker st;
    string s = st.inputarray();
    int size = st.countbracket(s);
    st.initializearray(size);
    if (st.checkbalanced(s)) {
        cout << "The equation is balanced" << endl;
        st.infixtopostfix(s);
    } else {
        cout << "The equation is not balanced" << endl;
    }
    return 0;
}
