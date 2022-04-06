#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        deque <int> dq;
        string s;
        string ans;
        bool reverse = 0;   //뒤집어짐 표시
        int n;
        char c;
        cin >> s;
        cin >> n;
        cin >> c;
        if (!n) cin >> c;

        else {
            while (c != ']') {
                int x;          //입력에 순서가 있어서 이런식으로 나눠서 가능했지만
                cin >> x;       //정답에서는 parse함수를 만들어서 1자리수 이상을 string하나에서
                dq.push_back(x); //입력가능하도록 처리하였다. 참고할것
                cin >> c;
            }
        }
        for (char c : s) {
            if (c == 'R') {
                reverse = !reverse;
            }
            else {
                if (dq.empty()) {
                    ans = "error";
                    break;
                }
                else if (reverse) //뒤집어져있으면 뒤에서제거
                    dq.pop_back();
                else
                    dq.pop_front();
            }
        }
        if (ans != "error") {
            ans += "[";
            if (reverse) {
                while (dq.size() > 1) {
                    ans += to_string(dq.back());
                    ans += ",";
                    dq.pop_back();
                }
                if (!dq.empty())
                    ans += to_string(dq.back());
            }
            else {
                while (dq.size() > 1) {
                    ans += to_string(dq.front());
                    ans += ",";
                    dq.pop_front();
                }
                if (!dq.empty())
                    ans += to_string(dq.front());
            }
            ans += ']';
        }
        cout << ans << '\n';
    }
}
//정답코드
// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : -
// http://boj.kr/e93d3fd7a3bc43179af06505c3f524b0
//#include <bits/stdc++.h>
//using namespace std;
//
//void parse(string& tmp, deque<int>& d) {
//    int cur = 0;
//    for (int i = 1; i + 1 < tmp.size(); i++)
//    {
//        if (tmp[i] == ',') {
//            d.push_back(cur);
//            cur = 0;
//        }
//        else {
//            cur = 10 * cur + (tmp[i] - '0'); 
//        }
//    }
//    if (cur != 0)
//        d.push_back(cur);
//}
//
//void print_result(deque<int>& d) {
//    cout << '[';
//    for (int i = 0; i < d.size(); i++)
//    {
//        cout << d[i];
//        if (i + 1 != d.size())
//            cout << ',';
//    }
//    cout << "]\n";
//}
//
//int t;
//int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//    cin >> t;
//    while (t--) {
//        deque<int> d;
//        int rev = 0;
//        int n;
//        bool isWrong = false;
//        string query, tmp;
//        cin >> query;
//        cin >> n;
//        cin >> tmp;
//        parse(tmp, d);
//        for (char c : query)
//        {
//            if (c == 'R')
//                rev = 1 - rev;
//            else {
//                if (d.empty()) {
//                    isWrong = true;
//                    break;
//                }
//                if (!rev) d.pop_front();
//                else d.pop_back();
//            }
//        }
//        if (isWrong)
//            cout << "error\n";
//        else {
//            if (rev) reverse(d.begin(), d.end());
//            print_result(d);
//        }
//    }
//}