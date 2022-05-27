#include <bits/stdc++.h>
using namespace std;
bool board[130][130];
int ans[2];

bool isPaper(int n, int r, int c) {
  for (int i = r; i < r + n; i++)
    for (int j = c; j < c + n; j++)
      if (board[r][c] != board[i][j]) return false;
  return true;
}
void paper(int n, int r, int c) {
  if (n == 1)
    ans[board[r][c]]++; //이 부분은 없앨 수 있음. 한 장일 때 isPaper = true
  else {
    if (isPaper(n, r, c))
      ans[board[r][c]]++;
    else {
      for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) paper(n / 2, r + n / 2 * i, c + n / 2 * j);
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) cin >> board[i][j];
  paper(N, 0, 0);
  for (int i : ans) cout << i << '\n';
}

//정답코드
// Authored by : haneulkimdev
// Co-authored by : -
// http://boj.kr/844f77ac02c84f889eeb69a5cf7d652b
// #include <bits/stdc++.h>
// using namespace std;

// int paper[128][128];
// int ans[2];

// bool chk(int n, int x, int y) {
//   for (int i = x; i < x + n; i++)
//     for (int j = y; j < y + n; j++)
//       if (paper[i][j] != paper[x][y]) return false;
//   return true;
// }

// void func(int n, int x, int y) {
//   if (chk(n, x, y)) {
//     ans[paper[x][y]]++;
//     return;
//   }
//   for (int i = 0; i < 2; i++)
//     for (int j = 0; j < 2; j++) func(n / 2, x + i * n / 2, y + j * n / 2);
// }

// int main(void) {
//   ios::sync_with_stdio(0);
//   cin.tie(0);
//   int n;
//   cin >> n;
//   for (int i = 0; i < n; i++)
//     for (int j = 0; j < n; j++) cin >> paper[i][j];
//   func(n, 0, 0);
//   for (int i = 0; i < 2; i++) cout << ans[i] << '\n';
// }