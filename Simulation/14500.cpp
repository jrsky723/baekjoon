#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int board[501][501];

bool linked(pair<int, int> p1, pair<int, int> p2) {
  return ((abs(p1.X - p2.X) + abs(p1.Y - p2.Y)) == 1);
}

int tSum(vector<pair<int, int>> tet, int x, int y){
  int sum = 0;
  for (auto cur : tet) sum += board[cur.X + x][cur.Y + y];
  return sum;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, ans = 0;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> board[i][j];

  vector<int> mask(16, 1);
  for (int i = 0; i < 4; i++) mask[i] = 0;
  do {
    vector<pair<int, int>> tet;
    for (int i = 0; i < 16; i++) {
      if (mask[i]) continue;
      tet.push_back({i / 4, i % 4});
      if (tet.size() == 4) break;
    }
    queue<int> Q;
    Q.push(0);
    bool vis[4] = {1, 0, 0, 0};
    int link = 0;
    while (!Q.empty()) {
      int cur = Q.front(); Q.pop();
      link++;
      for (int i = 1; i < 4; i++) {
        if (!linked(tet[cur], tet[i]) || vis[i]) continue;
        Q.push(i);
        vis[i] = 1;
      }
    }
    if (link < 4) continue;
    for (int i = 0; i <= n - 4; i++) 
      for (int j = 0; j <= m - 4; j++) 
        ans = max(tSum(tet, i, j), ans);

  } while (next_permutation(mask.begin(), mask.end()));

  cout << ans;
}