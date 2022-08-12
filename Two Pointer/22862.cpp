#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
 
  int cnt = 0;   //  홀수 개수
  if(a[0] % 2 == 1) cnt++;
  int en = 0;
  int ans = 0;
  for (int st = 0; st < n; st++) {
    while (en < n - 1 && cnt + a[en + 1] % 2 <= k) {
      en++;
      cnt += a[en] % 2;
    }
    ans = max(ans, en - st + 1 - cnt);
    cnt -= a[st] % 2;
  }
  cout << ans;
  return 0;
}