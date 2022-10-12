#include<bits/stdc++.h>
using namespace std;

const int MAX = 200, INF = 0x3f3f3f3f;
#define C first
#define N second
vector<pair<int, int>> adj[MAX + 5]; //{cost, next}
int dist[MAX + 5];
bool chk[MAX + 5];
int ans;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N,M;
  cin>>N>>M;
  for(int i=0; i<M; i++){
    int x, y, w;
    cin>>x>>y>>w;
    adj[x].push_back({w,y});
    adj[y].push_back({w,x});
  }
  fill(dist + 1, dist + 1 + N, INF);
  dist[1] = 0;
  chk[1] = true;
  for (auto nxt : adj[1]) dist[nxt.N] = nxt.C;
  int cnt = N - 1;
  while (cnt--) {
    int mnCost = INF;
    int mnNext = 0;
    for (int i = 1; i <= N; i++) {
      if (chk[i]) continue;
      if (mnCost > dist[i]){
        mnCost = dist[i];
        mnNext = i;
      }
    }
    chk[mnNext] = true;
    ans += mnCost;
    for (auto nxt : adj[mnNext]) {
      if (chk[nxt.N]) continue;
      dist[nxt.N] = min(dist[nxt.N],nxt.C);
    }
  }
  cout << ans;
}










