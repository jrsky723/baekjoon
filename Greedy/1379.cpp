#include <bits/stdc++.h>
using namespace std;

#define X get<0>
#define Y get<1>
#define Z get<2>
typedef tuple<int, int, int> tiii;
vector<tiii> lect;
priority_queue<tiii, vector<tiii>, greater<tiii>>pq;
int room[100005];
int n, k;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    int id, st, en;
    cin >> id >> st >> en;
    lect.push_back({st, en, id});
  }
  sort(lect.begin(), lect.end());
  for (auto [st, en, id] : lect) {
    if (!pq.empty() && X(pq.top()) <= st){
      room[id] = room[Z(pq.top())];
      pq.pop();
    }
    else {
      k++;
      room[id] = k;
    }
    pq.push({en, st, id});
  }
  cout << k <<'\n';
  for (int i = 1; i <= n; i++) cout << room[i] <<'\n';
}