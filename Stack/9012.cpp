#include <bits/stdc++.h>
using namespace std;

const int MAX = 100000;
int arr[MAX + 5];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) cin >> arr[i];

  bool ok = true;
  stack<int> st;
  vector<bool> ans;
  int cur = 1;
  for (int i = 0; i < n; i++) {
    while (cur <= arr[i]) {
      st.push(cur++);
      ans.push_back(1);
    }
    if (st.top() == arr[i]) {
      st.pop();
      ans.push_back(0);
    } else {
      ok = false;
      break;
    }
  }
  if (ok)
    for (bool b : ans) {
      cout << (b ? '+' : '-') << '\n';
    }
  else
    cout << "NO\n";
}