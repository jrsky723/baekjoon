#include <bits/stdc++.h>
using namespace std;
int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int n, m, k;
string board[12];
unordered_map<string, int> slist;
void put(int x, int y, string s) {
  slist[s]++;
  if (s.size() == 5) return;
  for (int dir = 0; dir < 8; dir++) {
    int nx = (x + dx[dir] + n) % n;
    int ny = (y + dy[dir] + m) % m;
    put(nx, ny, s + board[nx][ny]);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) cin >> board[i];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      string s;
      s += board[i][j];
      put(i, j, s);
    }
  }
  while (k--) {
    string query;
    cin >> query;
    cout << slist[query] << '\n';
  }
}