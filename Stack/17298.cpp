#include <bits/stdc++.h>
using namespace std;
int arr[1000000]; //i번째에 오큰수 저장
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    stack <pair<int,int>> s;   //i번째, n
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        while (!s.empty() && s.top().second < a) {
            arr[s.top().first] = a;
            s.pop();
        }         //정답과 순서만 다를 뿐 비슷하다. pair를 쓰는대신 arr하나더 생성
        arr[i] = -1;
        s.push({ i,a });
    }
    for (int i = 0; i < n; i++)
        if(arr[i]) cout << arr[i] << " ";
}
//정답 코드
// Authored by : haneulkimdev
// Co-authored by : -
// http://boj.kr/98a57090ad0b472f86492f495a362127
//#include <bits/stdc++.h>
//using namespace std;
//
//int a[1000000];
//int ans[1000000];
//int main(void) {
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//    int n;
//    cin >> n;
//    for (int i = 0; i < n; i++) cin >> a[i];
//    stack<int> S;
//    for (int i = n - 1; i >= 0; i--) {
//        while (!S.empty() && S.top() <= a[i]) S.pop();
//        if (S.empty())
//            ans[i] = -1;
//        else
//            ans[i] = S.top();
//        S.push(a[i]);
//    }
//    for (int i = 0; i < n; i++) cout << ans[i] << ' ';
//}