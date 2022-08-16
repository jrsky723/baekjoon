#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  priority_queue<int, vector<int>, greater<int>> pq;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int num;
      cin >> num;
      if (pq.size() == n) {
        if (num > pq.top()) {
          pq.pop();
          pq.push(num);
        }
        else continue;
      }
      else pq.push(num);
    }
  }
  cout << pq.top();
}