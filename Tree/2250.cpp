#include <bits/stdc++.h>
using namespace std;

int lc[10005], rc[10005];
bool isRoot[10005];
int level[10005];
vector<int> col;

void inorder(int cur) {
  if (lc[cur]) inorder(lc[cur]);
  col.push_back(cur);
  if (rc[cur]) inorder(rc[cur]);
}
void bfs(int root) {
  queue<int> q;
  q.push(root);
  level[root] = 1;
  while(!q.empty()) {
    int cur = q.front();
    q.pop();
    if (lc[cur]) {
      q.push(lc[cur]);
      level[lc[cur]] = level[cur] + 1;
    }
    if (rc[cur]) {
      q.push(rc[cur]);
      level[rc[cur]] = level[cur] + 1;
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  fill(isRoot + 1, isRoot + n + 1, true);
  for (int i = 0; i < n; i++) {
    int x, l, r;
    cin >> x >> l >> r;
    if(l != -1) {
      lc[x] = l;
      isRoot[l] = false;
    }
    if (r != -1) {
      rc[x] = r;
      isRoot[r] = false;
    }
  }
  int root = 0;
  for (int i = 1; i <= n; i++) {
    if (isRoot[i]) root = i;
  }
  col.push_back(0);
  inorder(root);
  bfs(root);
  int width = 0;
  int min_level = 10000;
  for (int s = 1; s < col.size(); s++) {
    for (int e = col.size() - 1; e >= s; e--) {
      if (level[col[s]] == level[col[e]]) {
        if (e - s + 1 == width) {
          width = e - s + 1;
          min_level = min(min_level, level[col[s]]);
        }
        else if (e - s + 1 > width) {
          min_level = level[col[s]];
          width = e - s + 1;
        }
        break;
      }
    }
  }
  cout << min_level << " "<<width;
} 