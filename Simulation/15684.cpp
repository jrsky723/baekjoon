#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[32][12];
int nBoard[32][12];
int n, m, h, cnt;

vector<pair<int, int>> cand;

bool chk() {
  for (int i = 1; i <= n; i++) {
    int lad = i;
    for (int j = 1; j <= h; j++) {
      if (nBoard[j][lad - 1])
        lad--;
      else if (nBoard[j][lad])
        lad++;
    }
    if (i != lad) return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> h;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    board[a][b] = 1;
  }

  for (int i = 1; i <= h; i++) {
    for (int j = 1; j < n; j++) {
      if (board[i][j - 1] || board[i][j] || board[i][j + 1]) continue;
      cand.push_back({i, j});
    }
  }

  for (int i = 1; i <= h; i++) copy(board[i] + 1, board[i] + n, nBoard[i] + 1);
  if (cand.size() == 0) {
    if (chk())
      cout << 0;
    else
      cout << -1;
    return 0;
  }

  while (cnt < 4) {
    bool clear = false;
    vector<bool> mask(cand.size(), 1);
    fill(mask.begin(), mask.begin() + cnt, 0);
    do {
      for (int i = 1; i <= h; i++)
        copy(board[i] + 1, board[i] + n, nBoard[i] + 1);
      bool isEmpty = true;
      int c = 0;
      for (int i = 0; i < mask.size(); i++) {
        if (mask[i]) continue;
        int x = cand[i].X, y = cand[i].Y;
        if (nBoard[x][y - 1] || nBoard[x][y] || nBoard[x][y + 1]) {
          isEmpty = 0;
          break;
        }
        nBoard[x][y] = 1;
        c++;
        if (c == cnt) break;
      }
      if (!isEmpty) continue;
      if (chk()) {
        clear = true;
        break;
      }
    } while (next_permutation(mask.begin(), mask.end()));
    if (clear) break;
    cnt++;
  }
  if (cnt == 4) cnt = -1;
  cout << cnt;
}