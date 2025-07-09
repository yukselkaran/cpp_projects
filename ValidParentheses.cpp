#include <iostream>
#include <stack>
using namespace std;

bool isParenthesesValid(string expression) {
    stack<char> st;

    for (char c : expression) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        }
        else if (c == ')' || c == '}' || c == ']') {
            if (st.empty()) return false;

            char top = st.top();
            if ((c == ')' && top == '(') ||
                (c == '}' && top == '{') ||
                (c == ']' && top == '[')) {
                st.pop();
            }
            else {
                return false;
            }
        }
    }
    return st.empty();
}

int main() {
    string input;
    cout << "Enter a string of parentheses: ";
    cin >> input;

    if (isParenthesesValid(input))
        cout << "Parentheses are correctly matched." << endl;
    else
        cout << "Parentheses are incorrectly matched!" << endl;

    return 0;
}