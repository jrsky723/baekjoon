#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
enum { W, N, O, G, R, F };
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int board[50][50];
int newBoard[50][50];
int dist[50][50];
int seeds[11];
int av;
int ans;
queue<pair<int, int>> Q;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, g, r;
  cin >> n >> m >> g >> r;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> board[i][j];
      if (board[i][j] == O) av++;
    }
  fill(seeds, seeds + g, G);
  fill(seeds + g, seeds + g + r, R);
  fill(seeds + g + r, seeds + av, N);
  sort(seeds, seeds + av);
  do {
    for (int i = 0; i < n; i++) fill(dist[i], dist[i] + m, -1);
    int curS = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        newBoard[i][j] = board[i][j];
        if (newBoard[i][j] == O) {
          newBoard[i][j] = seeds[curS++];
          if (newBoard[i][j] == G || newBoard[i][j] == R) {
            dist[i][j] = 0;
            Q.push({i, j});
          }
        }
      }
    int flowers = 0;
    while (!Q.empty()) {
      pair<int, int> cur = Q.front();
      Q.pop();
      if (newBoard[cur.X][cur.Y] == F) continue;
      int curDist = dist[cur.X][cur.Y];
      for (int dir = 0; dir < 4; dir++) {
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (newBoard[nx][ny] == W || newBoard[nx][ny] == F) continue;
        if (newBoard[nx][ny] == newBoard[cur.X][cur.Y]) continue;
        if (dist[nx][ny] >= 0 && dist[nx][ny] != curDist + 1) continue;
        if ((newBoard[cur.X][cur.Y] == G && newBoard[nx][ny] == R) ||
            (newBoard[cur.X][cur.Y] == R && newBoard[nx][ny] == G)) {
          newBoard[nx][ny] = F;
          flowers++;
          continue;
        }
        dist[nx][ny] = curDist + 1;
        newBoard[nx][ny] = newBoard[cur.X][cur.Y];
        Q.push({nx, ny});
      }
    }
    ans = max(flowers, ans);
  } while (next_permutation(seeds, seeds + av));
  cout << ans;
}

// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : -
// http://boj.kr/3a00c74928b0492f8317005f987babf5
// #include <bits/stdc++.h>
// using namespace std;

// #define X first
// #define Y second

// int n,m,g,r;
// int board[52][52];
// int dx[4] = {1,0,-1,0};
// int dy[4] = {0,1,0,-1};
// vector<pair<int,int> > cand;
// int candsz;
// const int EMPTY = 0;
// const int GREEN = 1;
// const int RED = 2;
// const int FLOWER = 3;

// // next_permutaion을 위한 변수, cand가 7이고 g=1,r=4일 때 {0,0,1,2,2,2,2}
// int brute[10];
// int solve(){
//   int cnt = 0;
//   pair<int,int> state[52][52]; // {arrival time, color}

//   queue<pair<int,int>> q;
//   for(int i = 0; i < candsz; i++){
//     if(brute[i] == GREEN || brute[i] == RED){
//       state[cand[i].X][cand[i].Y] = {0, brute[i]};
//       q.push(cand[i]);
//     }
//   }
//   while(!q.empty()){
//     auto cur = q.front(); q.pop();
//     int curtime = state[cur.X][cur.Y].X;
//     int curcolor = state[cur.X][cur.Y].Y;
//     if(state[cur.X][cur.Y].Y == FLOWER) continue;
//     for(int dir = 0; dir < 4; dir++){
//       int nx = cur.X + dx[dir];
//       int ny = cur.Y + dy[dir];
//       if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
//       if(board[nx][ny] == 0) continue;
//       if(state[nx][ny].Y == EMPTY){
//         state[nx][ny] = {curtime+1, curcolor};
//         q.push({nx,ny});
//       }
//       else if(state[nx][ny].Y == RED){
//         if(curcolor == GREEN && state[nx][ny].X == curtime+1){
//           cnt++;
//           state[nx][ny].Y = FLOWER;
//         }
//       }
//       else if(state[nx][ny].Y == GREEN){
//         if(curcolor == RED && state[nx][ny].X == curtime+1){
//           cnt++;
//           state[nx][ny].Y = FLOWER;
//         }        
//       }
//     }
//   }
//   return cnt;
// }

// int main(void) {
//   ios::sync_with_stdio(0);
//   cin.tie(0);
//   cin >> n >> m >> g >> r;  
//   for(int i = 0; i < n; i++){
//     for(int j = 0; j < m; j++){
//       cin >> board[i][j];
//       if(board[i][j] == 2)
//         cand.push_back({i,j});
//     }
//   }
//   candsz = cand.size();
//   fill(brute+candsz-g-r, brute+candsz-r,GREEN);
//   fill(brute+candsz-r, brute+candsz,RED);
//   int mx = 0;
//   do{
//     mx = max(mx, solve());
//   }while(next_permutation(brute, brute+candsz));
//   cout << mx << '\n';
// }