#include <bits/stdc++.h>
using namespace std;
int a[10005];
int n;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  long long cnt = 0;
  for (int i = 0; i < n - 2; i++) {
    for (int j = i + 1; j < n - 1; j++) {
      int sum = (a[i] + a[j]);
      int idx1 = lower_bound(a + j + 1, a + n, -sum) - a;
      int idx2 = upper_bound(a + j + 1, a + n, -sum) - a;
      cnt += idx2 - idx1;
    }
  }
  cout << cnt;
  return 0;
}
