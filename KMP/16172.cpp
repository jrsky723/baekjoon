#include <bits/stdc++.h>
using namespace std;

vector<int> failure(string &s) {
  vector<int> f(s.size());
  int j = 0;
  for (int i = 1; i < s.size(); i++) {
    while(j > 0 && s[i] != s[j]) j = f[j - 1];
    if(s[i] == s[j]) f[i] = ++j;
  }
  return f;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string temp, s1, s2;
  cin >> temp;
  for (auto c : temp) {
    if (c >= '0' && c <= '9') continue;
    s1 += c;
  }
  cin >> s2;
  vector<int> f = failure(s2);
  int j = 0;
  for (int i = 0; i < s1.size(); i++){
    while(j > 0 && s1[i] != s2[j]) j = f[j-1];
    if (s1[i] == s2[j]) j++;
    if (j == s2.size()) {
      cout << 1;
      return 0;
    }
  }
  cout << 0;
}