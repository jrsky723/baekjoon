#include <bits/stdc++.h>
using namespace std;
int n, k, ans;

int words[51];
int base;
void func(int mask, char c, int num) {
  if (num == k) {
    int cnt = 0;
    for (int i = 0; i < n; i++) 
      if (!(~mask & words[i])) cnt++;
    ans = max(ans, cnt);
    return;
  }
  if (c > 'z') return;
  if (!(~base & (1 << (c - 'a')))) func(mask, c + 1, num);
  else {
    func(mask | 1 << (c - 'a'), c + 1, num + 1);
    func(mask, c + 1, num);
  }
}
void solve() {
  k -= 5;
  if (k >= 0) func(base, 'a', 0);
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (auto c : s) words[i] |= 1 << (c-'a');
  }
  for (auto c : "antic") base |= (1 << c - 'a');
  solve();
  cout << ans;
}