#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7f7f7f7f;
int board[100005][4], d[100005][4];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  while (1) {
    int n;
    cin >> n;
    if (n == 0) break;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= 3; j++) cin >> board[i][j];

    d[1][1] = INF, d[1][2] = board[1][2], d[1][3] = d[1][2] + board[1][3];
    for (int i = 2; i <= n; i++) {
      d[i][1] = min(d[i - 1][1], d[i - 1][2]) + board[i][1];
      d[i][2] = min({d[i - 1][1], d[i - 1][2], d[i - 1][3], d[i][1]}) + board[i][2];
      d[i][3] = min({d[i - 1][2], d[i - 1][3], d[i][2]}) + board[i][3];
    }
    cout << t++ << ". " << d[n][2] << '\n';
  }
}