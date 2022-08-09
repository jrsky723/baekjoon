#include <bits/stdc++.h>
using namespace std;

int u[105][10005];
vector<int> uni[105];
int m, n;

bool solve(int u1, int u2) {
  int cnt = 0;
  for (int i = 0; i < n; i++)
    if (u[u1][i] == u[u2][i]) cnt++;
  return n == cnt;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> m >> n;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> u[i][j];
      uni[i].push_back(u[i][j]);
    }
  }
  for (int i = 0; i < m; i++) {
    sort(uni[i].begin(), uni[i].end());
    uni[i].erase(unique(uni[i].begin(), uni[i].end()), uni[i].end());
    for (int j = 0; j < n; j++)
      u[i][j] =
          lower_bound(uni[i].begin(), uni[i].end(), u[i][j]) - uni[i].begin();
  }
  int ans = 0;
  for (int i = 0; i < m; i++)
    for (int j = i + 1; j < m; j++)
      if (solve(i, j)) ans++;
  cout << ans;
}