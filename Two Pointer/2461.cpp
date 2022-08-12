#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> stu;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int ab;
      cin >> ab;
      stu.push_back({ab, i});
    }
  }
  sort(stu.begin(), stu.end());
  vector<int> chk(n);
  int en = 0;
  int kindcnt = 1;
  int ans = 0x7f7f7f7f;
  chk[stu[0].Y]++;
  for (int st = 0; st < stu.size(); st++) {
    while (en < m * n - 1 && kindcnt < n) {
      en++;
      if(chk[stu[en].Y] == 0) kindcnt++;
      chk[stu[en].Y]++;
    }
    if(kindcnt == n) ans = min(stu[en].X - stu[st].X, ans);
    chk[stu[st].Y]--;
    if(chk[stu[st].Y] == 0) kindcnt--;
  }
  cout << ans;
  return 0;
}