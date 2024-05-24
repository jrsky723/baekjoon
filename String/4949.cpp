#include <bits/stdc++.h>
using namespace std;

const string EXIT = ".";

string s;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while (1) {
    getline(cin, s);
    if (s == EXIT) break;
    stack<char> stk;
    bool ans = true;
    for (char c : s) {
      switch (c) {
        case '(':
        case '[':
          stk.push(c);
          break;
        case ')':
          if (!stk.empty() && stk.top() == '(')
            stk.pop();
          else
            ans = false;
          break;
        case ']':
          if (!stk.empty() && stk.top() == '[')
            stk.pop();
          else
            ans = false;
          break;
      }
      if (ans == false) break;
    }
    if (!stk.empty()) ans = false;
    cout << (ans ? "yes" : "no") << '\n';
  }
}