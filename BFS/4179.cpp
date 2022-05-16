#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
char board[1000][1001];
int Jdist[1000][1000];
int Fdist[1000][1000];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int r, c;
	queue <pair<int, int>> JQ;
	queue <pair<int, int>> FQ;
   
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            Fdist[i][j] = Jdist[i][j] = -1;
            cin >> board[i][j];
            if (board[i][j] == 'J') {
                JQ.push({ i,j });
                Jdist[i][j] = 0;
            }
            else if (board[i][j] == 'F') {
                FQ.push({ i,j });
                Fdist[i][j] = 0;
            }
        }
    }

    while (!FQ.empty()) {
        pair<int,int> cur = FQ.front();
        int curDist = Fdist[cur.X][cur.Y];
        FQ.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if (board[nx][ny] == '#' || Fdist[nx][ny] >= 0) continue;
            Fdist[nx][ny] = curDist + 1;
            FQ.push({ nx,ny });
        }
    }

    while (!JQ.empty()) {
        pair<int, int> cur = JQ.front();
        int curDist = Jdist[cur.X][cur.Y];
        JQ.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
                cout << curDist + 1;
                return 0;
            }
            if (board[nx][ny] == '#' || Jdist[nx][ny] >= 0)
                continue;
            if (curDist + 1 >= Fdist[nx][ny] && Fdist[nx][ny] != -1) continue;
            Jdist[nx][ny] = curDist + 1;
            JQ.push({ nx,ny });
        }
    }
    cout << "IMPOSSIBLE";
}
