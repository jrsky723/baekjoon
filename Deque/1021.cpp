#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    deque <int> d;
    int n;
    int ans = 0;
    cin >> n;
    for(int i = 1; i < n+1; i++) d.push_back(i);
    int m;
    cin >> m;
    while (m--) {
        int a;
        cin >> a;
        for (int i = 0; i < d.size(); i++) {  
            if (d[i] == a) {
                if (i < d.size() - i) { //size()는 unsigned int를 명심하자
                    for (int j = 0; j < i; j++) {
                        d.push_back(d.front());
                        d.pop_front();
                        ans++;
                    }
                    d.pop_front();  /*d.pop - front를 밖에다가 빼도 된다.ans도 밑에서 한번에
                                    더해줘도 상관없다. 굳이 j를 따로 만들지 않아도. front가 
                                    a와 같을 때까지 실행 시켜주면 됌*/
                }
                else {
                    for (int j = 0; j < d.size() - i; j++) {
                        d.push_front(d.back());
                        d.pop_back();
                        ans++;
                    }
                    d.pop_front();
                }
                break;
            }
        }
    }
    cout << ans;
}
//정답코드
// Authored by : haneulkimdev
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/9571e70535a34702812d2a03510ac182
//#include <bits/stdc++.h>
//using namespace std;
//
//int main(void) {
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//    int n, m;
//    cin >> n >> m;
//    deque<int> DQ;
//    for (int i = 1; i <= n; i++) DQ.push_back(i);
//    int ans = 0;
//    while (m--) {
//        int t;
//        cin >> t;
//        int idx = find(DQ.begin(), DQ.end(), t) - DQ.begin(); // idx : t가 있는 위치
//        while (DQ.front() != t) {
//            if (idx < DQ.size() - idx) {
//                DQ.push_back(DQ.front());
//                DQ.pop_front();
//            }
//            else {
//                DQ.push_front(DQ.back());
//                DQ.pop_back();
//            }
//            ans++;
//        }
//        DQ.pop_front();
//    }
//    cout << ans;
//}
