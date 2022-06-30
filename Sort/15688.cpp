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
      tmp[i] = arr[low] <= arr[high] ? arr[low++] : arr[high++];
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

//정답코드
// Authored by : heheHwang
// Co-authored by : -
// http://boj.kr/ff8bea751284429baa8fd53b43f694d2
// #include <bits/stdc++.h>
// using namespace std;

// const int MXN = 2'000'000, HALF = MXN / 2;
// int main(void) {
//   ios::sync_with_stdio(0);
//   cin.tie(0);

//   vector<int> numcnt(MXN + 2);
//   int N, t;
//   cin >> N;
//   while (N--) {
//     cin >> t;
//     numcnt[t + HALF]++;
//   }
//   for (int i = 0; i <= MXN; i++)
//     while (numcnt[i]--) cout << i - HALF << '\n';
// }