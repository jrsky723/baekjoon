#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
const int INF = 0x3f3f3f3f;


int n, m;
bool OOB(int x, int y) {
  return x <= 0 || x > n || y <= 0 || y > m;
}
string board[103];
int d[10005];
vector<pair<int, int>> adj[10003];

void dijkstra(int st) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  fill(d + 1, d + 1 + n * m, INF);
  d[st] = 0;
  pq.push({ d[st], st });
  while (!pq.empty()) {
    auto cur = pq.top(); pq.pop();
    if (d[cur.Y] != cur.X) continue;
    for (auto nxt : adj[cur.Y]) {
      if (d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
      d[nxt.Y] = d[cur.Y] + nxt.X;
      pq.push({ d[nxt.Y], nxt.Y });
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> m >> n;
  for (int i = 0; i < n; i++) cin >> board[i];

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int curIdx = (i - 1) * m + j;
      for (int dir = 0; dir < 4; dir++) {
        int nx = i + dx[dir];
        int ny = j + dy[dir];
        if (OOB(nx, ny)) continue;
        int w = 0;
        if (board[nx - 1][ny - 1] == '1') w = 1;
        int nxtIdx = (nx - 1) * m + ny;
        adj[curIdx].push_back({ w, nxtIdx });
      }
    }
  }
  dijkstra(1);
  cout << d[n * m];
}