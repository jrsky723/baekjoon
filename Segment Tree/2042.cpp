#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 1<<20;
ll arr[MAX];
ll seg[MAX * 2];
//segment tree에서 node의 갯수를 생각할 때 완전 이진트리의 모습을 떠올리자
int n, m, k, a, b;
ll c;

ll init(int idx, int st, int en) {
  if (st == en) return seg[idx] = arr[st];
  int mid = (st + en) / 2;
  return seg[idx] = init(2 * idx, st, mid) + init(2 * idx + 1, mid + 1, en);
}

ll sum(int idx, int st, int en, int l, int r) {
  if (l > en || r < st) return 0;
  if (l <= st && en <= r) return seg[idx];
  int mid = (st + en) / 2;
  return sum(2 * idx, st, mid, l, r) + sum(2 * idx + 1, mid + 1, en, l, r);
}

void update(int idx, int st, int en, int i, ll diff) {
  if (en < i || i < st) return;
  seg[idx] += diff;
  if (st == en) return;
  int mid = (st + en) / 2;
  update(2 * idx, st, mid, i, diff);
  update(2 * idx + 1, mid + 1, en, i, diff);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) cin >> arr[i];
  init(1, 1, n);
  for (int i = 0; i < m + k; i++) {
    cin >> a >> b >> c;
    if (a == 1) {
      ll diff = c - arr[b];
      arr[b] = c;
      update(1, 1, n, b, diff);
    } else
      cout << sum(1, 1, n, b, c) << '\n';
  }
}