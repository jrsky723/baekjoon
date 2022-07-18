#include <bits/stdc++.h>
using namespace std;

int a[10002];
int d[10002][3];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  d[1][0] = 0, d[1][1] = d[1][2] = a[1];
  for (int i = 2; i <= n; i++) {
    d[i][0] = max({d[i - 1][0], d[i - 1][1], d[i - 1][2]});
    d[i][1] = d[i - 1][0] + a[i];
    d[i][2] = d[i - 1][1] + a[i];
  }
  cout << max({d[n][0], d[n][1], d[n][2]});
}