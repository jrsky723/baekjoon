#include <bits/stdc++.h>
using namespace std;

int board[129][129];
int num = 0;
int len;
bool chk(int n, int x, int y) {
  for (int i = x; i < x + n; i++) {
    for (int j = y; j < y + n; j++) {
      if (board[i][j] != 0) return false;
    }
  }
  return true;
}

void tile_board_DC(int n, int x, int y) {
  num++;
  int n2 = n / 2;
  int x1 = x, y1 = y;
  int x2 = x + n2, y2 = y;
  int x3 = x, y3 = y + n2;
  int x4 = x + n2, y4 = y + n2;
  if (chk(n2, x1, y1)) board[x1 + n2 - 1][y1 + n2 - 1] = num;
  if (chk(n2, x2, y2)) board[x2][y2 + n2 - 1] = num;
  if (chk(n2, x3, y3)) board[x3 + n2 - 1][y3] = num;
  if (chk(n2, x4, y4)) board[x4][y4] = num;
  if (n == 2) return;
  tile_board_DC(n2, x1, y1);
  tile_board_DC(n2, x2, y2);
  tile_board_DC(n2, x3, y3);
  tile_board_DC(n2, x4, y4);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int k, x, y;
  cin >> k >> x >> y;
  len = (1 << k);
  board[len - y][x - 1] = -1;
  tile_board_DC(len, 0, 0);
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < len; j++) cout << board[i][j] << ' ';
    cout << '\n';
  }
}