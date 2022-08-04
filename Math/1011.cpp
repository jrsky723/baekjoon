#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll solve(ll k) {
  return floor(2 * sqrt(k) - 1e-9);
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int tc;
  cin >> tc;
  ll x, y;
  while (tc--) {
    cin >> x >> y;
    cout << solve(y - x) << '\n';
  }
}