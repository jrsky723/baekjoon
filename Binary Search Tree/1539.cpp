#include <bits/stdc++.h>
using namespace std;
int h[250005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  long long ans = 0;
  set<int> tree;
  while (n--) {
    int val;
    cin >> val;
    tree.insert(val);
    auto it = tree.lower_bound(val);
    int right = 0, left = 0;
    if (next(it) != tree.end()) right = h[*next(it)];
    if (it != tree.begin()) left = h[*prev(it)];
    h[val] = max(right, left) + 1;
  }
  for (auto i : h) ans += i;
  cout << ans;
}