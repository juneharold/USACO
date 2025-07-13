#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef vector<int> vi;
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    vi a(2*n+2);
    int dif=n;
    a[1]=1;
    for(int i=3;i<=(n+2);i+=2)
    {
        a[i]=a[i-2]+dif;
        dif-=2;
    }
    a[2]=2*n+2;
    dif=n-1;
    for(int i=4;i<=n+2;i+=2)
    {
        a[i]=a[i-2]+dif;
        dif-=2;
    }
    for(int i=1;i<=n+2;i++)cout<<a[i]<<' ';
}