#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s, e, q;
  cin >> s >> e >> q;
  unordered_map<string, int> state;  // 0 : out , 1 : in , 2 : signup
  string time, id;
  while (cin >> time >> id) {
    if (time <= s && state[id] == 0)
      state[id]++;
    else if (e <= time && time <= q && state[id] == 1)
      state[id]++;
  }
  int cnt = 0;
  for (auto v : state)
    if (v.second == 2) cnt++;
    cout << cnt;
}