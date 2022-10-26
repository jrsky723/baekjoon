#include <bits/stdc++.h>
using namespace std;

const int MAX = 10000;
int r, c, st, en, ans;
int dx[3] = {-1, 0, 1};
string board[MAX + 5];
bool finish[MAX + 5][505];
bool OOB(int x, int y) { return x < 0 || x >= r || y < 0 || y >= c; }

void dfs(int px, int py, int x, int y) {
  board[x][y] = 'x';
  if (y == en || finish[x][y]) {
    finish[px][py] = true;
    return;
  }
  for (int dir = 0; dir < 3; dir++) {
    int nx = x + dx[dir];
    int ny = y + 1;
    if (OOB(nx, ny) || board[nx][ny] == 'x') continue;
    dfs(x, y, nx, ny);
    if (finish[x][y]) break;
  }
  if (finish[x][y]) finish[px][py] = true;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> r >> c;
  for (int i = 0; i < r; i++) cin >> board[i];
  st = 0, en = c - 1;
  for (int i = 0; i < r; i++) dfs(i, st, i, st);
  for (int i = 0; i < r; i++)
    if (board[i][en] == 'x') ans++;
  cout << ans;
}