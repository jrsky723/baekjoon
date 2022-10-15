#include <bits/stdc++.h>
using namespace std;

int n;
bool exL[26], exR[26];
bool can[26][26];
set<char> ans;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    string gene;
    cin >> gene;
    int L = gene[0] - 'A';
    int R = gene[1] - 'A';
    if (exL[L] || exR[R]) can[L][R] = can[R][L] = true;
    exL[L] = exR[R] = true;
    for (int i = 0; i < 26; i++) {
      if (i == R) continue;
      if (exR[i]) can[i][L] = true;
    }
    for (int i = 0; i < 26; i++) {
      if (i == L) continue;
      if (exL[i]) can[i][R] = true;
    }
  }
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 26; j++) {
      if (can[i][j]) {
        if (i > j) ans.insert('A' + i);
        else ans.insert('A' + j);
      }
    }
  }
  cout << ans.size() << '\n';
  for (auto c : ans) cout << c << ' ';
}