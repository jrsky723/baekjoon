#include <bits/stdc++.h>
using namespace std;

int a[1001] , d[1001], pre[1001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  fill(d, d + n, 1);
  fill(pre, pre + n, -1);
  for (int i = 0; i < n; i++) cin >> a[i];
  
  for (int i = 0; i < n; i++) 
    for (int j = 0; j < i; j++) 
      if (a[j] < a[i]) {
        if (d[i] < d[j] + 1) {
          d[i] = d[j] + 1;
          pre[i] = j;
        }
      }
  auto it = max_element(d, d + n);
  int cur = it - d;
  int mx = *it;
  vector <int> ans;
  while (cur >= 0) {
    ans.push_back(a[cur]);
    cur = pre[cur];
  }
  cout << mx << '\n';
  for (int i = mx - 1; i >= 0; i--) {
    cout << ans[i] << ' ';
  }
}