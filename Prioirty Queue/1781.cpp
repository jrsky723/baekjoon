#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, ans = 0;
  cin >> n;
  vector<pair<int,int>> v(n);
  for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
  sort(v.begin(), v.end());
  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i = 0; i < n; i++) {
    if (pq.size() < v[i].first) pq.push(v[i].second);
    else {
      if (pq.top() < v[i].second) {
        pq.pop();
        pq.push(v[i].second);
      }
    }
  }
  while (!pq.empty()) {
    ans += pq.top();
    pq.pop();
  }
  cout << ans;
}