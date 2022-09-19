#include <bits/stdc++.h>
using namespace std;

int board[9][9];
bool row[10][10];
bool col[10][10];
bool box[3][3][10];
vector<pair<int, int>> blank;
bool clear;
void dfs(int k) {
  if (k == blank.size()) {
    clear = true;
    return;
  } 
  auto [x, y] = blank[k];
  for (int i = 1; i <= 9; i++) {
    if (row[x][i] || col[y][i] || box[x / 3][y / 3][i]) continue;
    row[x][i] = col[y][i] = box[x / 3][y / 3][i] = true;
    board[x][y] = i;
    dfs(k + 1);
    if(clear) return;
    row[x][i] = col[y][i] = box[x / 3][y / 3][i] = false;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cin >> board[i][j];
      if (board[i][j] == 0) {
        blank.push_back({i, j});
        continue;
      }
      row[i][board[i][j]] = true;
      col[j][board[i][j]] = true;
      box[i / 3][j / 3][board[i][j]] = true;
    }
  }
  dfs(0);

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) cout << board[i][j] << ' ';
    cout << '\n';
  }
}