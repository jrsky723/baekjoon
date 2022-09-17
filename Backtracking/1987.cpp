#include <bits/stdc++.h>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool chk[26];
string board[22];
int r, c;
int mx;
void dfs(int x, int y, int k) {
  chk[board[x][y] - 'A'] = true;
  for (int dir = 0; dir < 4; dir++) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
    if (chk[board[nx][ny] - 'A']) continue;
    dfs(nx, ny, k + 1);
  }
  mx = max(mx, k);
  chk[board[x][y] - 'A'] = false;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> r >> c;
  for (int i = 0; i < r; i++) cin >> board[i];
  dfs(0, 0, 1);
  cout << mx;
}