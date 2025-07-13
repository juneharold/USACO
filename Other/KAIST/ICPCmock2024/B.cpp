#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        if(n<=5)
        {
            cout<<"-1\n";
            continue;
        }
        vector<int> a(4);
        a[0]=1;
        a[1]=3;
        a[2]=n-3;
        a[3]=n-2;
        a.erase(unique(a.begin(),a.end()),a.end());
        cout<<a.size()<<'\n';
        for(int i=0;i<a.size();i++)
        {
            cout<<a[i]<<' ';
        }
        cout<<'\n';
    }
}