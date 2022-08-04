#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans[10];
void cal(int n, int ten) {
  while (n) {
    ans[n % 10] += ten;
    n /= 10;
  }
}
void func(int st, int end, int ten) {
  while (st % 10 && st <= end) cal(st++, ten);
  if (st > end) return;
  while (end % 10 != 9 && st <= end) cal(end--, ten);

  ll cnt = end / 10 - st / 10 + 1;
  for (int i = 0; i < 10; i++) ans[i] += cnt * ten;

  func(st / 10, end / 10, ten * 10);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  func(1, n, 1);
  for (int i = 0; i < 10; i++) cout << ans[i] <<' ';
  return 0;
}