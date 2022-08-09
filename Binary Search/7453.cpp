#include <bits/stdc++.h>
using namespace std;

int a[4002], b[4002], c[4002], d[4002];
int n;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];
  vector<int> ab;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) ab.push_back(a[i] + b[j]);
  sort(ab.begin(), ab.end());
  long long cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int cd = c[i] + d[j];
      auto ub = upper_bound(ab.begin(), ab.end(), -cd);
      auto lb = lower_bound(ab.begin(), ab.end(), -cd);
      cnt += (ub - lb);
    }
  }
  cout << cnt;
}