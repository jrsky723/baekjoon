#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000000;
bool state[MAX + 5];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  fill(state, state + MAX, 1);
  state[1] = false;
  for (int i = 2; i * i <= MAX; i++) {
    if (!state[i]) continue;
    for (int j = i * i; j <= MAX; j += i) state[j] = false;
  }
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    int cnt = 0;
    for (int i = 2; i <= n / 2; i++) {
      if (state[i] && state[n - i]) cnt++;
    }
    cout << cnt << '\n';
  }
}