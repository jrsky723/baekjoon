#include <bits/stdc++.h>
using namespace std;
int dis[100003];
bool vis[100003];
const int MAX = 100000;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    queue <int> Q;
    cin >> n >> k;
    vis[n] = true;
    Q.push(n);
    while (!Q.empty()) {
        int X = Q.front(); Q.pop();
        if (X == k) {
            cout << dis[X];
            break;
        }
        int nx = X;
        //(int nxt : {cur - 1, cur + 1, 2 * cur}) 이걸 이용하자
        for (int i = 0; i < 3; i++) {
            switch (i) {
                case 0: nx = X - 1;
                    break;
                case 1: nx = X + 1;
                    break;
                case 2: nx = 2 * X;
                    break;
            }
            if (nx<0 || nx > MAX) continue;
            if (vis[nx]) continue;
            Q.push(nx);
            vis[nx] = true;
            dis[nx] = dis[X] + 1;
        }
    }
}

// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : -
// http://boj.kr/ba53d62b7651443cbf7b2028c28ce197
//#include <bits/stdc++.h>
//using namespace std;
//#define X first
//#define Y second
//int dist[100002];
//int n, k;
//int main(void) {
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//    cin >> n >> k;
//    fill(dist, dist + 100001, -1);
//    dist[n] = 0;
//    queue<int> Q;
//    Q.push(n);
//    while (dist[k] == -1) {
//        int cur = Q.front(); Q.pop();
//        for (int nxt : {cur - 1, cur + 1, 2 * cur}) {
//            if (nxt < 0 || nxt > 100000) continue;
//            if (dist[nxt] != -1) continue;
//            dist[nxt] = dist[cur] + 1;
//            Q.push(nxt);
//        }
//    }
//    cout << dist[k];
//}