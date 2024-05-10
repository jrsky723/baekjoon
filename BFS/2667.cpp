#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
typedef pair<int, int> pii;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int MAX = 25;

string board[MAX + 3];
bool vis[MAX + 3][MAX + 3];
vector<int> cnts;
int n;

bool OOB(int x, int y) { return x < 0 || y < 0 || x >= n || y >= n; }

void bfs(pii p) {
  queue<pii> Q;
  Q.push(p);
  cnts.push_back(1);
  vis[p.X][p.Y] = 1;

  while (!Q.empty()) {
    auto cur = Q.front();
    Q.pop();
    for (int d = 0; d < 4; d++) {
      int nx = cur.X + dx[d];
      int ny = cur.Y + dy[d];
      if (OOB(nx, ny) || vis[nx][ny] || board[nx][ny] == '0') continue;
      vis[nx][ny] = true;
      cnts[cnts.size() - 1]++;
      Q.push({nx, ny});
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) cin >> board[i];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (board[i][j] == '0' || vis[i][j]) continue;
      bfs({i, j});
    }
  }

  sort(cnts.begin(), cnts.end());
  cout << cnts.size() << '\n';
  for (int cnt : cnts) cout << cnt << '\n';
}