#include <bits/stdc++.h>
using namespace std;
const int MAX = 3072;
char board[MAX + 1][2 * MAX];

//입력값의 변화가 없으면 const int& 활용 -> 실수 방지
void star(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++)
      board[i][n - 1 + j] = board[i][n - 1 - j] = '*';
  }
}
  void blank(int n, int x, int y) {
    if (n == 3) { // 이 문제는 별을 위치에 따라 그려주는게 더 편함
    board[x - 1][y] = ' ';
  } else {  //그리기로 했을 시 가운데 비우기 과정은 필요없음.
    for (int i = 0; i < n / 2; i++)
      for (int j = 0; j <= i; j++)
        board[x - i][y - j] = board[x - i][y + j] = ' ';
    blank(n / 2, x - n / 2, y);
    blank(n / 2, x, y - n / 2);
    blank(n / 2, x, y + n / 2);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) fill(board[i], board[i] + 2 * n - 1, ' ');
  star(n);
  blank(n, n - 1, n - 1);
  for (int i = 0; i < n; i++) cout << board[i] << '\n';
}

//정답코드
// #include <bits/stdc++.h>
// using namespace std;

// const int MAX = 1024 * 3 + 2;

// int n;
// char board[MAX][MAX * 2 - 1];

// void fill_star(const int& x, const int& y) {
//   board[x][y] = '*';
//   board[x + 1][y - 1] = '*', board[x + 1][y + 1] = '*';

//   for (int i = y - 2; i <= y + 2; ++i) {
//     board[x + 2][i] = '*';
//   }
// }

// void func(const int& s, const int& x, const int& y) {
//   if (s == 3) {
//     fill_star(x, y);
//     return;
//   }

//   int ns = s / 2;
//   func(ns, x, y);
//   func(ns, x + ns, y - ns);
//   func(ns, x + ns, y + ns);
// }

// int main() {
//   ios_base::sync_with_stdio(0);
//   cin.tie(0);

//   cin >> n;
//   func(n, 0, n - 1);
//   for (int i = 0; i < n; ++i) {
//     for (int ii = 0; ii < n * 2 - 1; ++ii) {
//       if (board[i][ii] == '*')
//         cout << '*';
//       else
//         cout << ' ';
//     }
//     cout << "\n";
//   }
// }