#include <bits/stdc++.h>
using namespace std;

vector<int> failure(string &s) {
  vector<int> f(s.size());
  for (int i = 1, j = 0; i < s.size(); i++) {
    while(j > 0 && s[i] != s[j]) j = f[ j - 1];
    if (s[i] == s[j]) f[i] = ++j; 
  }
  return f;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  string s;
  while(1) {
    cin >> s;
    if (s == ".") break;
    vector<int> f = failure(s);
    int sz = s.size();
    int mnPre = sz - f[sz - 1];
    if (sz % mnPre) cout << 1 <<'\n';
    else cout << sz / mnPre <<'\n';
  }
}