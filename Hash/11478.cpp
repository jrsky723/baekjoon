#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  unordered_set<string> list;
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i++)
    for (int j = 1; j <= s.size(); j++) list.insert(s.substr(i, j));
  cout << list.size();
}