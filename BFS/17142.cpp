#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

const int INF = 0x7f7f7f7f;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;
int board[52][52];
int newBoard[52][52];
int dist[52][52];
int ans = INF;
int res;
vector<pair<int, int>> vp;
vector<bool> mask;

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> board[i][j];
      if (board[i][j] == 2) {
        vp.push_back({i, j});
        mask.push_back(0);
      }
      if (board[i][j] == 0) res++;
    }
  }
  for (int i = 0; i < m; i++) mask[i] = 1;
  sort(mask.begin(), mask.end());
  do {
    for (int i = 0; i < n; i++) fill(dist[i], dist[i] + n, -1);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) newBoard[i][j] = board[i][j];
    queue<pair<int, int>> Q;
    for (int idx = 0; idx < mask.size(); idx++) {
      if (mask[idx]) {
        dist[vp[idx].X][vp[idx].Y] = 0;
        Q.push(vp[idx]);
      }
    }
    int mx = 0;
    int cnt = 0;
    while (!Q.empty()) {
      auto cur = Q.front();
      Q.pop();
      if (newBoard[cur.X][cur.Y] == 0) {
        cnt++;
        mx = max(mx, dist[cur.X][cur.Y]);
      }
      for (int dir = 0; dir < 4; dir++) {
        auto nx = cur.X + dx[dir];
        auto ny = cur.Y + dy[dir];
        if (OOB(nx, ny) || newBoard[nx][ny] == 1 || dist[nx][ny] >= 0) continue;
        dist[nx][ny] = dist[cur.X][cur.Y] + 1;
        Q.push({nx, ny});
      }
    }
    if (cnt == res) ans = min(mx, ans);
  } while (next_permutation(mask.begin(), mask.end()));

  if (ans == INF)
    cout << -1 << '\n';
  else
    cout << ans << '\n';
}