#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(ll n, ll aUnit, ll aCost, ll bUnit, ll bCost) {
  ll mn = 1e18 + 1;
  ll lcmAB = lcm(aUnit, bUnit);
  int aBundle = 0;
  while (aUnit * aBundle < lcmAB) {
    if(n <= aUnit * aBundle) {
      mn = min(aCost * aBundle, mn);
      break;
    }
    ll rem = n - aUnit * aBundle;
    ll bBundle = (rem - 1) / bUnit + 1;
    ll cost = aCost * aBundle + bCost * bBundle;
    mn = min(cost, mn);
    aBundle++;
  }
  cout << mn;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n, aUnit, aCost, bUnit, bCost;
  cin >> n >> aUnit >> aCost >> bUnit >> bCost;
  if(bCost * aUnit < aCost * bUnit) 
    solve(n, aUnit, aCost, bUnit, bCost);
  else 
    solve(n, bUnit, bCost, aUnit, aCost);
}