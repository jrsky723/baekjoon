#include <bits/stdc++.h>
using namespace std;

int lc[100005], rc[100005], p[100005];
bool vis[100005];
int n,  en;
long long cnt;

void inorder(int cur) {
  if (lc[cur]) inorder(lc[cur]);
  en = cur;
  if (rc[cur]) inorder(rc[cur]);
}

void myInorder(int cur) {
  vis[cur] = true;
  if (lc[cur] && !vis[lc[cur]]) {
    myInorder(lc[cur]);
    cnt++;
  } else if (rc[cur] && !vis[rc[cur]]) {
    myInorder(rc[cur]);
    cnt++;
  } else if (cur == en) {
    return;
  } else if (p[cur]) {
    myInorder(p[cur]);
    cnt++;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    int node, l, r;
    cin >> node >> l >> r;
    if (l != -1) {
      lc[node] = l;
      p[l] = node;
    }
    if (r != -1) {
      rc[node] = r;
      p[r] = node;
    }
  }
  inorder(1);
  myInorder(1);
  cout << cnt;
}