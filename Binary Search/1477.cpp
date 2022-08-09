#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int n , m , l;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> l;
  v.push_back(0), v.push_back(l);
  for (int i = 0; i < n; i++) {
    int pos;
    cin >> pos;
    v.push_back(pos);
  }
  sort(v.begin(), v.end());
  int st = 0, en = l;
  int ans = 0;
  while (st < en) {
    int mid = (st + en + 1) / 2;
    int cnt = 0;
    for (int i = 1; i < v.size(); i++) {
      int dist = v[i] - v[i - 1];
      cnt += (dist - 1) / mid;
    }
    if (cnt > m) st = mid;
    else {
      en = mid - 1;
      ans = mid;
    }
  }
  cout << ans;
}