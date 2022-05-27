#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int mod(int a, int b, int c) {
  if (b == 1) return a % c;
  ll temp = mod(a,b/2,c);
  temp = temp * temp % c;
  if(b%2) temp = temp * a % c;
  return temp;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a, b, c;
  cin >> a >> b >> c;
  cout << mod(a, b, c);
}