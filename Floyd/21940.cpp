#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int t[202][202];
int ans[202];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) fill(t[i] + 1, t[i] + 1 + n, INF);
  while(m--) {
    int a, b, time;
    cin >> a >> b >> time;
    t[a][b] = time;
  }
  for (int i = 1; i <= n; i++) t[i][i] = 0;

  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        if (t[i][j] > t[i][k] + t[k][j]) t[i][j] = t[i][k] + t[k][j];
  int k;
  cin >> k;
  vector<int> c(k);
  for (int i = 0; i < k; i++) cin >> c[i];
  for (int i = 1; i <= n; i++){
    int dist = 0;
    for (auto st : c) if (dist < t[st][i] + t[i][st]) dist = t[st][i] + t[i][st];
    if (dist > INF) dist = INF;
    ans[i] = dist;
  }
  int mn = *min_element(ans + 1, ans + 1 + n);
  for (int i = 1; i <= n; i++) if(mn == ans[i]) cout << i <<' ';
}