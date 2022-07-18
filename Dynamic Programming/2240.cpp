#include <bits/stdc++.h>
using namespace std;
int a[1002];
int d[1001][32];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t,w;
  cin >> t >> w;
  for (int i = 1; i <= t; i++) cin >> a[i];

  int cnt = 0;
  for (int i = 1; i <= t; i++) {
    cnt += a[i] == 1;
    d[i][0] = cnt;
  }
  for (int i = 1; i <= t; i++) 
    for (int j = 1; j <= w; j++)
      d[i][j] = max(d[i - 1][j], d[i - 1][j - 1]) + (a[i] == j % 2 + 1);

  cout << *max_element(d[t], d[t] + w + 1);
}