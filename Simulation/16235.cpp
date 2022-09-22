#include <bits/stdc++.h>
using namespace std;

int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int board[12][12];
int s2d2[12][12];
int n, m, k;

vector<int> trees[12][12];

bool OOB(int x, int y) { return x <= 0 || x > n || y <= 0 || y > n; }

void springSummer() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (trees[i][j].size() == 0) continue;

      vector<int> temp;
      int energy = 0;
      
      sort(trees[i][j].begin(), trees[i][j].end());

      for (auto age : trees[i][j]) {
        if (age > board[i][j]) energy += age / 2;
        else {
          board[i][j] -= age;
          temp.push_back(age + 1);
        }
      }
      trees[i][j].clear();
      for (auto age : temp) trees[i][j].push_back(age);
      board[i][j] += energy;
    }
  }
}

void autumn() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (trees[i][j].size() == 0) continue;

      for (auto age : trees[i][j]) {
        if (age % 5) continue;
        for (int dir = 0; dir < 8; dir++) {
          int nx = i + dx[dir];
          int ny = j + dy[dir];
          if (OOB(nx, ny)) continue;
          trees[nx][ny].push_back(1);
        }
      }
    }
  }
}

void winter() {
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) board[i][j] += s2d2[i][j];
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) cin >> s2d2[i][j];

  for (int i = 1; i <= n; i++) fill(board[i] + 1, board[i] + 1 + n, 5);

  for (int i = 0; i < m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    trees[x][y].push_back(z);
  }

  while (k--) {
    springSummer();
    autumn();
    winter();
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) ans += trees[i][j].size();
  cout << ans;
}