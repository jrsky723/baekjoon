#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    long long ans = 0;
    cin >> n;
    stack <pair<int,int>> s;    //키,연속으로 같은 키가 나온 수
    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;
        int cnt = 1;
        while (!s.empty() && h >= s.top().X) {  //스택에 내림차순으로 쌓기
            ans += s.top().Y;   //이전 숫자의 개수 만큼 쌍이 증가함.
            if (s.top().X == h) cnt += s.top().Y;  //같은 수 만큼 cnt를 증가
            s.pop();            // 스택을 내림차순으로 만들기
        }
        if (!s.empty()) ans++;  //스택이 비어있다면, h를 봐줄 상대가 없음
        s.push({h,cnt});       
    }
    cout << ans;
}
//정답코드
// Authored by : haneulkimdev
// Co-authored by : -
// http://boj.kr/cbef82389d1048db80c9652d18b71304
//#include <bits/stdc++.h>
//using namespace std;
//#define X first
//#define Y second
//
//int main(void) {
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//    int n;
//    cin >> n;
//    stack<pair<int, int>> S;
//    long long ans = 0;
//    while (n--) {
//        int h;
//        cin >> h;
//        int cnt = 1;
//        while (!S.empty() && S.top().X <= h) {
//            ans += S.top().Y;
//            if (S.top().X == h) cnt += S.top().Y;
//            S.pop();
//        }
//        if (!S.empty()) ans++;
//        S.push({ h, cnt });
//    }
//    cout << ans;
//}