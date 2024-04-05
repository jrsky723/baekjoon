#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int getA(int x) {
  double a = sqrt(x);
  if (a == (int)a) {
    return a - 1;
  } else {
    return (int)a;
  }
}

int ans(int x) {
  ll a = getA(x);
  ll mid = ((a + 1) * (a + 1) + a * a) / 2;
  if (x <= mid) {
    return 2 * a;
  } else {
    return 2 * a + 1;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int tc;
  cin >> tc;

  while (tc--) {
    int x, y;
    cin >> x >> y;
    cout << ans(y - x) << '\n';
  }
}
