#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 1000;
ll a[MAX + 5];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  vector <ll> two;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) two.push_back(a[i] + a[j]);
  sort(two.begin(), two.end());
  two.erase(unique(two.begin(), two.end()), two.end());

  ll mx = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (binary_search(two.begin(), two.end(), a[i] - a[j]))
        mx = max(mx, a[i]);
  cout << mx;
}