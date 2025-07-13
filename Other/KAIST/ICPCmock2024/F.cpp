#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
int a[400001];
void solve(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    int cnt = 0, flag = 0;
    for(int i=1;i<n;i++){
        if(a[i]==111) flag++;
        if(a[i]==110) cnt++;
        if(a[i]==11) cnt++;
    }
    if(flag%2==1)
    {
        cout<<"Yesyes\n";
    }
    else if(cnt%2==0)
    {
        cout<<"Nono\n";
    }
    else
    {
        cout<<"Yesyes\n";
    }
}
int main(){
    int repeat;
    cin >> repeat;
    while(repeat--){
        solve();
    }
}