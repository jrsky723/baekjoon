#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    stack <char> stk;
    while (1) {
        getline(cin,s);
        if (!s.compare(".")) break;
        bool isBalance = 1;
        for (char c : s) {
            if (c == '[' || c == '(') {
                stk.push(c);
            }
            else if (c == ']') {
                if (stk.empty()) isBalance = 0;
                else if (stk.top() != '[') isBalance = 0;   // 같은 알고리즘 하지만 코드를
                else stk.pop();                         //더 줄여보자
            }
            else if (c == ')') {
                if (stk.empty()) isBalance = 0;
                else if (stk.top() != '(') isBalance = 0;
                else stk.pop();
            }
            if (!isBalance) break;
        }

        if (!stk.empty()) isBalance = 0;

        if (isBalance) cout << "yes" <<'\n';
        else cout << "no"<<'\n';
        while (!stk.empty()) stk.pop();
    }
}

//정답코드
// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : -
// http://boj.kr/9dd230a7a6cf4fdaa3f2abde6c96c59c
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//    while (true) {
//        string a;
//        getline(cin, a);
//        if (a == ".") break;
//        stack<char> s;
//        bool isValid = true;
//        for (auto c : a) {
//            if (c == '(' || c == '[') s.push(c);
//            else if (c == ')') {
//                if (s.empty() || s.top() != '(') {
//                    isValid = false;
//                    break;
//                }
//                s.pop();
//            }
//            else if (c == ']') {
//                if (s.empty() || s.top() != '[') {
//                    isValid = false;
//                    break;
//                }
//                s.pop();
//            }
//        }
//        if (!s.empty()) isValid = false;
//        if (isValid) cout << "yes\n";
//        else cout << "no\n";
//    }
//}