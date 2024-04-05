#include <bits/stdc++.h>

using namespace std;

bool hansu(int x) {
  int temp = x;
  vector<int> vec;
  while (temp) {
    vec.push_back(temp % 10);
    temp /= 10;
  }
  if (vec.size() <= 2)
    return true;
  else {
    int d = vec[0] - vec[1];
    for (int i = 1; i < vec.size() - 1; i++) {
      if (d != vec[i] - vec[i + 1]) return false;
    }
    return true;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (hansu(i)) cnt++;
  }
  cout << cnt;
}
