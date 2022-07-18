#include <bits/stdc++.h>
using namespace std;

int board[503][503], d[503][503];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= i; j++) cin >> board[i][j];
  d[0][0] = board[0][0];
  for (int i = 1; i < n; i++) {
    d[i][0] = d[i - 1][0] + board[i][0];
    for (int j = 1; j < i; j++) d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + board[i][j];
    d[i][i] = d[i - 1][i - 1] + board[i][i];
  }
  cout << *max_element (d[n - 1], d[n - 1] + n);
}
// 정답과 동일
