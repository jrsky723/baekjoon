#include <bits/stdc++.h> 
using namespace std;
int a[100005];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  int en = 0, mn = 0x7f7f7f7f;
  for (int st = 0; st < n; st++) {
    while(en < n && a[en] - a[st] < m) en++;
    if (en == n) break;
    mn = min(mn, a[en] - a[st]);
  }
  cout << mn;
}



// #include <bits/stdc++.h>  //이분탐색 풀이
// using namespace std;
// int a[100005];

// int main() {
//   ios::sync_with_stdio(0);
//   cin.tie(0);
//   int n, m;
//   cin >> n >> m;
//   for (int i = 0; i < n; i ++) cin >> a[i];
//   sort (a, a + n);
//   int mn = 0x7f7f7f7f;
//   for (int i = 0; i < n; i++) {
//     int idx = lower_bound(a, a + n, a[i] + m) - a;
//     if (idx < n) mn = min (mn, a[idx] - a[i]);
//   }
//   cout << mn;
// }

