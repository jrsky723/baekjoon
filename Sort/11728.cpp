#include <bits/stdc++.h>
using namespace std;
int arr1[1000000];
int arr2[1000000];
int ans[2000000];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> arr1[i];
  for (int i = 0; i < m; i++) cin >> arr2[i];

  for (int i = 0, cur1 = 0, cur2 = 0; i < n + m; i++) {
    if (cur1 >= n)
      ans[i] = arr2[cur2++];
    else if (cur2 >= m)
      ans[i] = arr1[cur1++];
    else
      ans[i] = arr1[cur1] < arr2[cur2] ? arr1[cur1++] : arr2[cur2++];
  }
  for (int i = 0; i < n + m; i++) cout << ans[i] << ' ';
}