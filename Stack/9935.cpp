#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string text, bomb;
  cin >> text >> bomb;
  vector<char> v;
  for (int i = 0; i < text.size(); i++) {
    v.push_back(text[i]);
    if(v.back() == bomb.back()) {
      bool chk = true;
      if (v.size() < bomb.size()) continue;
      for (int j = 0; j < bomb.size(); j++) {
        if (v[v.size() - bomb.size() + j] != bomb[j]){
          chk = false;
          break;
        }
      }
      if (chk) {
        for (int j = 0; j < bomb.size(); j++) v.pop_back();
      }
    }
  }
  if (v.empty()) cout << "FRULA";
  else  for (auto c : v) cout << c;
}