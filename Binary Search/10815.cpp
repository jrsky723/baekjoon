#include <bits/stdc++.h>
using namespace std;

const int MAX = 500'000;
int a[MAX + 5];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  int m;
  cin >> m;
  while (m--) {
    int num;
    cin >> num;
    cout << binary_search(a, a + n, num) << ' ';
  }
}