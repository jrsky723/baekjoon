#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n, m, INum, ans, cnt;
int board[10][10];
bool vis[10][10];

vector<pair<int, int>> stPoints;
vector<tuple<int, int, int>> edge;

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

void fillIsland(int x, int y) {
  stPoints.push_back({x, y});
  queue<pair<int, int>> q;
  vis[x][y] = true;
  q.push({x, y});
  board[x][y] = ++INum;
  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (OOB(nx, ny) || vis[nx][ny] || !board[nx][ny]) continue;
      board[nx][ny] = INum;
      vis[nx][ny] = true;
      q.push({nx, ny});
    }
  }
}

void dfs(int x, int y, int st, int dir, int d) {
  if (board[x][y]) {
    int en = board[x][y];
    if (st != en && d > 1) edge.push_back({d, st, en});
    return;
  }
  int nx = x + dx[dir];
  int ny = y + dy[dir];
  if (!OOB(nx, ny)) dfs(nx, ny, st, dir, d + 1);
}

void getEdges(int x, int y) {
  int st = board[x][y];
  for (int i = 0; i < n; i++) fill(vis[i], vis[i] + m, 0);

  queue<pair<int, int>> q;
  vis[x][y] = true;
  q.push({x, y});
  while (!q.empty()) {
    auto cur = q.front(); q.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (OOB(nx, ny) || vis[nx][ny]) continue;
      if (!board[nx][ny]) {
        dfs(nx, ny, st, dir, 0);
        continue;
      }
      vis[nx][ny] = true;
      q.push({nx, ny});
    }
  }
}

vector<int> p;
int find(int x) {
  if (p[x] < 0) return x;
  return p[x] = find(p[x]);
}

bool is_diff_group(int u, int v) {
  u = find(u), v = find(v);
  if (u == v) return 0;
  if (p[u] == p[v]) p[u]--;
  if (p[u] < p[v]) p[v] = u;
  else p[u] = v;
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> board[i][j];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      if (!vis[i][j] && board[i][j]) fillIsland(i, j);
  }
  for (auto st : stPoints) getEdges(st.X, st.Y);
  sort(edge.begin(), edge.end());
  for (int i = 0; i <= INum; i++) p.push_back(-1);
  for (auto [cost, a, b] : edge) {
    if (!is_diff_group(a, b)) continue;
    ans += cost;
    cnt++;
  }
  if (cnt == INum - 1) cout << ans;
  else cout << -1;
}