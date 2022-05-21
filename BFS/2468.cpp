#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[101][101];
bool vis[101][101];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

queue <pair<int,int>> Q;
int N;

void bfs(int h,int x,int y){
    Q.push({x,y});
    vis[x][y] = true;
    while(!Q.empty()){
        pair <int,int> cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if(vis[nx][ny] || board[nx][ny] <= h) continue;
            vis[nx][ny] = true;
            Q.push({nx,ny});
        }
    }
}

int main(){   
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int ans = 0;
    cin>>N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>board[i][j];
        }
    }
    for(int h = 1; h <= 100; h++){
        int count = 0;
        for(int i = 0; i < N; i++) fill(vis[i],vis[i] + N,0);
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(!vis[i][j] && board[i][j] > h){
                    bfs(h,i,j);
                    count++;
                }
            }
        }
        ans = max(count,ans);
    }
    if(ans == 0) ans = 1;
    cout<<ans;
}

//정답 코드
// Authored by : std-freejia
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/4b36ea477ba8433c9cf9d053a711e07b
// #include <bits/stdc++.h>
// #define X first
// #define Y second
// using namespace std;

// int n, maxcnt, maxlimit;
// int area[102][102];
// int vis[102][102]; // 비에 잠긴 영역
// int dx[] = {0, 1, 0, -1};
// int dy[] = {1, 0, -1, 0};

// void bfs(int i, int j, int limit){
//   queue<pair<int,int>> q;
//   vis[i][j] = 1; // 방문표시
//   q.push({i, j}); // 푸시
//   while(!q.empty()){
//     auto cur = q.front(); q.pop();

//     for(int i = 0; i < 4; i++){
//       int nx = cur.X + dx[i];
//       int ny = cur.Y + dy[i];

//       if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue; // 정상 범위 체크
//       if(vis[nx][ny] == 0 && area[nx][ny] > limit){  // 미방문, 침수되지 않음
//         vis[nx][ny] = 1;  // 첫 방문이라면 방문표시
//         q.push({nx, ny}); // 푸시
//       }
//     }
//   }
// }

// int main(void) {
//   ios::sync_with_stdio(0);
//   cin.tie(0);

//   cin >> n;
//   for(int i = 0; i < n; i++) {
//     for (int j = 0; j < n; j++) { // 0인 영역에서 시작하기
//       cin >> area[i][j];
//       maxlimit = max(area[i][j], maxlimit); // 잠기는 최대 높이
//     }
//   }

//   for(int limit = 0; limit <= maxlimit; limit++) {
//     for(int i = 0; i < n; i++)
//       fill(vis[i], vis[i]+n, 0); // 방문배열 초기화
    
//     int cnt = 0;
//     for(int i = 0; i < n; i++) {
//       for (int j = 0; j < n; j++) {
//         if (area[i][j] > limit && vis[i][j] == 0) { // 침수 여부, 방문 여부
//           bfs(i, j, limit);
//           cnt++;
//         }
//       }
//     }
//     maxcnt = max(cnt, maxcnt);
//   }
//   cout << maxcnt;
// }