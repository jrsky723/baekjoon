#include <bits/stdc++.h>
using namespace std;
const int MAX = 500'000;
int a[MAX + 5];
int b[MAX + 5];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int nA, nB;
  cin >> nA >> nB;
  for (int i = 0; i < nA; i++) cin >> a[i];
  for (int i = 0; i < nB; i++) cin >> b[i];
  sort(a, a + nA);
  sort(b, b + nB);
  vector <int> ans;
  for (int i = 0; i < nA; i++) {
    if (binary_search(b, b + nB, a[i])) continue;
    ans.push_back(a[i]);
  }
  cout << ans.size() << '\n';
  if (ans.size()) {
    for (int i : ans)
      cout << i << ' ';
  }
  return 0;
}