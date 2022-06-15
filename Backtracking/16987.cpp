#include <bits/stdc++.h>
using namespace std;
#define S first
#define W second
int n, ans;
pair<int, int> eggs[9];
int cnt;
void func(int k) {
  if (k == n) {
    ans = max(cnt, ans);
    return;
  }
  if (eggs[k].S <= 0 || cnt == n - 1) {
    func(k + 1);
    return;
  }
  for (int i = 0; i < n; i++) {
    if (i == k || eggs[i].S <= 0) continue;
    eggs[k].S -= eggs[i].W;
    eggs[i].S -= eggs[k].W;
    if (eggs[k].S <= 0) cnt++;
    if (eggs[i].S <= 0) cnt++;
    func(k + 1);
    if (eggs[k].S <= 0) cnt--;
    if (eggs[i].S <= 0) cnt--;
    eggs[k].S += eggs[i].W;
    eggs[i].S += eggs[k].W;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> eggs[i].S >> eggs[i].W;
  func(0);
  cout << ans;
}