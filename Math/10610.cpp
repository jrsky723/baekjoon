#include <bits/stdc++.h>
using namespace std;
int a[10];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    a[s[i] - '0']++;
  }
  int sum = 0;
  for (int i = 0; i < 10; i++) {
    sum += i * a[i];
  }

  if (sum % 3 || a[0] == 0) {
    cout << "-1";
    return 0;
  }
  string ans;
  for (int i = 9; i >= 0; i--) {
    while (a[i]--) {
      ans.push_back('0' + i);
    }
  }
  cout << ans;
}