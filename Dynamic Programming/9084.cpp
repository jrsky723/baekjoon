#include <bits/stdc++.h>
using namespace std;

int c[25];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> c[i];
    cin >> m;
    int d[10005] = {};
    d[0] = 1;
    for (int i = 0; i < n; i++)
      for (int j = c[i]; j <= m; j++)
        d[j] += d[j - c[i]];
    cout << d[m] << '\n';
  }
}
//정답과 동일
