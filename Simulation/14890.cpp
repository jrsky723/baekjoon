#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int board[102][102];
int n, L, ans;

bool chk(vector<int> line) {
  int cur = 0;
  int cnt = 1;  //같은 높이 구간 길이
  while (cur < n - 1) {
    if (line[cur] == line[cur + 1]) {
      cur++;
      cnt++;
    } else if (line[cur] - line[cur + 1] == 1) {
      if (cur + L >= n) return 0;
      for (int i = cur + 1; i < cur + L; i++)
        if (line[i] != line[i + 1]) return 0;
      cur = cur + L;
      cnt = 0;
    } else if (line[cur] - line[cur + 1] == -1) {
      if (cnt < L) return 0;
      cnt = 1;
      cur++;
    } else
      return false;
  }
  return true;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> L;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> board[i][j];

  for (int i = 0; i < n; i++) {
    vector<int> line;
    for (int j = 0; j < n; j++) line.push_back(board[i][j]);
    if (chk(line)) ans++;
  }
  for (int j = 0; j < n; j++) {
    vector<int> line;
    for (int i = 0; i < n; i++) line.push_back(board[i][j]);
    if (chk(line)) ans++;
  }
  cout << ans;
}
//정답코드와 동일