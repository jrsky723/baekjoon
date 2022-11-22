#include <bits/stdc++.h>
using namespace std;
int S;
void add(int x) { S |= (1 << x); }
void remove(int x) { S &= ~(1 << x); }
bool check(int x) { return S & (1 << x); }
void toggle(int x) {
  if (check(x))
    remove(x);
  else
    add(x);
}
void all() { S = (1 << 21) - 1; }
void empty() { S = 0; }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    string s;
    int x;
    cin >> s;
    if (s == "all")
      all();
    else if (s == "empty")
      empty();
    else {
      cin >> x;
      if (s == "add")
        add(x);
      else if (s == "remove")
        remove(x);
      else if (s == "check")
        cout << check(x) << '\n';
      else
        toggle(x);
    }
  }
}