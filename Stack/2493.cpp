#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    stack <pair<int,int>> stk;
    int n,a;
    cin >> n;   //정답에 매우 근접, 하지만 더 효율적으로  하기위해
                //처음 스택에 탑의 최대 높이보다 1높은 값을 넣으면
    stk.push({ 0, 0 }); //매 순간 마다 이전이 0이 아닌지 확인할 필요없음
    for (int i = 0; i < n; i++) {
        cin >> a;   
        while (stk.top().first && stk.top().first < a) stk.pop();
        cout<<stk.top().second<<" ";
        stk.push({a , i+1});
    }
}
//정답코드
// Authored by : twinkite
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/44465623025e452bba5feb80b0b0e60e
//#include <bits/stdc++.h>
//using namespace std;
//#define X first
//#define Y second
//
//int N;
//stack<pair<int, int>> tower;
//
//int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//
//    cin >> N;
//    tower.push({ 100000001, 0 });
//    for (int i = 1; i <= N; i++) {
//        int height;
//        cin >> height;
//        while (tower.top().X < height)
//            tower.pop();
//        cout << tower.top().Y << " ";
//        tower.push({ height, i });
//    }
//}