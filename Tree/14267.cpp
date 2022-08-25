#include <bits/stdc++.h>
using namespace std;

long long val[100005];
vector<int> child[100005];
int p[100005];

void dfs(int cur){
  for (auto nxt : child[cur]) {
    val[nxt] += val[cur];
    dfs(nxt);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    if (p[i] != -1) child[p[i]].push_back(i);
  }
  while (m--) {
    int st, w;
    cin >> st >> w;
    val[st] += w;
  }
  dfs(1);
  for (int i = 1; i <= n; i++) {
    cout << val[i] <<' ';
  }
}
