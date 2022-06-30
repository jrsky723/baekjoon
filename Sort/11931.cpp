#include <bits/stdc++.h>
using namespace std;

int arr[1000000];
int tmp[1000000];
int n;

void merge(int st, int en) {
  int mid = (st + en) / 2;
  for (int i = st, low = st, high = mid; i < en; i++) {
    if (low == mid)
      tmp[i] = arr[high++];
    else if (high == en)
      tmp[i] = arr[low++];
    else
      tmp[i] = arr[low] >= arr[high] ? arr[low++] : arr[high++];
  }
  for (int i = st; i < en; i++) arr[i] = tmp[i];
}

void merge_sort(int st, int en) {
  if (en == st + 1) return;
  int mid = (st + en) / 2;
  merge_sort(st, mid);
  merge_sort(mid, en);
  merge(st, en);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  merge_sort(0, n);
  for (int i = 0; i < n; i++) cout << arr[i] << '\n';
}