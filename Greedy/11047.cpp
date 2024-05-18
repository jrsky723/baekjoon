#include <bits/stdc++.h>
using namespace std;

const int MAX = 10;

int arr[MAX + 3];
int n, k, cnt;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> arr[i];

  for (int i = n - 1; i >= 0; i--) {
    cnt += k / arr[i];
    k %= arr[i];
  }
  cout << cnt << '\n';
}