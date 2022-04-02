#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;      //이 문제는 범위를 잘 파악해야한다
    long long ans = 0;  //ans의 범위는 80000(80000+1)/2 ->int범위초과
    stack<int> stk; 
    cin >> n;
    int height;
    for (int i = 0; i < n; i++) {
        cin >> height;
        while (!stk.empty() && stk.top() <= height) stk.pop();
        ans += stk.size();
        stk.push(height);   //작은 숫자가 추가될 때마다 그 이전 빌딩들의               
    }                       //벤치마킹이 1증가를 표현
    cout << ans;  
}

//정답 코드
// Authored by : unluckyjung
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/a84f083cdee3436f9f46acdef175e55f
//#include <bits/stdc++.h>
//using namespace std;
//
//#define ll long long
//
//stack<int> s;
//int n;
//ll ans;
//
//int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//
//    cin >> n;
//    ll h;
//    while (n--) {
//        cin >> h;
//        while (!s.empty() && s.top() <= h)
//            s.pop();
//        ans += s.size();
//        s.push(h);
//    }
//    cout << ans;
//    return 0;
//}