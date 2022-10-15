#include <bits/stdc++.h>
using namespace std;
const int MAX = 100000;
#define X first
#define Y second
int f[MAX + 5];
int dp[MAX + 5][101];
int n;
int beauty(int a, int b) { return (a - b) * (a - b); }
int func(int idx, int last){
  if (idx == n) return 0;
  int &ret = dp[idx][last];
  if (ret != -1) return ret;
  ret = func(idx + 1, last);
  if (last == 0) ret = max(ret, func(idx + 1, f[idx]));
  else ret = max(ret, func(idx + 1, f[idx]) + beauty(f[idx], last));
  return ret;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> f[i];
  memset(dp, -1, sizeof(dp));
  cout << func(0, 0);
}