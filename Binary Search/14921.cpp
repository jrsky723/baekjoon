#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7f7f7f7f;
int a[100005];
int n;
int find(int idx) {
  int idx2 = lower_bound(a + idx + 1, a + n, -a[idx]) - a;
  int mn = INF;
  int ret = 0;
  for (int i : {-1, 0, 1}) {
    int nx = idx2 + i;
    if (nx < 0  || nx >= n || nx == idx) continue;
    if (abs(a[nx] + a[idx]) < mn) {
      mn = abs(a[nx] + a[idx]);
      ret = nx;
    }
  }
  return ret;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  int mn = INF;
  int ans = 0;
  for (int idx = 0; idx < n - 1; idx++) {
    int idx2 = find(idx);
    if (mn > abs(a[idx] + a[idx2])) {
      mn = abs(a[idx] + a[idx2]);
      ans = a[idx] + a[idx2];
    }
  }
  cout << ans;
}