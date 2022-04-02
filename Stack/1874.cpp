#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio;
    cin.tie(0);
    stack<int> s;
    queue<int> input;   //입력이 끊겨도 정답으로 처리된다. meaningless
    queue<bool>ans;     //string으로 정답을 입력받으면 더 가볍다.
    int n,cnt=0;
    cin>>n;
    for(int i = 0; i < n; i++){
        int num;
        cin>>num;
        input.push(num);
    }
    s.push(0);
    while(!input.empty()){
        while(s.top() < input.front()){
            cnt++;
            s.push(cnt);        //s.push(cnt++) 를 생각하자
            ans.push(1);
        }
        if(s.top() > input.front())
            break;
        s.pop();
        input.pop();
        ans.push(0);
    }
    if(input.empty()){
        while(!ans.empty()){
            if(ans.front()) cout<<"+"<<'\n';
            else cout<<"-"<<'\n';      //정답에서 처럼 출력을 위한건
            ans.pop();                 //string으로 구현하는게 간단
        }
    }
    else
        cout<<"NO"<<'\n';   //while문 안에 return 0을 줘서 함수를 종료
                            //하는 방법이 나아보임
}
//정답
// Authored by : haneulkimdev
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/7a18dc82bd4041aaa59c745f06d4ba60
// #include <bits/stdc++.h>
// using namespace std;

// int main(void) {
//   ios::sync_with_stdio(0);
//   cin.tie(0);
//   int n;
//   cin >> n;
//   stack<int> S;
//   int cnt = 1;
//   string ans;
//   while (n--) {
//     int t;
//     cin >> t;
//     while (cnt <= t) {
//       S.push(cnt++);
//       ans += "+\n";
//     }
//     if (S.top() != t) {
//       cout << "NO\n";
//       return 0;
//     }
//     S.pop();
//     ans += "-\n";
//   }
//   cout << ans;
// }

/*
현재 처리를 필요로 하는 수는 cnt이다. cnt 이상인 값 t가 주어지면 그 값을 pop할 수 있게 cnt가 t가
될 때 까지 push를 해야 한다(18-21줄). 만약 22번째 줄과 같이 S.top()과 t가 일치하지 않는다면
올바르지 않은 수열이다.
*/