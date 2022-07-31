#include <bits/stdc++.h>
using namespace std;

pair<int, int> f[100005];
int mon[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int func(int m, int d) {
  int ret = 0;
  for (int i = 0; i < m - 1; i++) ret += mon[i];
  ret += d;
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int m1, d1, m2, d2;
    cin >> m1 >> d1 >> m2 >> d2;
    f[i] = {func(m1, d1), func(m2, d2)};
  }
  sort(f, f + n);
  int ans = 0;
  int t = func(3, 1);
  int end = func(11, 30);
  for (int i = 0; i < n; i++) {
    if (t < f[i].first || t >= f[i].second) continue;
    int cur = i + 1;
    int mx = f[i].second;
    while (t >= f[cur].first) {
      mx = max (mx, f[cur++].second);
      cur++;
    }
    ans++;
    t = mx;
    i = cur;
    if (t > end) break;
  }
  if (t <= end) ans = 0;
  cout << ans;
}