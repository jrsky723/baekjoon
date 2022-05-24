#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[301][301];
bool vis[301][301];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int N, M;
void bfs(int x, int y) {
  queue<pair<int, int>> Q;
  Q.push({x, y});
  vis[x][y] = true;
  while (!Q.empty()) {
    pair<int, int> cur = Q.front();
    Q.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
      if (vis[nx][ny]) continue;
      if (board[nx][ny] == 0) {
        if (board[cur.X][cur.Y] != 0) board[cur.X][cur.Y]--;
      } else {
        Q.push({nx, ny});
        vis[nx][ny] = true;
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) cin >> board[i][j];

  int turn = 0, count;
  while (true) {
    count = 0;
    for (int i = 0; i < N; i++) fill(vis[i], vis[i] + M, 0);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (board[i][j] != 0 && !vis[i][j]) {
          bfs(i, j);
          count++;
        }
      }
    }
    cout<<'\n'<<count<<' '<<turn<<"\n\n";
    
    for (int i = 0; i < N; i++){
      for (int j = 0; j < M; j++)
        cout<<board[i][j]<<' ';
      cout<<'\n';  
    }
    
    if (count >= 2 || count == 0) break;
    turn++;
  }

  if (count == 0)
    cout << 0;
  else
    cout << turn;
}