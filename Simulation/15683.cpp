#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int board[9][9];
int cnt, mxCnt;
int n, m;
vector<pair<int, int>> cctvs;

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

void cctv1(int x, int y, int dir) {
  while (board[x][y] != 6) {
    x += dx[dir];
    y += dy[dir];
    if (OOB(x, y)) break;
    if (board[x][y] == 0) cnt++;
    if (board[x][y] <= 0) board[x][y]--;
  }
}

void rev1(int x, int y, int dir) {
  while (board[x][y] != 6) {
    x += dx[dir];
    y += dy[dir];
    if (OOB(x, y)) break;
    if (board[x][y] < 0) board[x][y]++;
    if (board[x][y] == 0) cnt--;
  }
}

void cctv(int k) {
  if (k == cctvs.size()) {
    mxCnt = max(cnt, mxCnt);
    return;
  }
  pair<int, int> cur = cctvs[k];
  switch (board[cur.X][cur.Y]) {
    case 1:
      for (int dir = 0; dir < 4; dir++) {
        cctv1(cur.X, cur.Y, dir);
        cctv(k + 1);
        rev1(cur.X, cur.Y, dir);
      }
      break;
    case 2:
      for (int dir1 = 0, dir2; dir1 < 2; dir1++) {
        dir2 = dir1 + 2;
        cctv1(cur.X, cur.Y, dir1);
        cctv1(cur.X, cur.Y, dir2);
        cctv(k + 1);
        rev1(cur.X, cur.Y, dir1);
        rev1(cur.X, cur.Y, dir2);
      }
      break;
    case 3:
      for (int dir1 = 0, dir2; dir1 < 4; dir1++) {
        dir2 = dir1 + 1;
        if (dir2 >= 4) dir2 -= 4;
        cctv1(cur.X, cur.Y, dir1);
        cctv1(cur.X, cur.Y, dir2);
        cctv(k + 1);
        rev1(cur.X, cur.Y, dir1);
        rev1(cur.X, cur.Y, dir2);
      }
      break;
    case 4:
      for (int dir1 = 0, dir2, dir3; dir1 < 4; dir1++) {
        dir2 = dir1 + 1;
        dir3 = dir1 + 2;
        if (dir2 >= 4) dir2 -= 4;
        if (dir3 >= 4) dir3 -= 4;
        cctv1(cur.X, cur.Y, dir1);
        cctv1(cur.X, cur.Y, dir2);
        cctv1(cur.X, cur.Y, dir3);
        cctv(k + 1);
        rev1(cur.X, cur.Y, dir1);
        rev1(cur.X, cur.Y, dir2);
        rev1(cur.X, cur.Y, dir3);
      }
      break;
    case 5:
      for (int dir = 0; dir < 4; dir++) cctv1(cur.X, cur.Y, dir);
      cctv(k + 1);
      for (int dir = 0; dir < 4; dir++) rev1(cur.X, cur.Y, dir);
      break;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  int space = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> board[i][j];
      if (board[i][j] == 0)
        space++;
      else if (board[i][j] != 6)
        cctvs.push_back({i, j});
    }
  }
  cctv(0);
  cout << space - mxCnt;
}
//정답코드
// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : -
// http://boj.kr/c961e6bf6107428caf200c11c964f9e1
// #include <bits/stdc++.h>
// using namespace std;
// #define X first
// #define Y second

// int dx[4] = {1,0,-1,0};
// int dy[4] = {0,1,0,-1}; // 남쪽, 동쪽, 북쪽, 서쪽 순서
// int n, m;
// int board1[10][10]; // 최초에 입력받은 board를 저장할 변수
// int board2[10][10]; // 사각 지대의 개수를 세기 위해 사용할 변수
// vector<pair<int,int> > cctv; // cctv의 좌표를 저장할 변수

// bool OOB(int a, int b){ // Out Of Bounds 확인
//   return a < 0 || a >= n || b < 0 || b >= m;
// }

// // (x,y)에서 dir 방향으로 진행하면서 벽을 만날 때 까지 지나치는 모든 빈칸을 7로 바꿔버림
// void upd(int x, int y, int dir){
//   dir %= 4;
//   while(1){
//     x += dx[dir];
//     y += dy[dir];
//     if(OOB(x,y) || board2[x][y] == 6) return; // 범위를 벗어났거나 벽을 만나면 함수를 탈출
//     if(board2[x][y] != 0) continue; // 해당 칸이 빈칸이 아닐 경우(=cctv가 있을 경우) 넘어감
//     board2[x][y] = 7; // 빈칸을 7로 덮음
//   }
// }

// int main(void) {
//   ios::sync_with_stdio(0);
//   cin.tie(0);
//   cin >> n >> m;
//   int mn = 0; // 사각 지대의 최소 크기 (=답)
//   for(int i = 0; i < n; i++){
//     for(int j = 0; j < m; j++){
//       cin >> board1[i][j];
//       if(board1[i][j] != 0 && board1[i][j] != 6)
//         cctv.push_back({i,j});
//       if(board1[i][j] == 0) mn++;
//     }
//   }
//   // 1 << (2*cctv.size())는 4의 cctv.size()승을 의미.
//   for(int tmp = 0; tmp < (1<<(2*cctv.size())); tmp++){ // tmp를 4진법으로 뒀을 때 각 자리수를 cctv의 방향으로 생각할 것이다.
//     for(int i = 0; i < n; i++)
//       for(int j = 0; j < m; j++)
//         board2[i][j] = board1[i][j];
//     int brute = tmp;    
//     for(int i = 0; i < cctv.size(); i++){
//       int dir = brute % 4;
//       brute /= 4;
//       int x = cctv[i].X;
//       int y = cctv[i].Y; // tie(x, y) = cctv[i];로 쓰면 1줄로 줄일 수 있음
//       if(board1[x][y] == 1){
//         upd(x,y,dir);
//       }
//       else if(board1[x][y] == 2){
//         upd(x,y,dir);
//         upd(x,y,dir+2);
//       }
//       else if(board1[x][y] == 3){
//         upd(x,y,dir);
//         upd(x,y,dir+1);
//       }
//       else if(board1[x][y] == 4){
//         upd(x,y,dir);
//         upd(x,y,dir+1);
//         upd(x,y,dir+2);
//       }
//       else{ // board1[x][y] == 5
//         upd(x,y,dir);
//         upd(x,y,dir+1);
//         upd(x,y,dir+2);
//         upd(x,y,dir+3);
//       }
//     }
//     int val = 0;
//     for(int i = 0; i < n; i++)
//       for(int j = 0; j < m; j++)
//         val += (board2[i][j]==0);
//     mn = min(mn, val);
//   }
//   cout << mn;
// }