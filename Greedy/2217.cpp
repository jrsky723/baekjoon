#include <bits/stdc++.h>
using namespace std;

int r[100005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> r[i];
  sort (r, r + n);
  int ans = 0;
  for (int i = 1; i <= n; i++)
    ans = max(ans, r[n - i] * i);
  cout << ans;
}