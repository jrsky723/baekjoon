#include <bits/stdc++.h>

using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  priority_queue<int, vector<int>, greater<int>> pqR;  //최소 힙
  priority_queue<int> pqL;                             //최대힙
  while (n--) {
    int x;
    cin >> x;
    if (pqL.empty())
      pqL.push(x);
    else {
      if (x > pqL.top())
        pqR.push(x);
      else
        pqL.push(x);
      while (pqR.size() > pqL.size()) {
        pqL.push(pqR.top());
        pqR.pop();
      }
      while (pqL.size() > pqR.size() + 1) {
        pqR.push(pqL.top());
        pqL.pop();
      }
    }
    cout << pqL.top() << '\n';
  }
}