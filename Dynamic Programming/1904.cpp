#include <bits/stdc++.h>
using namespace std;

int d[1000005];
int main() {
  int n;
  cin >> n;
  d[0] = d[1] = 1;
  for (int i = 2; i <= n; i++) 
    d[i] = (d[i - 1] + d[i - 2]) % 15746;
  cout << d[n];
}
//정답코드
// Authored by : Hot6Mania
// Co-authored by : -
// http://boj.kr/5fa43d98481c4d3f9f1d8e55bdb5ed6b
// #include <bits/stdc++.h>
// using namespace std;

// int n;
// int d[1000010];
// int mod = 15746;

// int main(void){
//   ios::sync_with_stdio(0);
//   cin.tie(0);
  
//   cin >> n;
//   d[1] = 1; d[2] = 2;
//   for(int i = 3; i <= n; ++i) d[i] = (d[i-1] + d[i-2]) % mod;
//   cout << d[n];
// }