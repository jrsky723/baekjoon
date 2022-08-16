#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    priority_queue<ll,vector<ll>, greater<ll>> pq;
    ll ans = 0;
    int k;
    cin >> k;   
    for (int i = 0; i < k; i++) {
      ll x;
      cin >> x;
      pq.push(x);
    }
    while (pq.size() > 1) {
      ll x1 = pq.top(); pq.pop();
      ll x2 = pq.top(); pq.pop();
      ans += x1 + x2;
      pq.push(x1 + x2);
    }
    cout << ans << '\n';
  }
}