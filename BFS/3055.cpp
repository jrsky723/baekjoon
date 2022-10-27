#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int r, c;
string board[55];
int w[55][55];
int dist[55][55];
bool OOB(int x, int y) { return x < 0 || x >= r || y < 0 || y >= c; }
void getW() {
  queue<pair<int, int>> q;
  for (int i = 0; i < r; i++) fill(w[i], w[i] + c, -1);
  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++)
      if (board[i][j] == '*') {
        q.push({i, j});
        w[i][j] = 0;
      }
  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (OOB(nx, ny) || w[nx][ny] >= 0) continue;
      if (board[nx][ny] == 'D' || board[nx][ny] == 'X') continue;
      q.push({nx, ny});
      w[nx][ny] = w[cur.X][cur.Y] + 1;
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  pair<int, int> D,S;
  queue<pair<int, int>> q;
  cin >> r >> c;
  for (int i = 0; i < r; i++) {
    cin >> board[i];
    for (int j = 0; j < c; j++) {
      if (board[i][j] =='D') D = {i,j};
      if (board[i][j] =='S') S = {i, j};
    }
  }
  getW();
  for (int i = 0; i < r; i++) fill(dist[i], dist[i] + c, -1);
  q.push(S);
  dist[S.X][S.Y] = 0;
  while(!q.empty()) {
    auto cur = q.front(); q.pop();
    if (board[cur.X][cur.Y] == 'D') break;
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (OOB(nx, ny) || dist[nx][ny] >= 0) continue;
      if (board[nx][ny] == 'X') continue;
      if (w[nx][ny] != -1 && w[nx][ny] <= dist[cur.X][cur.Y] + 1) continue;
      dist[nx][ny] = dist[cur.X][cur.Y] + 1;
      q.push({nx, ny});
    }
  }
  if (dist[D.X][D.Y] == -1) cout << "KAKTUS";
  else cout << dist[D.X][D.Y];
}