#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> signup{};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int k, l;
  cin >> k >> l;
  for (int i = 0; i < l; i++) {
      string s;
      cin >> s;
      if(signup.find(s) != signup.end()) {
          signup.erase(s);
          signup[s] = i;
      }
      else {
          signup[s] = i;
      }
  }
  vector<pair<string,int>> v (signup.begin(), signup.end());
  sort(v.begin(), v.end(), [](auto &a, auto &b) {return a.second < b.second;});
  int en = min(k, (int)v.size());
  for (int i = 0; i < en; i++) cout << v[i].first<<'\n';
}