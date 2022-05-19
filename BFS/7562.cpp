#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[301][301];
int dx[8] = {2,1,-1,-2,-2,-1,1,2};
int dy[8] = {1,2,2,1,-1,-2,-2,-1};

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  queue <pair<int,int>> Q;
  cin>>T;
  while(T--){
    int I;
    cin>>I;
    int curX,curY,desX,desY;
    cin>>curX>>curY>>desX>>desY;
    board[curY][curX] = 1;
    //비어있다는 것을 나타낼 때 -1을 사용하자. fill 할 것 convention
    Q.push({curY,curX});  //체스판은 정사각형이므로 가로,세로 구분 의미없다.
    while(!Q.empty()){
      pair<int,int> cur = Q.front(); Q.pop();
      if(cur.X == desY && cur.Y == desX){
        cout<<board[desY][desX] - 1<<'\n';
        break;
      } //의미없는 loop를 안 돌리려고 break를 해줬지만, 코드를 더 줄이는걸 선호하자
      for(int dir = 0; dir < 8; dir++){
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if(nx < 0 || nx >= I || ny < 0 || ny >= I) continue;
        if(board[nx][ny] > 0) continue;
        board[nx][ny] = board[cur.X][cur.Y] + 1;
        Q.push({nx,ny});
      }
    }
    while(!Q.empty()) Q.pop();
    for(int i = 0; i < I; i++) fill(board[i],board[i] + I,0);
  }
}
//정답코드
// Authored by : yongjunleeme
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/f5754d2b4a6b48ab88efc3e9dcbb1943
// #include <bits/stdc++.h>
// using namespace std;

// #define X first
// #define Y second
// int dist[305][305];
// int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
// int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
// int t, n, x, y, xx, yy;
// queue <pair<int, int >> Q;

// int main(void) {
//   ios::sync_with_stdio(0);
//   cin.tie(0);

//   cin >> t;
//   while (t--) {
//     cin >> n;
//     for (int i = 0; i < n; i++) fill(dist[i], dist[i] + n, -1);
//     cin >> x >> y;
//     dist[x][y] = 0;
//     Q.push({x, y});
//     cin >> xx >> yy;
//     while (!Q.empty()) {
//       auto cur = Q.front(); Q.pop();
//       for (int dir = 0; dir < 8; dir++) {
//         int nx = cur.X + dx[dir];
//         int ny = cur.Y + dy[dir];
//         if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
//         if (dist[nx][ny] >= 0) continue;
//         dist[nx][ny] = dist[cur.X][cur.Y] + 1;        
//         Q.push({nx, ny});
//       }
//     }
//     cout << dist[xx][yy] << "\n";
//   }
// }