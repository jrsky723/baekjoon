#include <bits/stdc++.h>
using namespace std;

int n;

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

  cin >> n;
  while (n--) {
    vector<int> ans;
    map<char, int> c2i;
    string A, W, S;
    cin >> A >> W >> S;

    for (int i = 0; i < A.size(); i++) c2i[A[i]] = i;

    for (int x = 0; x < A.size(); x++) {
      int cnt = 0;
      string tempA = A, tempW = W;
      rotate(tempA.begin(), tempA.begin() + x, tempA.end());
      for (int i = 0; i < tempW.size(); i++) tempW[i] = tempA[c2i[tempW[i]]];

      vector<int> f = failure(tempW);
      int j = 0;
      for (int i = 0; i < S.size(); i++) {
        while (j > 0 && S[i] != tempW[j]) j = f[j - 1];
        if (S[i] == tempW[j]) j++;
        if (j == tempW.size()) {
          j = f[j - 1];
          cnt++;
        }
      }
      if (cnt == 1) ans.push_back(x);
    }
    if (ans.size() == 0)
      cout << "no solution";
    else if (ans.size() == 1)
      cout << "unique: " << ans[0];
    else {
      cout << "ambiguous:";
      for (int i : ans) cout << ' ' << i;
    }
    cout << '\n';
  }
}