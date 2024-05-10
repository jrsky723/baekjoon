#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

const int MAX = 100;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

char board[MAX + 5][MAX + 5];
int dist[MAX + 5][MAX + 5];

int n, m;

bool OOB(int x, int y) { return x < 0 || y < 0 || x >= n || y >= m; }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < s.length(); j++) {
      board[i][j] = s[j];
    }
  }

  queue<pair<int, int>> Q;
  dist[0][0] = 1;
  Q.push({0, 0});

  while (!Q.empty()) {
    auto cur = Q.front();
    Q.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (OOB(nx, ny) || dist[nx][ny] != 0 || board[nx][ny] == '0') continue;
      dist[nx][ny] = dist[cur.X][cur.Y] + 1;
      Q.push({nx, ny});
    }
  }

  cout << dist[n - 1][m - 1] << '\n';
}