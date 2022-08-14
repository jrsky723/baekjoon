#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<ll, ll> um;
ll n, p, q;
ll a(ll i) {
  if (um[i])
    return um[i];
  else {
    ll ret = a(i / p) + a(i / q);
    um[i] = ret;
    return ret;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> p >> q;
  um[0] = 1;
  cout << a(n);
}