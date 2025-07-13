
#define rep(i,n) for(int i=0; i< (n); i++)
#define rep1(i,n) for(int i=1; i<=(n); i++)
#define repr(i,a,b) for(int i = (a); i <= (b); i++)
#define pb push_back
#define eb emplace_back
#define ep emplace
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vll = vector<long long>;
typedef pair<ll,int> pi;
const int MAXN=60010;
struct edg{
    int pos,cap,rev,cost,idx;
};
vector<edg> gph[MAXN];
void clear()
{
    for(int i=0; i<MAXN; i++)
    {
        gph[i].clear();
    }
}
void add_edge(int s,int e,int x,int c, int idx=-1) // x = flow, c = cost
{
    gph[s].push_back({e,x,(int)gph[e].size(),c,idx});
    gph[e].push_back({s,0,(int)gph[s].size()-1,-c,-1});
}

ll phi[MAXN], inque[MAXN], dist[MAXN];
void prep(int src,int sink)
{
    memset(phi,0x3f,sizeof(phi));
    memset(dist,0x3f,sizeof(dist));
    queue<int> que;
    que.push(src);
    inque[src] = 1;
    while(!que.empty())
    {
        int x = que.front();
        que.pop();
        inque[x]=0;
        for(auto &i : gph[x])
        {
            if(i.cap > 0 && phi[i.pos] > phi[x] + i.cost)
            {
                phi[i.pos] = phi[x] + i.cost;
                if(!inque[i.pos])
                {
                    inque[i.pos]=1;
                    que.push(i.pos);
                }
            }
        }
    }
    for(int i=0; i<MAXN; i++)
    {
        for(auto &j : gph[i])
        {
            if(j.cap > 0)
            {
                j.cost+=phi[i]-phi[j.pos];
            }
        }
    }
    priority_queue<pi, vector<pi>, greater<pi> > pq;
    pq.push(pi(0,src));
    dist[src]=0;
    while(!pq.empty())
    {
        auto l = pq.top();
        pq.pop();
        if(dist[l.second]!=l.first)continue;
        for(auto &i : gph[l.second])
        {
            if(i.cap > 0 && dist[i.pos] > l.first + i.cost)
            {
                dist[i.pos] = l.first + i.cost;
                pq.push(pi(dist[i.pos],i.pos));
            }
        }
    }
}
bool vis[MAXN];
int ptr[MAXN];
int dfs(int pos,int sink,int flow)
{
    vis[pos]=1;
    if(pos==sink)return flow;
    for(;ptr[pos]<gph[pos].size();ptr[pos]++)
    {
        auto &i = gph[pos][ptr[pos]];
        if(!vis[i.pos]&&dist[i.pos]==i.cost+dist[pos]&&i.cap>0)
        {
            int ret = dfs(i.pos,sink,min(i.cap,flow));
            if(ret!=0)
            {
                i.cap-=ret;
                gph[i.pos][i.rev].cap+=ret;
                return ret;
            }
        }
    }
    return 0;
}
ll match(int src,int sink,int sz=MAXN)
{
    prep(src,sink);
    for(int i=0;i<sz;i++)
    {
        dist[i]+=phi[sink]-phi[src];
    }
    ll ret=0;
    int flow=0;
    while(true)
    {
        memset(ptr,0,sizeof(ptr));
        memset(vis,0,sizeof(vis));
        ll tmp=0;
        while((tmp=dfs(src,sink,1e9)))
        {
            ret+=dist[sink]*tmp;
            flow+=tmp;
            memset(vis,0,sizeof(vis));
        }
        tmp=1e18;
        for(int i=0;i<sz;i++)
        {
            if(!vis[i])continue;
            for(auto &j : gph[i])
            {
                if(j.cap > 0 && !vis[j.pos])
                {
                    tmp=min(tmp,(dist[i]+j.cost)-dist[j.pos]);
                }
            }
        }
        if(tmp > 1e9 - 200)break;
        for(int i=0; i<sz; i++)
        {
            if(!vis[i])
            {
                dist[i]+=tmp;
            }
        }
    }
    return ret;
}
int main()
{
    int n;cin>>n;
    int sz=0;
    int temp=n*2+1;
    for(int i=1;i<=n;i++)
    {
        sz+=temp;
        temp+=2;
    }
    for(int i=1;i<=sz;i++)
    {
        add_edge(0,i,1,0);
        add_edge(i+sz,sz*2+1,1,0);
    }
    temp=n*2;
    int pt=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<temp;j++)
        {
            int x;cin>>x;
            add_edge()
        }
    }
}