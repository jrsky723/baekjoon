#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  unordered_map<string, string> idols;
  unordered_map<string, vector<string>> teams;
  while (n--) {
    string teamName;
    int teamNum;
    cin >> teamName >> teamNum;
    vector<string> temp;
    while (teamNum--) {
      string name;
      cin >> name;
      idols[name] = teamName;
      temp.push_back(name);
    }
    sort(temp.begin(), temp.end());
    teams[teamName] = temp;
  }
  while (m--) {
    string query;
    bool kind;
    cin >> query >> kind;
    if (kind) {
      cout << idols[query] << '\n';
    } else {
      for (auto s : teams[query]) {
        cout << s << '\n';
      }
    }
  }
}