#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;
#define ll long long

vector<string> tokenize (string s) {
    vector<string> ret;
    string temp="";
    for (char x: s) {
        if (x==32) {
            ret.push_back(temp);
            temp="";
        }
        else temp+=x;
    }
    ret.push_back(temp);
    return ret;
}

vector<ll> graph[10];
ll n=0, ans=0;
void dfs(ll cur, ll val, ll cnt) {
    ll nv=val+cur*pow(10, cnt);
    if (cnt==0) {
        bool possible=true;
        ll temp=nv, appeared[10]={};
        while (temp>0) {
            ll x=temp%10;
            if (appeared[x]) possible=false;
            appeared[x]=1;
            temp/=10;
        }
        if (!possible) return;
        ans+=nv;
        return;
    }
    for (ll i=0; i<graph[cur].size(); i++) {
        ll nx=graph[cur][i];
        dfs(nx, nv, cnt-1);
    }
}

// 3 12 23 34 41 31
int main()
{
    string s; getline(cin, s);
    vector<string> in=tokenize(s);
    ll power=1;
    for (ll j=in[0].size()-1; j>=0; j--) {
        n+=(in[0][j]-48)*power;
        power*=10;
    }

    ll node[10]={};
    for (ll i=1; i<in.size(); i++) {
        ll a=in[i][0]-48, b=in[i][1]-48;
        node[a]=1;
        node[b]=1;
        graph[a].push_back(b);
    }

    for (ll i=1; i<=9; i++) {
        if (node[i]==1) dfs(i, 0, n);
    }

    cout << ans;
}
