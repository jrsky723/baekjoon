#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7f7f7f7f;
int a[1005];
int d[1005], rd[1005];
int n;
void func(int arr[], int st, int en) {
  int d = 1;
  if (st > en) d = -1;
  vector<int > v = {INF};
  for (int i = st; i != en; i += d) {
    if (a[i] > v.back()) v.push_back(a[i]);
    else {
      int idx = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
      v[idx] = a[i];
    }
    arr[i] = v.size();
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  func(d, 0, n);
  func(rd, n - 1, -1);
  int ans = 0;
  for (int i = 0; i < n; i++) ans = max(ans, d[i] + rd[i] - 1);
  cout << ans;
  return 0;
}