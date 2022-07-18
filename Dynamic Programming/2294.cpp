#include <bits/stdc++.h>
using namespace std;

const int INF = 0x7f7f7f7f;
int a[105];
int d[10005]; 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  fill(d + 1, d + k + 1, INF);
  d[0] = 0;
  for (int i = 1; i <= n; i++) 
    for (int j = a[i]; j <= k; j++)
      d[j] = min(d[j], d[j - a[i]] + 1);
  if (d[k] == INF) cout << -1;
  else cout << d[k];
}

//정답과 동일
