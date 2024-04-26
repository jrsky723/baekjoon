#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000;

int a[MAX + 5], dp[MAX + 5];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  fill(dp, dp + n, 1);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < i; j++)
      if (a[j] < a[i]) dp[i] = max(dp[i], dp[j] + 1);
  cout << *max_element(dp, dp + n);
}