#include <bits/stdc++.h>
using namespace std;
const int MAX = 10000001;
typedef long long ll;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll a, b;
  cin >> a >> b;
  vector<bool> state(MAX, 1);
  state[1] = false;
  for (int i = 2; (i * i) <= MAX; i++) {
    if (!state[i]) continue;
    for (int j = i * i; j <= MAX; j += i) state[j] = false;
  }
  int ans = 0;
  for (ll i = 2; i * i <= b; i++) {
    if (state[i]) {
      ll j = i;
      while (j <= b / i) {
        j *= i;
        if (j >= a) ans++;
      }
    }
  }
  cout << ans;
}