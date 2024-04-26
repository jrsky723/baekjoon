#include <bits/stdc++.h>

using namespace std;

const int MAX_S = 300;
const int MAX_V = 10000;

int arr[MAX_S + 5];
int dp[MAX_S + 5];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  dp[1] = arr[1];
  dp[2] = arr[1] + arr[2];

  for (int i = 3; i <= n; i++) {
    dp[i] = max(dp[i - 2], dp[i - 3] + arr[i - 1]) + arr[i];
  }

  cout << dp[n] << '\n';
}