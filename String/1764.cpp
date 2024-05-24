#include <bits/stdc++.h>
using namespace std;

#define NAME first
#define CNT second

map<string, int> mp;
vector<string> ans;
string s;
int n, m;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  while (n--) {
    cin >> s;
    mp.insert({s, 1});
  }
  while (m--) {
    cin >> s;
    mp[s]++;
  }
  for (auto p : mp) {
    if (p.CNT == 2) ans.push_back(p.NAME);
  }
  cout << ans.size() << '\n';
  for (string s : ans) cout << s << '\n';
}