#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000'000'000;
int comb[202][102];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  comb[0][0] = 1;

  for (int i = 1; i <= n + m; i++) {
    comb[i][0] = 1;
    for (int j = 1; (j < i && j <= m); j++) {
      comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]);
      if (comb[i][j] > MAX) comb[i][j] = MAX + 1;
    }
    if(i <= m) comb[i][i] = 1;
  }
  if(comb[n + m][m] < k) {
    cout << -1;
    return 0;
  }
  k--;
  for (int i = m + n - 1; i >= 0; i--) {
    if(i >= m && comb[i][m] > k) cout << 'a';
    else {
      cout << 'z';
      k -= comb[i][m];
      m--;
    }
  }
  return 0;
}