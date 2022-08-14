#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, ans = 1;
    unordered_map<string, int> items;
    cin >> n;
    for (int i = 0; i < n; i++) {
      string name, kind;
      cin >> name >> kind;
      items[kind]++;
    }
    for (auto v : items) ans *= v.second + 1;
    cout << ans - 1 << '\n';
  }
}