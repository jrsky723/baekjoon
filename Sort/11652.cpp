#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll arr[100001];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);
  int cnt = 1, mxcnt = 1;
  ll mxval = arr[0];

  for (int i = 1; i < n; i++) {
    if (arr[i - 1] != arr[i]) cnt = 0;
    cnt++;
    if (mxcnt < cnt) {
      mxcnt = cnt;
      mxval = arr[i];
    }
  }
  cout << mxval;
}