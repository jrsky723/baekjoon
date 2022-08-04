#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    string s = to_string(i);
    for (int j = 0; j < s.size(); j++) {
      cnt++;
      if(cnt == k) {
        cout << s[j];
        return 0;
      }
    }
  }
  cout << -1;
}