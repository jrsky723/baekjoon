#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<bool> state(n + 1, 1);
    for (int k = 2; k <= n; k++) {
      for (int i = k; i <= n; i += k) {
        if (state[i])
          state[i] = 0;
        else
          state[i] = 1;
      }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      if (state[i]) ans++;
    }
    cout << ans << '\n';
  }
}