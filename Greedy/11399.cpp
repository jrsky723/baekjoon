#include <bits/stdc++.h>
using namespace std;

int p[1005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> p[i];
  int ans = 0;
  sort(p, p + n);
  for (int i = 0; i < n; i++) ans += p[i] * (n - i);
  cout << ans;
}