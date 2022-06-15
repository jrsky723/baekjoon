#include <bits/stdc++.h>
using namespace std;

string board[5];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool mask[25];
int ans;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 5; i++) cin >> board[i];
  fill(mask + 7, mask + 25, true);
  do {
    bool temp[5][5] = {}, vis[5][5] = {};
    queue<pair<int, int>> Q;
    int adj = 0, dasom = 0;
    for (int i = 0; i < 25; i++)
      if (!mask[i]) {
        int x = i / 5;
        int y = i % 5;
        temp[x][y] = true;
        if (Q.empty()) {
          Q.push({x, y});
          vis[x][y] = true;
        }
      }

    while (!Q.empty()) {
      int x, y;
      tie(x, y) = Q.front();
      Q.pop();
      adj++;
      dasom += board[x][y] == 'S';
      for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
        if (vis[nx][ny] || !temp[nx][ny]) continue;
        Q.push({nx, ny});
        vis[nx][ny] = true;
      }
    }
    ans += (adj >= 7 && dasom >= 4);
  } while (next_permutation(mask, mask + 25));
  cout << ans;
}