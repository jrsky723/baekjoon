#include <bits/stdc++.h>
using namespace std;

int a[10005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  int en = 0, tot = a[0], cnt = 0;
  for (int st = 0; st < n; st++) {
    while(en < n && tot < m) tot += a[++en];
    if (tot == m) cnt++;
    tot -= a[st];
  } 
  cout << cnt;
}

//정답코드
// Authored by : pjshwa
// Co-authored by : -
// http://boj.kr/b7ec5531223f449f99942515f10fb39b
// #include <bits/stdc++.h>
// typedef long long ll;
// using namespace std;

// ll pf_sum[10005];

// int main(void){
//   ios::sync_with_stdio(0);
//   cin.tie(0);

//   int n, m;
//   cin >> n >> m;

//   pf_sum[0] = 0;
//   for (int i = 1; i <= n; i++) cin >> pf_sum[i], pf_sum[i] += pf_sum[i - 1];

//   int lp = 0, rp = 0;
//   int ans = 0;

//   while (rp <= n) {
//     ll csum = pf_sum[rp] - pf_sum[lp];
//     if (csum <= m) {
//       if (csum == m) ans++;
//       rp++;
//     }
//     else lp++;
//   }

//   cout << ans;
// }