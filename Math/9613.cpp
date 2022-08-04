#include <bits/stdc++.h>
using namespace std;

int a[105];
int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    long long sum = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < i; j++) sum += gcd(a[i], a[j]);
    cout << sum << '\n';
  }
}