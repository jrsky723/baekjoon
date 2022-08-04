#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll find(ll n, int p) {
  ll rtn = 0;
  while (n) {
    rtn += (n / p);
    n /= p;
  }
  return rtn;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  ll two = 0, five = 0;
  two = find(n, 2) - find(m, 2) - find((n - m), 2);
  five = find(n, 5) - find(m, 5) - find((n - m), 5); 
  cout << min(two, five);
}