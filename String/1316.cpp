#include <bits/stdc++.h>

using namespace std;

bool is_exist[26];

bool check(string s) {
  char prev_c = '0';
  for (auto c : s) {
    if (prev_c != '0') {
      if (is_exist[c - 'a'] == true && prev_c != c) return false;
    }
    is_exist[c - 'a'] = true;
    prev_c = c;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, ans = 0;
  cin >> n;

  while (n--) {
    string s;
    cin >> s;
    fill(is_exist, is_exist + 26, false);
    if (check(s)) ans++;
  }
  cout << ans << '\n';
}
