#include <bits/stdc++.h>
using namespace std;

string s;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> s;
  sort(s.begin(), s.end());
  for (int i = s.length() - 1; i >= 0; i--) cout << s[i];
}