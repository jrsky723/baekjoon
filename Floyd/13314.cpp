#include <bits/stdc++.h>
using namespace std;

int d[102][102];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n = 100;
  for (int i = 1; i <= n - 1; i++) fill(d[i] + 1, d[i] + 1 + n - 1, 1);
  for (int i = 1; i <= n; i++) d[i][i] = 0;
  cout << n << '\n';
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) cout << d[i][j] << ' ';
    cout << '\n';
  }
}
