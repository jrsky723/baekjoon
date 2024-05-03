#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000000;

int p[MAX + 5];

int find_root(int x) {
  if (p[x] == -1) return x;
  p[x] = find_root(p[x]);
  return p[x];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  fill(p, p + n + 1, -1);

  while (m--) {
    int op, a, b;
    cin >> op >> a >> b;
    int a_r = find_root(a);
    int b_r = find_root(b);
    if (op == 1) {
      cout << (a_r == b_r ? "YES" : "NO") << '\n';
      continue;
    }
    if (a_r == b_r) continue;
    if (a_r < b_r)
      p[b_r] = a_r;
    else
      p[a_r] = b_r;
  }
}