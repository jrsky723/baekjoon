#include <bits/stdc++.h>
using namespace std;

const int MAX = 500'000;
int arr[MAX + 5];
int lower_idx(int target, int len) {
  int st = 0;
  int en = len;
  while (st < en) {
    int mid = (st + en) / 2;
    if (arr[mid] >= target) en = mid;
    else st = mid + 1;
  }
  return st;
}
int upper_idx(int target, int len) {
  int st = 0;
  int en = len;
  while (st < en) {
    int mid = (st + en) / 2;
    if (arr[mid] > target) en = mid;
    else st = mid + 1;
  }
  return st;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);
  int m;
  cin >> m;
  while (m--) {
    int num;
    cin >> num;
    cout << upper_idx(num, n) - lower_idx(num, n) << ' ';
  }
}