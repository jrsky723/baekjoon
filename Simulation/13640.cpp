#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
char board[11][11];
int n, m, ans = 11;
pair<int, int> posR, posB, curR, curB;

bool isOut(pair<int, int> &p) { return board[p.X][p.Y] == 'O'; }

void rotateP(pair<int, int> &p) {
  int temp = n - 1 - p.X;
  p.X = p.Y;
  p.Y = temp;
}

void rotate() {  // board를 시계방향으로 회전
  char temp[11][11];
  for (int i = 0; i < n; i++) copy(board[i], board[i] + m, temp[i]);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++) board[i][j] = temp[n - 1 - j][i];
  rotateP(curR);
  rotateP(curB);
  swap(n, m);
}

void move1(pair<int, int> &p) {  // 아래방향으로 움직임 (한 개)
  while (board[p.X + 1][p.Y] != '#') {
    if (board[p.X][p.Y] == 'O') break;
    p.X++;
  }
}

void move2(pair<int, int> &p1, pair<int, int> &p2) {  // 포개지는것 방지
  move1(p1);
  move1(p2);
  if (!isOut(p1) && p1 == p2) p2.X--;
}

void tilt(int dir) {  // dir = 0 :아래쪽 , 1 : 오른쪽 2 : 위쪽 3 : 왼쪽
  for (int i = 0; i < dir; i++) rotate();
  if (curB.X >= curR.X)
    move2(curB, curR);
  else
    move2(curR, curB);
  for (int i = 0; i < (4 - dir) % 4; i++) rotate();
}

void game(int k, int dir) {
  if (k == 10) return;
  tilt(dir);
  if (isOut(curR)) {
    if (!isOut(curB)) ans = min(ans, k + 1);
    return;
  }
  pair<int, int> newPosR, newPosB;
  tie(newPosR, newPosB) = {curR, curB};
  for (int newDir = 0; newDir < 4; newDir++) {
    if (newDir == dir) continue;
    game(k + 1, newDir);
    tie(curR, curB) = {newPosR, newPosB};
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> board[i][j];
      if (board[i][j] == 'R')
        posR = {i, j};
      else if (board[i][j] == 'B')
        posB = {i, j};
    }
  }
  for (int dir = 0; dir < 4; dir++) {
    tie(curR, curB) = {posR, posB};
    game(0, dir);
  }
  if (ans == 11) ans = -1;
  cout << ans;
}

//정답코드
// Authored by : jihwan0123
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/c6dff411258544ce8393f745f463df33
// #include <bits/stdc++.h>
// using namespace std;

// #define X first
// #define Y second

// int n, m;
// pair<int,int> red, blue; // 빨간 구슬과 파란 구슬의 위치
// string board[11];
// // dist[a][b][c][d] : 빨간 구슬이 (a, b)이고 파란 구슬이 (c, d)에 위치한 상황에 도달하기 위한 동작의 횟수
// int dist[11][11][11][11]; 
// int dx[4] = {0, 1, 0, -1};
// int dy[4] = {1, 0, -1, 0};

// // red_x, red_y : 빨간 구슬 좌표, blue_x, blue_y : 파란 구슬 좌표
// int bfs() {
//   queue<tuple<int, int, int, int>> q;
//   q.push({red.X, red.Y, blue.X, blue.Y});
//   dist[red.X][red.Y][blue.X][blue.Y] = 0;
//   while (!q.empty()) {
//     int rx, ry, bx, by;
//     tie(rx, ry, bx, by) = q.front();
//     q.pop();
//     int cnt = dist[rx][ry][bx][by];
//     // 10번 넘게 탈출 못하면 -1
//     if (cnt >= 10)
//       return -1;
//     // 4방향으로 기울이기
//     for (int i = 0; i < 4; i++) {
//       int n_rx = rx, n_ry = ry, n_bx = bx, n_by = by;

//       // Blue 이동, 가장자리에 모두 '#'이 있다는 조건으로 인해 OOB를 체크하지 않아도 됨. #나 O의 앞에서 정지함.
//       while (board[n_bx + dx[i]][n_by + dy[i]] == '.'){
//         n_bx += dx[i];
//         n_by += dy[i];
//       }
//       // Blue가 탈출했다면 실패이므로 continue
//       if(board[n_bx + dx[i]][n_by + dy[i]] == 'O') continue;

//       // Red 이동
//       while (board[n_rx + dx[i]][n_ry + dy[i]] == '.'){
//         n_rx += dx[i];
//         n_ry += dy[i];
//       }
//       // Red가 탈출했다면 종료, 바로 정답을 반환
//       if(board[n_rx + dx[i]][n_ry + dy[i]] == 'O') return cnt+1;

//       // Red, Blue가 겹쳐진 경우 늦게 출발한 구슬을 한칸 뒤로 이동
//       if ((n_rx == n_bx) && (n_ry == n_by)) {
//         if (i == 0) // 위쪽
//           ry < by ? n_ry-- : n_by--;
//         else if (i == 1) // 오른쪽
//           rx < bx ? n_rx-- : n_bx--;
//         else if (i == 2) // 아래쪽
//           ry > by ? n_ry++ : n_by++;
//         else // 왼쪽
//           rx > bx ? n_rx++ : n_bx++;
//       }
//       // 이미 (n_rx, n_ry, n_bx, n_by)를 방문한 적이 있다면 continue
//       if (dist[n_rx][n_ry][n_bx][n_by] != -1) continue;
//       dist[n_rx][n_ry][n_bx][n_by] = cnt + 1;
//       q.push({n_rx, n_ry, n_bx, n_by});
//     }
//   }
//   return -1;
// }
// int main(void) {
//   ios::sync_with_stdio(0);
//   cin.tie(0);

//   // 거리 배열 초기화
//   for(int i = 0; i < 10; i++)
//     for(int j = 0; j < 10; j++)
//       for(int k = 0; k < 10; k++)
//         fill(dist[i][j][k], dist[i][j][k]+10, -1);
  
//   cin >> n >> m;
//   for (int i = 0; i < n; i++) {
//     cin >> board[i];
//     for (int j = 0; j < m; j++) {      
//       if (board[i][j] == 'B'){
//         blue = {i, j};
//         board[i][j] = '.';
//       }
//       else if (board[i][j] == 'R'){
//         red = {i, j};
//         board[i][j] = '.';
//       }
//     }
//   }
  
//   cout << bfs();
// }
/*
빨간 구슬과 파란 구슬의 좌표를 가지고 4차원에서 BFS를 돌리면 된다. O(N^2M^2)에 동작한다.
최대 10번이라는 제한이 있기 때문에 O(4^10)의 백트래킹으로도 통과가 가능하다.
*/