#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
const int MAX = 100000;
int n;
int a[MAX + 5];
pair<int, int> ans;
bool check(int st, int en) {
  if (st < en) {
    if (abs(a[st] + a[en]) < abs(ans.X + ans.Y)) {
      ans.X = a[st], ans.Y = a[en];
      return true;
    }
  }
  return false;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  int st = 0, en = n - 1;
  ans = {a[st], a[en]};
  while (st < en) {
    check(st, en);
    if (check(st + 1, en))
      st++;
    else if (check(st, en - 1))
      en--;
    else 
      st++;
  }
  cout << ans.X << ' ' << ans.Y;
}