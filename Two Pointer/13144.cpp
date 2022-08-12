#include <bits/stdc++.h>
using namespace std;
int a[100005];
bool chk[100005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  int en = 0;
  long long cnt = 0;
  chk[a[0]] = 1;
  for (int st = 0; st < n; st++) {
    while (en < n - 1 && !chk[a[en + 1]]) {
      en++;
      chk[a[en]] = 1;
    }
    cnt += (en - st + 1);
    chk[a[st]] = 0;
  }
  cout << cnt;
  return 0;
}