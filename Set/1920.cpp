#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  set<int> s;

  int n, m;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    s.insert(x);
  }
  cin >> m;
  while (m--) {
    int x;
    cin >> x;
    bool ans = 0;
    if (s.find(x) != s.end()) ans = 1;
    cout << ans << '\n';
  }
}