#include <bits/stdc++.h>
using namespace std;

int arr[21];
int n, s;
int cnt = 0;
void func(int cur , int sum) {
  if (cur == n) {
    if (sum == s) cnt++;
    return;
  }
  func(cur + 1, sum); // 더하지 않음
  func(cur + 1, sum + arr[cur]); //더함
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> s;
  for (int i = 0; i < n; i++) cin >> arr[i];
  func(0,0);
  if (s == 0) cnt--;  //합이 0일 때 공집합 제외
  cout << cnt;
}