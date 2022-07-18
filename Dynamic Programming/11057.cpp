#include <bits/stdc++.h>
using namespace std;

long long d[1005][10];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  fill(d[1], d[1] + 10, 1);
  for (int i = 2; i <= n; i++)
    for (int j = 0; j < 10; j++) {
      for (int k = j; k < 10; k++) d[i][j] += d[i - 1][k];
      d[i][j] %= 10007;
    }

  int ans = 0;
  for (int i = 0; i < 10; i++) ans += d[n][i];
  cout << ans % 10007;
}
//10개의 수 중에 n개를 뽑는다고 생각하면 더 간단하다.