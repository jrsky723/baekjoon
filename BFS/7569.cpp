#include <bits/stdc++.h>
using namespace std;
#define X get<0>
#define Y get<1>
#define Z get<2>
int box[101][101][101];
int dx[6] = {1,0,0,-1,0,0};
int dy[6] = {0,1,0,0,-1,0};
int dz[6] = {0,0,1,0,0,-1};

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N,M,H;
  int cnt = 0;
  queue <tuple<int,int,int>> Q;
  cin>>M>>N>>H;
  for (int k = 0; k < H; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        cin >> box[i][j][k];
        if(box[i][j][k] == -1) cnt++;
        else if(box[i][j][k] == 1) {
            Q.push({i,j,k});
          }
      }
    }
  }

  int m = 0;
  while(!Q.empty()){
    tuple<int,int,int> cur = Q.front(); Q.pop(); cnt++;
    m = max(box[X(cur)][Y(cur)][Z(cur)],m);
    for(int dir = 0; dir < 6; ++dir){
      int nx = X(cur) + dx[dir];
      int ny = Y(cur) + dy[dir];
      int nz = Z(cur) + dz[dir];
      if(nx < 0 || nx >= N || ny < 0 || ny >= M || nz < 0 || nz >= H) continue;
      if(box[nx][ny][nz] != 0) continue;
      box[nx][ny][nz] = box[X(cur)][Y(cur)][Z(cur)] + 1;
      Q.push({nx,ny,nz});
    }
  }
  if(cnt == N*M*H) cout<<m-1;
  else cout<<-1;
}
//정답코드
// Authored by : BueVonHun
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/f3877bee8d3c454482dd3229e4246b49
// #include <bits/stdc++.h>
// using namespace std;

// int dx[6] = {0, 0, 1, -1, 0, 0};
// int dy[6] = {1, -1, 0, 0, 0, 0};
// int dz[6] = {0, 0, 0, 0, 1, -1};
// int board[103][103][103];
// int dist[103][103][103];
// queue<tuple<int, int, int>> Q;
// int m, n, h;
// int main(void) {
//   ios_base::sync_with_stdio(0);
//   cin.tie(0);
//   cin >> m >> n >> h;
//   for (int i = 0; i < h; i++) {
//     for (int j = 0; j < n; j++) {
//       for (int k = 0; k < m; k++) {
//         int tmp;
//         cin >> tmp;
//         board[j][k][i] = tmp;
//         if (tmp == 1) Q.push({j, k, i});
//         if (tmp == 0) dist[j][k][i] = -1;
//       }
//     }
//   }

//   while (!Q.empty()) {
//     auto cur = Q.front();
//     Q.pop();
//     int curX, curY, curZ;
//     tie(curX, curY, curZ) = cur;
//     for (int dir = 0; dir < 6; dir++) {
//       int nx = curX + dx[dir];
//       int ny = curY + dy[dir];
//       int nz = curZ + dz[dir];
//       if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
//       if (dist[nx][ny][nz] >= 0) continue;
//       dist[nx][ny][nz] = dist[curX][curY][curZ] + 1;
//       Q.push({nx, ny, nz});
//     }
//   }

//   int ans = 0;
//   for (int i = 0; i < h; i++) {
//     for (int j = 0; j < n; j++) {
//       for (int k = 0; k < m; k++) {
//         if (dist[j][k][i] == -1) {
//           cout << -1 << "\n";
//           return 0;
//         }
//         ans = max(ans, dist[j][k][i]);
//       }
//     }
//   }
//   cout << ans << "\n";
//   return 0;
// }