#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, d, k, c;
  cin >> n >> d >> k >> c;
  vector<int> vec(2 * n);
  vector<int> chk(d + 1, 0);
  for (int i = 0; i < n; i++) {
    cin >> vec[i];
    vec[i + n] = vec[i];
  }
  int ans = 1;
  int eatcnt = 0;
  int kindcnt = 1;
  chk[c]++;
  int en = 0;
  for (int st = 0; st < 2 * n; st++) {
    while (en < 2 * n && eatcnt < k) {
      if (chk[vec[en]] == 0) {
        kindcnt++;
        ans = max(kindcnt, ans);
      }
      chk[vec[en]]++;
      eatcnt++;
      en++;
    }
    eatcnt--;
    chk[vec[st]]--;
    if (chk[vec[st]] == 0) kindcnt--;
  }
  cout << ans;
  return 0;
}