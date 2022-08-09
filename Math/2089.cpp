#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  if (n == 0) {
    cout << "0";
    return 0;
  }
  string ans;
  while (n) {
    if (n % -2) {
      ans += "1";
      n = (n - 1) / -2;
    } else {
      ans += "0";
      n /= -2;
    }
  }
  reverse(ans.begin(), ans.end());
  cout << ans << '\n';
  return 0;
}