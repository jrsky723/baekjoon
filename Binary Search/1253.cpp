#include <bits/stdc++.h>
using namespace std;
int a[2005];
int n;

bool zero() {
  for (int i = 0; i < n; i++)
    if (a[i]) return false;
  return true;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];

  if (zero()) {
    cout << n;
    return 0;
  }
  sort(a, a + n);
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      int idx = lower_bound(a, a + n, a[i] - a[j]) - a;
      if (idx == i || idx == j) continue;
      if (a[idx] + a[j] == a[i]) {
        cnt++;
        break;
      }
    }
  }
  cout << cnt;
}