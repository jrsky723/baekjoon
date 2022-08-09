#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> a(1002), b(1002);
int t, n, m;
void input(vector<vector<int>> &v, int r) {
  for (int i = 0; i < r; i++) {
    int num;
    cin >> num;
    v[i].push_back(num);
  }
  for (int i = 0; i < r - 1; i++)
    for (int j = i + 1; j < r; j++) v[i].push_back(v[i].back() + v[j].front());
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t >> n;
  input(a, n);
  cin >> m;
  input(b, m);
  vector<int> sumA, sumB;
  for (auto v : a)
    for (int i : v) sumA.push_back(i);
  for (auto v : b)
    for (int i : v) sumB.push_back(i);
  sort(sumB.begin(), sumB.end());
  long long cnt = 0;
  for (int i : sumA) {
    auto up = upper_bound(sumB.begin(), sumB.end(), t - i);
    auto low = lower_bound(sumB.begin(), sumB.end(), t - i);
    cnt += (up - low);
  }
  cout << cnt;
}