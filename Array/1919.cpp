#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s1,s2;
    int ans = 0;
    int alphabet[26] = {};  //정답에선 2d array를 만듦.
    cin>>s1>>s2;
    for(char i : s1) alphabet[i-'a']++;
    for(char i : s2) alphabet[i-'a']--;
    //이 문제에선 2개의 string이기 때문에 이와 같이 구현되지만
    //확장성을 위해선 2차원 배열을 쓰는것이 나아보인다.
    //다차원 배열을 적극 활용해볼것.
    for(int i : alphabet) {
        if(i>0) ans+=i;
        else if(i<0) ans-=i;
    }
    cout<<ans;
}

//정답코드
// Authored by : twinkite
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/ae5d8d2f69f04530b4df0c591e9b07d5
// #include <bits/stdc++.h>
// using namespace std;

// int arr[2][26], res;
// string s1, s2;

// int main(void){
//   ios::sync_with_stdio(0);
//   cin.tie(0);
 
//   cin>>s1>>s2;
//   for(char c : s1)
//     arr[0][c-'a']++;
  
//   for(char c : s2)
//     arr[1][c-'a']++;
  
//   for(int i=0; i<26; i++)
//     res += abs(arr[0][i]-arr[1][i]);
  
//   cout << res;
// }