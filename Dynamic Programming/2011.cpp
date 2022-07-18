#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000;
int a[5005];
int d[5005][2];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  for (int i = 1; i <= s.size(); i++) a[i] = s[i - 1] - '0';
  d[0][0] = 1;
  if (a[1] >= 1 && a[1] <= 9) d[1][0] = 1;
  d[1][1] = 0;
  for (int i = 2; i <= s.size(); i++) {
    if (a[i] >= 1 && a[i] <= 9) d[i][0] = (d[i - 1][0] + d[i - 1][1]) % mod;
    if (10 * a[i - 1] + a[i] <= 26 && 10 * a[i - 1] + a[i] >= 10)
      d[i][1] = (d[i - 2][0] + d[i - 2][1]) % mod;
  }
  cout << (d[s.size()][0] + d[s.size()][1]) % mod;
}
// 정답코드
// Authored by : Hot6Mania
// Co-authored by : -
// http://boj.kr/04239b41012a4a41bb36c1a00c62b5ec
// #include <bits/stdc++.h>
// using namespace std;

// int n;
// int a[5010], d[5010];
// int mod = 1000000;

// int main(void){
//   ios::sync_with_stdio(0);
//   cin.tie(0);
  
//   string s; cin>>s;
//   n = s.size();
//   for(int i = 1; i <= n; ++i) a[i] = s[i-1] - '0';
//   d[0] = 1;
//   for(int i = 1; i <= n; ++i){
//     if(a[i] > 0) d[i] = (d[i] + d[i-1]) % mod;
//     int x = a[i-1] * 10 + a[i];
//     if(x >= 10 && x <= 26) d[i] = (d[i] + d[i-2]) % mod;
//   }
//   cout << d[n];
// }