#include <bits/stdc++.h>
using namespace std;

bool isPrime[1005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  isPrime[1] = false;
  fill(isPrime + 2, isPrime + n + 1, 1);
  int cnt = 0;
  for (int i = 2; i <= n; i++) {
    if (isPrime[i] == 0) continue;
    for (int j = i; j <= n; j += i) {
      if (isPrime[j] == 1) {
        isPrime[j] = 0;
        cnt++;
      }
      if (cnt == k) {
        cout << j;
        return 0;
      }
    }
  }
}