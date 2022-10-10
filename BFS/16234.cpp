#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int board[55][55];
bool vis[55][55];
int N, L, R;
bool isFull;
void bfs(int x, int y) {
  queue <pair<int, int>> q;
  vector<pair<int, int>> vec;
  vis[x][y] = true;
  q.push({x, y});
  vec.push_back({x, y});
  int sum = 0, num = 0;
  while(!q.empty()) {
    auto cur = q.front(); q.pop();
    sum += board[cur.X][cur.Y];
    num++;
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (nx < 0 || nx >= N || ny < 0 || ny >= N || vis[nx][ny]) continue;
      int gap = abs(board[cur.X][cur.Y] - board[nx][ny]);
      if (gap < L || gap > R) continue;
      q.push({nx, ny});
      vec.push_back({nx, ny});
      vis[nx][ny] = true;
    }
  }
  if (vec.size() > 1) isFull = false;
  for (auto p : vec) board[p.X][p.Y] = sum / num;
}
int main(){ 
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> L >> R;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) cin >> board[i][j];
    
  int cnt = 0;
  while (1) {
    isFull = true;
    for (int i = 0; i < N; i++) fill(vis[i], vis[i] + N, 0);

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (vis[i][j]) continue;
        bfs(i, j);
      }
    }
    if (isFull) break;
    cnt++;
  }
  cout << cnt;
}