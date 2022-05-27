#include <bits/stdc++.h>
using namespace std;

int board[2200][2200];
int ans[3];

void paper(int n, int r, int c) {
  if (n == 1)
    ans[board[r][c] + 1]++;
  else {
    int num = board[r][c];
    bool isPaper = true;
    for (int i = r; i < r + n; i++)
      for (int j = c; j < c + n; j++)
        if (num != board[i][j]) isPaper = false;
    //위에 동작을 함수로 만들어서 return 시키는 것이 나아 보임
    if (isPaper)
      ans[num + 1]++;
    else {
      for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) paper(n / 3, r + n / 3 * i, c + n / 3 * j);
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

// Authored by : cpprhtn
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/b8488e82105d49e89ca6f39fd8ee665b
// #include <bits/stdc++.h>
// using namespace std;

// int N;
// int paper[2200][2200];
// int cnt[3]; //-1, 0, 1로 채워진 종이 갯수

// //해당 종이 내부에 같은 숫자로만 채워졌는지 확인하는 함수
// bool check(int x, int y, int n) {
//   for (int i = x; i < x + n; i++)
//   for (int j = y; j < y + n; j++)
//     if (paper[x][y] != paper[i][j])
//     return false;
//   return true;
// }
// void solve(int x, int y, int z)
// {
//   if (check(x, y, z)) {
//     cnt[paper[x][y] + 1] += 1;
//     return;
//   }
//   int n = z / 3;
//   for (int i = 0; i < 3; i++)
//   for (int j = 0; j < 3; j++)
//     solve(x + i * n, y + j * n, n);
// }
// int main(void) {
//   ios::sync_with_stdio(0);
//   cin.tie(0);
//   cin >> N;
//   for (int i = 0; i < N; i++)
//   for (int j = 0; j < N; j++)
//     cin >> paper[i][j];
//   solve(0, 0, N);
//   for (int i = 0; i < 3; i++) cout << cnt[i] << "\n";
// }