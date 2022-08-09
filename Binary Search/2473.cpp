#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[5005], ans[3];
int n;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  ll mn = 3e10 + 5;
  for (int i = 0; i < n - 2; i++) {
    int j = i + 1, k = n - 1;
    while (1) {
      if (j >= k) break;
      ll sum = a[i] + a[j] + a[k];
      if (mn > llabs(sum)) {
        mn = llabs(sum);
        ans[0] = a[i], ans[1] = a[j], ans[2] = a[k];
      }
      if (sum > 0)
        k--;
      else
        j++;
    }
  }
  for (int i : ans) cout << i << ' ';
}