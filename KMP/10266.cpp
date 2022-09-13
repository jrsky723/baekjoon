#include <bits/stdc++.h>
using namespace std;

const int MAX = 360'000;
vector<int> failure(vector<int> v) {
  vector<int> f(v.size());
  for (int i = 1, j = 0; i < v.size(); i++) {
    while(j > 0 && v[i] != v[j]) j = f[j - 1];
    if (v[i] == v[j]) f[i] = ++j;
  }
  return f;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> pat(MAX, 0);
  vector<int> cl(MAX * 2, 0);
  for (int i = 1; i <= n; i++) {
    int deg;
    cin >> deg;
    pat[deg] = 1;
  }
  for (int i = 1; i <= n; i++) {
    int deg;
    cin >> deg;
    cl[deg] = cl[deg + MAX] = 1;
  }
  vector<int> f = failure(pat);
  for (int i = 0,j = 0; i < MAX * 2; i++) {
    while(j > 0 && cl[i] != pat[j]) j = f[j - 1];
    if (cl[i] == pat[j]) j++;
    if (j == pat.size()) {
      cout << "possible";
      return 0;
    }
  }
  cout << "impossible";
}