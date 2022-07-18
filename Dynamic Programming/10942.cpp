#include <bits/stdc++.h>
using namespace std;

int a[2005] , d[2005][2005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,m;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    d[i][i] = 1;
    if (a[i - 1] == a[i]) d[i - 1][i] = 1;
  }
  for (int gap = 2; gap < n; gap++) {
    for (int i = 1; i <= n - gap; i++) {
      int f = i, t = i + gap;
      if (a[f] == a[t] && d[f + 1][t - 1])  d[f][t] = 1;
    }
  }

  cin >> m;
  while (m--) {
    int f,t;
    cin >> f >> t;
    cout << d[f][t] << '\n';
  }
}
