#include <bits/stdc++.h>
using namespace std;

const int MAX = 1'000'000;
int arr[MAX + 5];
int temp[MAX + 5];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    temp[i] = arr[i];
  }

  sort(temp, temp + n);
  vector<int> v;
  v.push_back(temp[0]);
  for (int i = 1; i < n; i++) {
    if (v.back() == temp[i]) continue;
    v.push_back(temp[i]);
  }
  for (int i = 0; i < n; i++) {
    cout << lower_bound(v.begin(), v.end(), arr[i]) - v.begin() << ' ';
  }
}