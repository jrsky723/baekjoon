#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;
int city[51][51];
int dist[51][51];
vector<pair<int, int>> stores;

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int ans = 0x7f7f7f7f;

  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      cin >> city[i][j];
      if (city[i][j] == 2) stores.push_back({i, j});
    }

  vector<bool> mask(stores.size(), 0);
  fill(mask.begin(), mask.begin() + m, 1);

  do {
    int total = 0;
    queue<pair<int, int>> Q;
    for (int i = 0; i < n; i++) fill(dist[i], dist[i] + n, -1);
    for (int i = 0; i < stores.size(); i++) {
      if (mask[i]) {
        Q.push(stores[i]);
        dist[stores[i].X][stores[i].Y] = 0;
      }
    }
    while (!Q.empty()) {
      auto cur = Q.front();
      Q.pop();
      if (city[cur.X][cur.Y] == 1) total += dist[cur.X][cur.Y];
      for (int dir = 0; dir < 4; dir++) {
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if (OOB(nx, ny) || dist[nx][ny] >= 0) continue;
        dist[nx][ny] = dist[cur.X][cur.Y] + 1;
        Q.push({nx, ny});
      }
    }
    ans = min(total, ans);
  } while (prev_permutation(mask.begin(), mask.end()));
  cout << ans;
}