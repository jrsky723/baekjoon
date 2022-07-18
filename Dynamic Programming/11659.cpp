#include <bits/stdc++.h>
using namespace std;

int num[100005]; 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> num[i];
    num[i] += num[i - 1];
  }
  while (m--) {
    int from, to;
    cin >> from >> to;
    cout << num[to] - num[from - 1] << '\n';
  }
}