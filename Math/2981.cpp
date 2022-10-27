#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
  if (a % b == 0) return b;
  return gcd(b, a % b);
}
int n;
int a[100];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  int cur = a[1] - a[0];
  for (int i = 1; i < n - 1; i++) cur = gcd(cur, a[i + 1] - a[i]);
  vector<int> ans = {cur};
  for (int i = 2; i * i <= cur; i++) {
    if (cur % i == 0) {
      if (i == cur / i)
        ans.push_back(i);
      else {
        ans.push_back(i);
        ans.push_back(cur / i);
      }
    }
  }
  sort(ans.begin(), ans.end());
  for (int i : ans) cout << i << ' ';
}