#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int x1, x2, y1, y2;
  cin >> x1 >> x2 >> y1 >> y2;
  x1 *= lcm(x2, y2) / x2;
  y1 *= lcm(x2, y2) / y2;
  int a1 = x1 + y1, a2 = lcm(x2, y2);
  int GCD = gcd(a1, a2);
  a1 /= GCD;
  a2 /= GCD;
  cout << a1 << ' ' << a2;
}