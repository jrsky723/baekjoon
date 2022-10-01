#include <bits/stdc++.h>
using namespace std;

vector<int> failure(string &s) {
  vector<int> f(s.size());
  int j = 0;
  for (int i = 1; i < s.size(); i++) {
    while (j > 0 && s[i] != s[j]) j = f[j - 1];
    if (s[i] == s[j]) f[i] = ++j;
  }
  return f;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string t, p;
  
  getline(cin, t);
  getline(cin, p);
  vector<int> ans;
  vector<int> f = failure(p);
  int j = 0;
  for (int i = 0; i < t.size(); i++) {
    while(j > 0 && t[i] != p[i]) j = f[j - 1];
    if (t[i] == p[j]) j++;
    if (j == p.size()) ans.push_back(i + 1);
  }
  cout << ans.size() << '\n';
  for (int i : ans) cout << i << '\n';
}