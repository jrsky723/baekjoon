#include <bits/stdc++.h>
using namespace std;

int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int p[9] = {0, 0, 0, 1, 1, 2, 3, 5, 11};
map<string, int> dict;
string board[4];
bool vis[4][4];
int w, b;

bool OOB(int x, int y) { return x < 0 || x >= 4 || y < 0 || y >= 4; }

struct TrieNode {

  map<char, TrieNode *> child;

  ~TrieNode() {
    for (auto nxt : child) delete nxt.second;
  }

  void dfs(int x, int y, int k) {
    if (k == 8) return;
    auto cur = this;
    vis[x][y] = true;
    if (cur->child[board[x][y]] == NULL) cur->child[board[x][y]] = new TrieNode;
    cur = cur->child[board[x][y]];
    for (int dir = 0; dir < 8; dir++) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (OOB(nx, ny) || vis[nx][ny]) continue;
      cur->dfs(nx, ny, k + 1);
    }
    vis[x][y] = false;
  }

  bool find(string &s) {
    auto cur = this;
    for (auto c : s) {
      if (cur->child[c] == NULL) return false;
      cur = cur->child[c];
    }
    return true;
  }
};

TrieNode *root;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> w;
  while (w--) {
    string s;
    cin >> s;
    dict[s] = p[s.size()];
  }

  cin >> b;
  while (b--) {
    for (int i = 0; i < 4; i++) cin >> board[i];
    root = new TrieNode;

    for (int i = 0; i < 4; i++)
      for (int j = 0; j < 4; j++) root->dfs(i, j, 0);

    int sum = 0, cnt = 0;
    string longestS = "";
    for (auto words : dict) {
      string s = words.first;
      if (root->find(s)) {
        cnt++;
        sum += words.second;
        if (s.size() > longestS.size())
          longestS = s;
        else if (s.size() == longestS.size()) {
          if (longestS > s) longestS = s;
        }
      }
    }
    cout << sum << ' ' << longestS << ' ' << cnt << '\n';
    delete root;
  }
}
