#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

string board[14];
int vis[14][8];
int ans = 0;
bool OOB(int x, int y) { return x < 0 || x >= 12 || y < 0 || y >= 6; }

bool puyo(int x, int y) {
  vector<pair<int, int>> cand;
  queue<pair<int, int>> Q;
  Q.push({x, y});
  vis[x][y] = 1;
  while (!Q.empty()) {
    auto cur = Q.front();
    Q.pop();
    cand.push_back(cur);
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (OOB(nx, ny) || vis[nx][ny]) continue;
      if (board[nx][ny] != board[cur.X][cur.Y]) continue;
      vis[nx][ny] = 1;
      Q.push({nx, ny});
    }
  }
  if (cand.size() >= 4) {
    for (auto cur : cand) board[cur.X][cur.Y] = '.';
  }
  return cand.size() >= 4;
}

void tilt() {
  for (int y = 0; y < 6; y++) {
    int idx = 11;
    for (int i = 11; i >= 0; i--) {
      if (board[i][y] == '.') continue;
      swap(board[idx--][y], board[i][y]);
    }
  }
}
int main() {
  for (int i = 0; i < 12; i++) cin >> board[i];
  while (1) {
    bool isPuyo = 0;
    for (int i = 0; i < 12; i++) fill(vis[i], vis[i] + 6, 0);
    for (int i = 0; i < 12; i++)
      for (int j = 0; j < 6; j++)
        if (board[i][j] != '.' && !vis[i][j])
          if (puyo(i, j)) isPuyo = 1;
    if (isPuyo)
      ans++;
    else
      break;
    tilt();
  }
  cout << ans;
}