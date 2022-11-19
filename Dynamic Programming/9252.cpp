#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s1, s2, temp1, temp2, ans;
  cin >> temp1 >> temp2;
  s1 = " " + temp1;
  s2 = " " + temp2;
  for (int i = 1; i < s1.length(); i++) {
    for (int j = 1; j < s2.length(); j++) {
      if (s1[i] == s2[j])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else
        dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
    }
  }

  int row = s1.size() - 1;
  int col = s2.size() - 1;
  while (dp[row][col]) {
    if (dp[row][col] == dp[row - 1][col])
      row--;
    else if (dp[row][col] == dp[row][col - 1])
      col--;
    else
      ans += s1[row], row--, col--;
  }
  cout << dp[s1.length()- 1][s2.length() - 1] << '\n';
  if (ans.size()) {
    reverse(ans.begin(), ans.end());
    cout << ans;
  }
}