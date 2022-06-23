#include <bits/stdc++.h>
using namespace std;

int n, m, k;
bool board[42][42];
int r, c;
bool sticker[12][12];

bool pastable(int x, int y) {
  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++)
      if (board[x + i][y + j] && sticker[i][j]) return false;
  return true;
}

void past(int x, int y) {
  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++)
      if (sticker[i][j]) board[x + i][y + j] = 1;
}

void rotate() {
  int tmp[12][12];
  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++) tmp[i][j] = sticker[i][j];
  for (int i = 0; i < c; i++)
    for (int j = 0; j < r; j++) sticker[i][j] = tmp[r - 1 - j][i];
  swap(r, c);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  while (k--) {
    cin >> r >> c;
    for (int i = 0; i < r; i++)
      for (int j = 0; j < c; j++) cin >> sticker[i][j];

    for (int rot = 0; rot < 4; rot++) {
      bool isPast = false;
      for (int x = 0; x <= n - r; x++) {
        if (isPast) break;
        for (int y = 0; y <= m - c; y++) {
          if (pastable(x, y)) {
            past(x, y);
            isPast = true;
            break;
          }
        }
      }
      if (isPast) break;
      rotate();
    }
  }
  int cnt = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (board[i][j]) cnt++;
  cout << cnt;
}