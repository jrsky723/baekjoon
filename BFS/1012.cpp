#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
typedef pair<int, int> pii;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int MAX = 50;

bool board[MAX + 3][MAX + 3];
bool vis[MAX + 3][MAX + 3];

int t, m, n, k, cnt;

bool OOB(int x, int y) { return x < 0 || y < 0 || x >= n || y >= m; }

void init() {
  cnt = 0;
  for (int i = 0; i < n; i++) fill(board[i], board[i] + m, 0);
  for (int i = 0; i < n; i++) fill(vis[i], vis[i] + m, 0);
}

void bfs(int x, int y) {
  queue<pii> Q;
  Q.push({x, y});
  vis[x][y] = true;
  while (!Q.empty()) {
    auto cur = Q.front();
    Q.pop();
    for (int d = 0; d < 4; d++) {
      int nx = cur.X + dx[d];
      int ny = cur.Y + dy[d];
      if (OOB(nx, ny) || vis[nx][ny] || board[nx][ny] == 0) continue;
      vis[nx][ny] = true;
      Q.push({nx, ny});
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> t;
  while (t--) {
    cin >> m >> n >> k;
    init();
    while (k--) {
      int a, b;
      cin >> a >> b;
      board[b][a] = 1;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (vis[i][j] || board[i][j] == 0) continue;
        bfs(i, j);
        cnt++;
      }
    }
    cout << cnt << '\n';
  }
}