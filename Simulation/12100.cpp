#include <bits/stdc++.h>
using namespace std;

#define first X
#define second Y
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, ans;
int board[22][22], origin[22][22];
bool isMerge[22][22];

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

void merge(int x, int y, int dir) {
  int nx = x + dx[dir];
  int ny = y + dy[dir];
  while (!board[nx][ny]) {
    if (OOB(nx, ny)) break;
    nx += dx[dir];
    ny += dy[dir];
  }
  if (!OOB(nx, ny)) {
    if (board[nx][ny] == board[x][y] && !isMerge[nx][ny]) {
      board[nx][ny] += board[x][y];
      isMerge[nx][ny] = true;
      board[x][y] = 0;
    } else {
      if (!(nx - dx[dir] == x && ny - dy[dir] == y)) {
        board[nx - dx[dir]][ny - dy[dir]] = board[x][y];
        board[x][y] = 0;
      }
    }
  } else {
    board[nx - dx[dir]][ny - dy[dir]] = board[x][y];
    board[x][y] = 0;
  }
}

void shift(int dir) {
  int rowStart = 0, rowEnd = n - 1, colStart = 0, colEnd = n - 1;
  int xInc = 1, yInc = 1;
  bool colFisrt = true;
  for (int i = 0; i < n; i++) fill(isMerge[i], isMerge[i] + n, 0);
  switch (dir) {
    case 0:
      swap(rowStart, rowEnd);
      xInc *= -1;
      break;
    case 1:
      swap(colStart, colEnd);
      yInc *= -1;
      colFisrt = false;
      break;
    case 3:
      colFisrt = false;
      break;
  }

  if (colFisrt) {
    for (int x = rowStart + xInc; x != rowEnd + xInc; x += xInc)
      for (int y = colStart; y != colEnd + yInc; y += yInc)
        if (board[x][y]) merge(x, y, dir);
  } else {
    for (int y = colStart + yInc; y != colEnd + yInc; y += yInc)
      for (int x = rowStart; x != rowEnd + xInc; x += xInc)
        if (board[x][y]) merge(x, y, dir);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> origin[i][j];
  for (int tmp = 0; tmp < (1 << (2 * 5)); tmp++) {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) board[i][j] = origin[i][j];
    int brute = tmp;
    for (int i = 0; i < 5; i++) {
      int dir = brute % 4;
      brute /= 4;
      shift(dir);
    }
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) ans = max(ans, board[i][j]);
  }
  cout << ans;
}

//정답코드
// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : -
// http://boj.kr/82284615e5814db489ee482ef77bcaf4
// #include <bits/stdc++.h>
// using namespace std;

// int board1[21][21];
// int board2[21][21];
// int n;

// void rotate(){ // board2를 시계 방향으로 90도 회전하는 함수
//   int tmp[21][21];
//   for(int i = 0; i < n; i++)
//     for(int j = 0; j < n; j++)
//       tmp[i][j] = board2[i][j];
//   for(int i = 0; i < n; i++)
//     for(int j = 0; j < n; j++)
//       board2[i][j] = tmp[n-1-j][i];
// }

// void tilt(int dir){
//   while(dir--) rotate();
//   for(int i = 0; i < n; i++){
//     int tilted[21] = {}; // board2[i]를 왼쪽으로 기울인 결과를 저장할 변수
//     int idx = 0; // tilted 배열에서 어디에 삽입해야 하는지 가리키는 변수
//     for(int j = 0; j < n; j++){
//       if(board2[i][j] == 0) continue;
//       if(tilted[idx] == 0) // 삽입할 위치가 비어있을 경우
//         tilted[idx] = board2[i][j];
//       else if(tilted[idx] == board2[i][j]) // 같은 값을 갖는 블록이 충돌할 경우
//         tilted[idx++] *= 2;
//       else // 다른 값을 갖는 블록이 충돌
//         tilted[++idx] = board2[i][j];
//     }
//     for(int j = 0; j < n; j++) board2[i][j] = tilted[j]; // board2[i]에 tilted를 덮어씀
//   }
// }


// int main(void) {
//   ios::sync_with_stdio(0);
//   cin.tie(0);

//   cin >> n;
//   for(int i = 0; i < n; i++)
//     for(int j = 0; j < n; j++)
//       cin >> board1[i][j];

//   int mx = 0;
//   for(int tmp = 0; tmp < 1024; tmp++){
//     for(int i = 0; i < n; i++)
//       for(int j = 0; j < n; j++)
//         board2[i][j] = board1[i][j];
//     int brute = tmp;
//     for(int i = 0; i < 5; i++){
//       int dir = brute % 4;
//       brute /= 4;
//       tilt(dir);
//     }
//     for(int i = 0; i < n; i++)
//       for(int j = 0; j < n; j++)
//         mx = max(mx, board2[i][j]);
//   }
//   cout << mx;
// }