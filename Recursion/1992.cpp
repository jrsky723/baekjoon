#include <bits/stdc++.h>
using namespace std;
string board[64];   //bool[64][64] 와 메모리 차이 없음.

bool chk(int n, int x, int y) {
  for (int i = x; i < n + x; i++)
    for (int j = y; j < n + y; j++)
      if (board[x][y] != board[i][j]) return false;
  return true;
}

void comp(int n, int x, int y) {
  if (chk(n, x, y)) cout<<board[x][y]; 
  else {     //cout을 사용한다면 string 보다 더 메모리를 적게씀
    cout<<"(";
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++)
        comp(n / 2, x + n / 2 * i, y + n / 2 * j);
    cout<<")";
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) cin >> board[i];
  comp(N, 0, 0);
}

//정답코드

// Authored by : cpprhtn
// Co-authored by : -
// http://boj.kr/04267bd2251a41109700585bc73a6de2
// #include <bits/stdc++.h>
// using namespace std;

// int N;
// const int MAX = 64;
// int arr[MAX][MAX];
// void solve(int n, int y, int x)
// {
//   if (n == 1) {
//     cout << arr[y][x];
//     return;
//   }
//   bool zero = true, one = true;
//   for (int i = y; i < y + n; i++)
//     for (int j = x; j < x + n; j++)
//       if (arr[i][j])
//         zero = false;
//       else
//         one = false;
//   if (zero)
//     cout << 0;
//   else if (one)
//     cout << 1;
//   else {
//     cout << "(";
//     solve(n / 2, y, x); //왼쪽 위
//     solve(n / 2, y, x + n / 2); //오른쪽 위
//     solve(n / 2, y + n / 2, x); //왼쪽 아래
//     solve(n / 2, y + n / 2, x + n / 2); //오른쪽 아래
//     cout << ")";
//   }
//   return;
// }
// int main(void)
// {
//   ios::sync_with_stdio(0);
//   cin.tie(0);
//   cin >> N;
//   for (int i = 0; i < N; i++) {
//     string str;
//     cin >> str;
//     for (int j = 0; j < N; j++)
//       arr[i][j] = str[j] - '0';
//   }
//   solve(N, 0, 0);
// }