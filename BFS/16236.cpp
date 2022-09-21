#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int board[22][22], dist[22][22];

int n, lv = 2, eatCnt, t;

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

pair<int, int> find(int x, int y) {
  for (int i = 0; i < n; i++) fill(dist[i], dist[i] + n, -1);
  queue<pair<int, int>> q;
  vector<pair<int, int>> cand;
  int candD = 0;
  q.push({x, y});
  dist[x][y] = 0;
  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    if (candD != 0 && dist[cur.X][cur.Y] >= candD) continue;
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (OOB(nx, ny) || dist[nx][ny] >= 0 || lv < board[nx][ny]) continue;
      dist[nx][ny] = dist[cur.X][cur.Y] + 1;
      if (board[nx][ny] != 0 && board[nx][ny] < lv) {
        candD = dist[nx][ny];
        cand.push_back({nx,ny});
      }
      q.push({nx, ny});
    }
  }
  if (cand.empty()) return {-1,-1};
  else {
    sort(cand.begin(), cand.end());
    return cand[0];
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  pair<int, int> pos;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> board[i][j];
      if (board[i][j] == 9) {
        pos = {i, j};
        board[i][j] = 0;
      }
    }
  }

  while (1) {
    auto nxt = find(pos.X, pos.Y);
    if (nxt.X == -1 && nxt.Y == -1) break;
    board[nxt.X][nxt.Y] = 0;
    t += dist[nxt.X][nxt.Y];
    eatCnt++;
    if (eatCnt == lv) {
      eatCnt = 0;
      lv++;
    }
    pos = nxt;
  }
  cout << t;
}