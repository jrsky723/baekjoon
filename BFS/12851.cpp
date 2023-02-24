#include <bits/stdc++.h>
using namespace std;

const int MAX = 100000;
int n, k, ways, minTime = 1e9;
int d[MAX + 1];

bool OOB(int x) { return x < 0 || x > MAX; }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  fill(d, d + MAX + 1, -1);
  queue<int> q;
  q.push(n);
  d[n] = 0;
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    if (d[x] > minTime) break;
    if (x == k) {
      minTime = d[x];
      ways++;
      continue;
    }
    for (int nx : {x - 1, x + 1, x * 2}) {
      if (OOB(nx)) continue;
      if (d[nx] == -1 || d[nx] == d[x] + 1) {
        d[nx] = d[x] + 1;
        q.push(nx);
      }
    }
  }
  cout << minTime << '\n' << ways << '\n';
}