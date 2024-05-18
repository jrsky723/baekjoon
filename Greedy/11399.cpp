#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000;

int arr[MAX + 3];
int n, cur, ans;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];

  sort(arr, arr + n);
  for (int i = 0; i < n; i++) {
    cur += arr[i];
    ans += cur;
  }
  cout << ans << '\n';
}