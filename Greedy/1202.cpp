#include <bits/stdc++.h>
using namespace std;

#define M first
#define V second

typedef pair<int, int> pii;

const int MAX = 3000000;

pii arr[MAX + 3];
multiset<int> ms;
int n, k;
long long ans;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int m, v;
    cin >> m >> v;
    arr[i] = {m, v};
  }
  for (int i = 0; i < k; i++) {
    int a;
    cin >> a;
    ms.insert(a);
  }

  sort(arr, arr + n, [](pii &a, pii &b) {
    if (a.V == b.V) a.M < b.M;
    return a.V > b.V;
  });

  for (int i = 0; i < n; i++) {
    auto it = ms.lower_bound(arr[i].M);
    if (it != ms.end()) {
      ans += arr[i].V;
      ms.erase(it);
    }
  }
  cout << ans << '\n';
}