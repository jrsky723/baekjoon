#include <bits/stdc++.h>
using namespace std;

#define X get<0>
#define Y get<1>
#define B get<2>
char board[1001][1001];
int dist[1001][1001][2];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  queue<tuple<int, int, bool>> Q;
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < N; i++) 
    for (int j = 0; j < M; j++) 
      cin >> board[i][j];
  dist[0][0][0] = 1;
  Q.push({0, 0, 0});
  int ans = -1;

  while (!Q.empty()) {
    tuple<int, int, bool> cur = Q.front();
    Q.pop();
    if (X(cur) == N - 1 && Y(cur) == M - 1) {
      ans = dist[X(cur)][Y(cur)][B(cur)];
      break;
    }
    for (int dir = 0; dir < 4; dir++) {
      int nx = X(cur) + dx[dir];
      int ny = Y(cur) + dy[dir];
      if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
      //부수기
      if (!B(cur) && board[nx][ny] == '1' && dist[nx][ny][1] == 0) {
        dist[nx][ny][1] = dist[X(cur)][Y(cur)][B(cur)] + 1;
        Q.push({nx, ny, 1});
      }
      //진행
      if (board[nx][ny] == '0' && dist[nx][ny][B(cur)] == 0) {
        dist[nx][ny][B(cur)] = dist[X(cur)][Y(cur)][B(cur)] + 1;
        Q.push({nx, ny, B(cur)});
      }
    }
  }
  cout << ans;
}

//정답코드를 참고했음