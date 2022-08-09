#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 1'000'000;
int arr[MAX + 5];
int m, n;
bool solve(ll x) {
  if (x == 0) return true;
  ll cur = 0;
  for (int i = 0; i < n; i++) cur += arr[i] / x;
  return cur >= m;
}
int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0);

  cin >> m >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];

  ll st = 0;
  ll en = *max_element(arr, arr + n);

  while (st < en) {
    ll mid = (st + en + 1) / 2;
    if (solve(mid)) st = mid;
    else en = mid - 1;
  }
  cout << st;
}