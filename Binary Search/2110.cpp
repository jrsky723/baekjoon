#include <bits/stdc++.h>
using namespace std;

int a[200005];
int n, c;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> c;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  int left = 0, right = a[n - 1];
  int ans = 0;
  while (left <= right) {
    int cnt = 1;  //공유기 갯수
    int mid = (left + right) / 2;
    int preidx = 0;
    for (int i = 1; i < n; i++) {
      if (a[i] - a[preidx] >= mid) {
        preidx = i;   //기준 거리 보다 사이거리가 큰 공유기 갯수 세기
        cnt++;
      }             
    }
    if (cnt >= c) { 
      ans = mid;
      left = mid + 1;
    }
    else right = mid - 1;
  }
  cout << ans;
}