#include <bits/stdc++.h>
using namespace std;

#define X first 
#define Y second 
const int MAX = 500, INF = 0x3f3f3f3f;
int n, m;
bool cycle;
vector<pair<int, int>> adj[MAX + 5];
long long d[MAX + 5];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({b,c});
  }
  fill(d + 1, d + 1 + n, INF);
  d[1] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (auto nxt : adj[j]) {
        if (d[j] != INF && d[nxt.X] > d[j] + nxt.Y) {
          d[nxt.X] = d[j] + nxt.Y;
          if (i == n) cycle = true;
        }
      }
    }
  }
  if (cycle) cout << -1 << '\n';
  else {
    for (int i = 2; i <= n; i++) 
      cout << (d[i] != INF ? d[i] : -1) <<'\n';
  }
}