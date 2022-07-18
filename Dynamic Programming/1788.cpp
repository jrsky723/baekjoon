#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000000;
const int rem = 1000000000;
long long d[2 * MAX + 5];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  d[MAX - 1] = 1, d[MAX] = 0;
  d[MAX + 1] = 1;
  for (int i = MAX + 2; i <= 2 * MAX; i++) d[i] = (d[i - 1] + d[i - 2]) % rem;
  for (int i = MAX - 2; i >= 0; i--) d[i] = (d[i + 2] - d[i + 1]) % rem;
  int n;
  cin >> n;
  if (d[MAX + n] < 0)
    cout << -1 << '\n' << -d[MAX + n];
  else if (d[MAX + n] > 0)
    cout << 1 << '\n' << d[MAX + n];
  else
    cout << 0 << '\n' << 0;
}