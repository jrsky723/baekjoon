#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
const int INF = 0x7f7f7f7f;
int n;
vector<pair<int, int>> edge;
vector<int> v = {INF};
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    edge.push_back({a, b});
  }
  sort(edge.begin(), edge.end());
  //가장 긴 증가하는 부분수열 O(nlogn)
  for (int i = 0; i < n; i++) {
    int t = edge[i].Y;
    if (t > v.back()) v.push_back(t);
    else {
      int idx = lower_bound(v.begin(), v.end(), t) - v.begin();
      v[idx] = t; 
    }
  }
  cout << n - v.size() << '\n';
}