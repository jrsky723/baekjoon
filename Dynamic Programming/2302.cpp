#include <bits/stdc++.h>
using namespace std;

bool vip[42];
long long d[42];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,m;
  cin >> n;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int num;
    cin >> num;
    vip[num] = 1;
  }
  d[0] = 1, d[1] = 1, d[2] = 2;
  for (int i = 3; i <= n - m; i++) d[i] = d[i - 1] + d[i - 2];

  int ans = 1, cnt = 0; //짧게 쓰기가능
  for (int i = 1; i <= n; i++) {
    if (vip[i]) {
      ans *= d[cnt];
      cnt = 0;
    } else
      cnt++;
  }
  ans *= d[cnt];
  cout << ans;
}

//정답코드
// Authored by : sukam09
// Co-authored by : -
// http://boj.kr/d6fbad043aa84210b49531fc17c48ef2
// #include <bits/stdc++.h>
// using namespace std;

// vector<int> v = {0}; // 고정석의 번호
// int d[45]; // 연속된 자리의 개수가 i개일 때 앉을 수 있는 경우의 수

// int main(void) {
//   ios::sync_with_stdio(0);
//   cin.tie(0);
  
//   int n, m, vv;
//   cin >> n;
//   cin >> m;
//   while (m--) {
//     cin >> vv;
//     v.push_back(vv);
//   }
//   v.push_back(n + 1);

//   d[0] = 1;
//   d[1] = 1;
//   d[2] = 2;
//   for (int i = 3; i <= n; i++) d[i] = d[i - 1] + d[i - 2];

//   int ans = 1;
//   for (int i = 1; i < v.size(); i++) ans *= d[v[i] - v[i - 1] - 1];
//   cout << ans; 
// }