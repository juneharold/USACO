#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
vi adj[1<<17],child[1<<17];
const long long mod=1e9+7;
int a,b;
void dfs(int k,int par)
{
    for(int i=0;i<adj[k].size();i++)
    {
        int t=adj[k][i];
        if(t==par)continue;
        child[k].push_back(t);
        dfs(t,k);
    }
}
vector<pi> dfs2(int k)
{
     vector<pi> u;
     vi v(501);
     u.push_back({1,1});
     for(int l=0;l<child[k].size();l++)
     {
        vector<pi> t=dfs2(child[k][l]);
        for(int i=0;i<u.size();i++)
        {
            for(int j=0;j<t.size();j++)
            {
                if(u[i].first+t[j].first>b)
                {
                    break;
                }
                long long temp=(long long)(v[u[i].first+t[j].first])+((long long)u[i].second*(long long)t[j].second);
                temp%=mod;
                v[u[i].first+t[j].first]=temp;
            }
        }
        u.clear();
        for(int i=0;i<=b;i++)
        {
            if(v[i])
            {
                u.push_back({i, v[i]});
                v[i]=0;
            }
        }
     }
     for(int i=0;i<u.size();i++)
     {
        v[u[i].first]+=u[i].second;
        v[u[i].first]%=mod;
     }
     u.clear();
     if(v[b])
     {
        u.push_back({0,v[b]});
     }
     if(v[a])
     {
        if(u.empty())
        {
            u.push_back({0,v[a]});
        }
        else
        {
            u.back().second+=v[a];
            u.back().second%=mod;
        }
     }
     for(int i=1;i<b;i++)if(v[i])u.push_back({i,v[i]});
     /*
     cout<<k<<'\n';
     for(int i=0;i<u.size();i++)cout<<u[i].first<<' '<<u[i].second<<'\n';
     */
     return u;
}
main()
{
    int n;
    scanf("%d %d %d",&n,&a,&b);
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1,0);
    vector<pi> temp=dfs2(1);
    if(temp[0].first==0)
    {
        printf("%d",temp[0].second);
    }
    else
    {
        printf("0");
    }
}