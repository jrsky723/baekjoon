#include <bits/stdc++.h>
using namespace std;
int num[11];
void nxt(int i) {
  if (num[i + 1] == 0) {
    if (num[i] == 9)
      for (int j = 0; j <= i + 1; j++) num[j] = j;
    else
      num[i]++;
  } else {
    if (num[i] + 1 >= num[i + 1]) {
      nxt(i + 1);
      num[i] = i;
    } else
      num[i]++;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int idx = 0;
  while (idx < n) {
    nxt(0);
    if (num[10]) break;
    idx++;
  }
  if (idx == n) {
    long long ans = 0, j = 1;
    for (int i = 0; i < 10; i++, j *= 10) ans += j * num[i];
    cout << ans;
  } else  cout << -1;
}