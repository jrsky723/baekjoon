#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int MAX = 100000;
int n, cur, cnt;

vector<pii> vec;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    vec.push_back({b, a});
  }
  sort(vec.begin(), vec.end());
  for (auto p : vec) {
    if (cur <= p.second) {
      cur = p.first;
      cnt++;
    }
  }
  cout << cnt << '\n';
}