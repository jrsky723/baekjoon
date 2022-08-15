#include <bits/stdc++.h>
using namespace std;

#define H first
#define K second

pair<int, int> arr[500005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i].H >> arr[i].K;
  sort(arr, arr + n, greater<>());
  multiset<int> team;
  for (int i = 0; i < n; i++) {
    auto it = team.lower_bound(arr[i].K);
    if(it == team.begin()) team.insert(1);
    else {
      int num = *prev(it);
      team.erase(prev(it));
      team.insert(num + 1);
    }
  }
  cout << team.size();  
}