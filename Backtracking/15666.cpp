#include <bits/stdc++.h>
using namespace std;
int num[10];
int arr[10];
int n, m;
void func(int k, int st) {
  if (k == m) {
    for (int i = 0; i < m; i++) cout << num[arr[i]] << ' ';
    cout << '\n';
    return;
  }
  int temp = 0;
  for (int i = st; i < n; i++) {
    if (temp != num[i]) {
      temp = num[i];
      arr[k] = i;
      func(k + 1, i);
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> num[i];
  sort(num, num + n);
  func(0, 0);
}

//정답과 동일