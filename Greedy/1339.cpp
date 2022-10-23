#include <bits/stdc++.h>
using namespace std;

vector<int> v(26);
int n;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int digit = 1;
    for (int j = s.length() - 1; j >= 0; j--) {
      v[s[j] - 'A'] += digit;
      digit *= 10;
    }
  }
  sort(v.rbegin(), v.rend());
  int num = 9, ans = 0;
  for (int i : v) {
    if (i == 0) break;
    ans += i * num--;
  }
  cout << ans;
}