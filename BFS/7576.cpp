#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int MAX = 1000;

int board[MAX + 3][MAX + 3];
int dist[MAX + 3][MAX + 3];
int n, m, ans, rem;

queue<pair<int, int>> Q;

bool OOB(int x, int y) { return x < 0 || y < 0 || x >= n || y >= m; }

void bfs() {
  while (!Q.empty()) {
    auto cur = Q.front();
    Q.pop();
    ans = max(ans, dist[cur.X][cur.Y]);
    for (int d = 0; d < 4; d++) {
      int nx = cur.X + dx[d];
      int ny = cur.Y + dy[d];
      if (OOB(nx, ny) || board[nx][ny] == -1 || dist[nx][ny] >= 0) continue;
      dist[nx][ny] = dist[cur.X][cur.Y] + 1;
      rem--;
      Q.push({nx, ny});
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> m >> n;
  for (int i = 0; i < n; i++) {
    fill(dist[i], dist[i] + m, -1);
    for (int j = 0; j < m; j++) {
      cin >> board[i][j];
      if (board[i][j] == 1) {
        dist[i][j] = 0;
        Q.push({i, j});
      }
      if (board[i][j] == 0) rem++;
    }
  }
  bfs();
  if (rem) ans = -1;
  cout << ans << '\n';
}