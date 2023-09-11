#include <bits/stdc++.h>
using namespace std;

bool isChar(char c) {
    return c >= 'A' && c <= 'Z';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    stack <char> st;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (isChar(s[i])) {
            cout << s[i];
            continue;
        }
        if (s[i] == '(') {
            st.push(s[i]);
        }
        else if (s[i] == ')') {
            while (st.top() != '(') {
                cout << st.top();
                st.pop();
            }
            st.pop();
        }
        else if (s[i] == '*' || s[i] == '/') {
            while (!st.empty() && (st.top() == '*' || st.top() == '/')) {
                cout << st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        else if (s[i] == '+' || s[i] == '-') {
            while (!st.empty() && st.top() != '(') {
                cout << st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()) {
        cout << st.top();
        st.pop();
    }
    return 0;
}