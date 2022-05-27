#include <bits/stdc++.h>
using namespace std;

bool board[201][201];
int dist[201][201][31];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int hdx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int hdy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int k,w,h;
bool OOB(int x,int y){
  return (x < 0 || x >= h || y < 0 || y >= w);
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>k>>w>>h;
  for(int i = 0; i < h; i++)
    for(int j = 0; j < w; j++){
      cin>>board[i][j];
      for(int l = 0; l <= k; l++)
      dist[i][j][l] = -1;
    }
  queue <tuple<int,int,int>> Q;
  Q.push({0,0,0});
  dist[0][0][0] = 0;
  int ans = -1;
  while(!Q.empty()){
    auto [x,y,c] = Q.front(); Q.pop();
    if(x == h-1 && y == w-1) {
      ans = dist[x][y][c];
      break;
    }
    if(c < k){
      for(int dir = 0; dir < 8; dir++){
        int nx = x + hdx[dir];
        int ny = y + hdy[dir];
        if(OOB(nx,ny) || board[nx][ny] == 1 || dist[nx][ny][c+1] >= 0) continue;
        Q.push({nx,ny,c+1});
        dist[nx][ny][c+1] = dist[x][y][c] + 1;
      }
    }
    for(int dir = 0 ; dir < 4; dir++){
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if(OOB(nx,ny) || board[nx][ny] == 1 || dist[nx][ny][c] >= 0) continue;
      Q.push({nx,ny,c});
      dist[nx][ny][c] = dist[x][y][c] + 1;
    }
  }
  cout<<ans;
}
//정답코드
// Authored by : heheHwang
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/40081492d92a4e1d9c805d23bf485942
// #include <bits/stdc++.h>
// using namespace std;

// int board[202][202];
// int vis[32][202][202];
// int dmx[4] = { 0, 0, 1, -1 };
// int dmy[4] = { 1, -1, 0, 0 };
// int dkx[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
// int dky[8] = { 1, -1, 2, -2, 2, -2, 1, -1 };
// queue<tuple<int, int, int>> Q;
// int bX, bY, Kn;

// int main(void) {
//   ios::sync_with_stdio(0);
//   cin.tie(0);

//   cin >> Kn >> bY >> bX;
//   for (int i = 0; i < bX; i++)
//     for (int j = 0; j < bY; j++)
//       cin >> board[i][j];
//   Q.push({ 0, 0, 0 });
//   vis[0][0][0] = 1;
//   while (!Q.empty()) {
//     int vk, vx, vy;
//     tie(vk, vx, vy) = Q.front();
//     Q.pop();
//     if (vk < Kn) {
//       for (int i = 0; i < 8; i++) {
//         int nx = vx + dkx[i], ny = vy + dky[i];
//         if (nx < 0 || ny < 0 || bX <= nx || bY <= ny) continue;
//         if (board[nx][ny]) continue;
//         if (vis[vk + 1][nx][ny]) continue;
//         vis[vk + 1][nx][ny] = vis[vk][vx][vy] + 1;
//         Q.push({ vk + 1, nx, ny });
//       }
//     }
//     for (int i = 0; i < 4; i++) {
//       int nx = vx + dmx[i], ny = vy + dmy[i];
//       if (nx < 0 || ny < 0 || bX <= nx || bY <= ny) continue;
//       if (board[nx][ny]) continue;
//       if (vis[vk][nx][ny]) continue;
//       vis[vk][nx][ny] = vis[vk][vx][vy] + 1;
//       Q.push({ vk, nx, ny });
//     }
//   }
//   int ans = 0x7f7f7f7f;
//   for (int i = 0; i < Kn + 1; i++)
//     if(vis[i][bX - 1][bY - 1]) ans = min(ans, vis[i][bX - 1][bY - 1]);
//   if (ans != 0x7f7f7f7f) cout << ans - 1;
//   else cout << -1;
// }