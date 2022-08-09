#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7f7f7f7f;
int a[1000005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<int> v = {INF};
  vector<int> order(n);
  for (int i = 0; i < n; i++) {
    if (a[i] > v.back()) {
      v.push_back(a[i]);
      order[i] = v.size();
    }
    else {
      int idx = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
      v[idx] = a[i];
      order[i] = idx + 1;
    }
  }
  cout << v.size() <<'\n';
  stack<int> ans;
  int target = v.size();
  for (int i = n - 1; i >= 0; i--) 
    if(order[i] == target) {
      ans.push(a[i]);
      target--;
    }
  while(!ans.empty()) {
    cout << ans.top() << ' ';
    ans.pop();
  }
  return 0;
}