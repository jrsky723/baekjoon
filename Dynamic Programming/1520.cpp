#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int a[505][505], d[505][505];
int m, n;
int func(int x, int y) {
  if(d[x][y] != -1) return d[x][y];
  if (x == m && y == n) return 1;
  d[x][y] = 0;
  for (int dir = 0; dir < 4; dir++) {
    int nx = x + dx[dir], ny = y + dy[dir];
    if (nx <= 0 || nx > m || ny <= 0 || ny > n) continue;
    if (a[nx][ny] < a[x][y]) d[x][y] += func(nx, ny);
  }
  return d[x][y];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> m >> n;
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++) cin >> a[i][j], d[i][j] = -1;
  cout << func(1,1);
}