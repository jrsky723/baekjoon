#include <bits/stdc++.h>
using namespace std;
int n;
int l[100005];

int find(int idx1) { 
  int idx2 = lower_bound(l, l + n, -l[idx1]) - l;
  int mn = 0x7f7f7f7f;
  int ret = 0;
  for (int i : {-1, 0, 1}) {
    int nx = idx2 + i;
    if (nx < 0 || nx >= n || nx == idx1) continue;
    int val = abs(l[nx] + l[idx1]);
    if (val < mn) {
      mn = val;
      ret = nx;
    }
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> l[i];
  int mn = 0x7f7f7f7f;
  int l1 = 0, l2 = n - 1;
  for (int i = 0; i < n; i++) {
    int idx1 = i, idx2 = find(idx1);
    int val = abs(l[i] + l[idx2]);
    if (mn > val) {
      mn = val;
      l1 = idx1;
      l2 = idx2;
    }
  }
  if (l2 < l1) swap(l1, l2);
  cout << l[l1] << ' ' << l[l2];
}