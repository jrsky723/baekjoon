#include <bits/stdc++.h>
using namespace std;

const int MAX = 200000;
int tc, n;
vector<int> p(MAX + 5),s(MAX + 5);
int find(int x) {
  if (p[x] < 0) return x;
  else return p[x] = find(p[x]);
}
void func(int u, int v) {
  u = find(u), v = find(v);
  if (u != v) {
    if (s[u] < s[v]) swap(u, v);
    s[u] += s[v];
    p[v] = u;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> tc;
  while (tc--) {
    map<string, int> id;
    fill(p.begin(), p.end(), -1);
    fill(s.begin(), s.end(), 1);
    int num = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
      string f1, f2;
      cin >> f1 >> f2;
      if (id.find(f1) == id.end()) id[f1] = num++;
      if (id.find(f2) == id.end()) id[f2] = num++;
      func(id[f1], id[f2]);
      int p1 = find(id[f1]);
      int p2 = find(id[f2]);
      cout << max(s[p1], s[p2]) << '\n';
    }
  }
}