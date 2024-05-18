#include <bits/stdc++.h>
using namespace std;

string s;
int ans, cur;
bool isMinus;

void calc() { ans += isMinus ? -cur : cur; }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> s;

  for (char c : s) {
    if (c >= '0' && c <= '9') {
      cur *= 10;
      cur += c - '0';
    } else {
      calc();
      if (c == '-') isMinus = true;
      cur = 0;
    }
  }
  calc();
  cout << ans << '\n';
}