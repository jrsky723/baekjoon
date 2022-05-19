#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000000;
int dist[MAX + 1];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int F,S,G,U,D;
  queue<int> Q;
  cin>>F>>S>>G>>U>>D;
  fill(dist,dist + F,-1); //0층을 제외하고 생각하는 방법이 실수를 줄일듯 하다.
  dist[S-1] = 0;  //0층을 제외한다면 그냥 S로 가능
  Q.push(S-1);
  int ans = -1;
  while(!Q.empty()){
    int cur = Q.front(); Q.pop();
    if(cur == G - 1){
      ans = dist[cur];
      break;
    }
    for(int nxt : {cur + U, cur - D}){
      if(nxt < 0 || nxt >= F) continue;
      if(dist[nxt] >= 0) continue;
      dist[nxt] = dist[cur] + 1;
      Q.push(nxt); 
    }
  }
  if(ans == -1) cout<<"use the stairs";
  else cout<<ans;
}
//정답코드
// Authored by : std-freejia
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/8f34874217304e3ca3a499f672788d70
// #include <bits/stdc++.h>
// using namespace std;

// int f, s, g, u, d;
// int dist[1000002];

// int main(void) {
//   ios::sync_with_stdio(0);
//   cin.tie(0);

//   cin >> f >> s >> g >> u >> d;
//   fill(dist+1, dist+f+1, -1);
  
//   queue<int> q;
//   dist[s] = 0; // 현재 위치의 거리를 0으로 둠
//   q.push(s); // s층에서 시작
//   while(!q.empty()){
//     int cur = q.front(); q.pop();
//     for(auto nxt : {cur + u, cur - d}){
//       if(nxt > f || nxt <= 0 || dist[nxt] != -1) continue;
//       dist[nxt] = dist[cur] + 1;
//       q.push(nxt);
//     }
//   }

//   if(dist[g] == -1) cout << "use the stairs";
//   else cout << dist[g];
// }