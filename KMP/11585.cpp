#include <bits/stdc++.h>
using namespace std;

vector<int> failure(string &s) {
  vector<int> f(s.size());
  for (int i = 1, j = 0; i < (int)s.size(); i++) {
    while(j > 0 && s[i] != s[j]) j = f[j - 1];
    if (s[i] == s[j]) f[i] = ++j;
  }
  return f;
}

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  string s1(n, ' '), s2(2 * n - 1, ' ');
  for (int i = 0; i < n; i++) cin >> s1[i];
  for (int i = 0; i < n; i++) {
    cin >> s2[i];
    s2[i + n] = s2[i];
  }
  vector<int> f = failure(s1);
  int cnt = 0;
  for (int i = 0, j = 0; i < 2*n - 1; i++){
    while (j > 0 && s2[i] != s1[j]) j = f[j - 1];
    if (s2[i] == s1[j]) j++;
    if (j == s1.size()) {
      cnt++;
      j = f[j - 1];
    }
  }
  int div = gcd(n, cnt);
  cout << cnt / div <<'/'<<n / div;
}