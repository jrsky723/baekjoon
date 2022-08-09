#include <bits/stdc++.h>
using namespace std;
int a[10005];
int n, m;

bool solve(int x) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    if (x < a[i])
      sum += x;
    else
      sum += a[i];
  }
  return sum <= m;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  cin >> m;
  int low = 0;
  int high = *max_element(a, a + n);
  while (low < high) {
    int mid = (low + high + 1) / 2;
    if(solve(mid)) low = mid;
    else high = mid - 1;
  }
  cout << low;
}