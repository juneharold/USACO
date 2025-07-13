#include<bits/stdc++.h>
using namespace std;
typedef long double lf;
#define int long long
struct st{
    int x,y;
    lf val;
}ar[1<<17];
bool s(const st &p,const st &l)
{
    if(p.val==l.val)return p.x<l.x;
    return p.val<l.val;
}
bool s1(const st &p,const st &l)
{
    if(p.x==l.x)return p.y<l.y;
    return p.x<l.x;
}
bool s2(const st &p,const st &l)
{
    return p.y<l.y;
}
lf atan(int x,int y)
{
    return atan((lf)y/(lf)x);
}
int gcd(int a,int b)
{
    if(!b)return a;
    return gcd(b,a%b);
}
void solve()
{
    int n;cin>>n;
    int tp=0;
    for(int i=1;i<=n;i++)
    {
        int x,y;cin>>x>>y;
        if(x==0&&y==0)continue;
        tp++;
        ar[tp].x=x;
        ar[tp].y=y;
    }
    n=tp;
    if(!n)
    {
        cout<<"0\n";
        return;
    }
    int flag=0;
    for(int i=2;i<=n;i++)
    {
        if(ar[i-1].x*ar[i].y!=ar[i-1].y*ar[i].x)
        {
            flag=1;
        }
    }
    if(flag==0)
    {
        for(int i=2;i<=n;i++)
        {
            if(ar[i].x*ar[i-1].x<0||ar[i].y*ar[i-1].y<0)
            {
                flag=1;
            }            
        }
        if(flag==1)
        {
            cout<<"2\n";
            int g=gcd(abs(ar[1].x),abs(ar[1].y));
            cout<<ar[1].x/g<<' '<<ar[1].y/g<<'\n';
            cout<<-ar[1].x/g<<' '<<-ar[1].y/g<<'\n';
            return;
        }
        cout<<"1\n";
        int g=gcd(abs(ar[1].x),abs(ar[1].y));
        cout<<ar[1].x/g<<' '<<ar[1].y/g<<'\n';
        return;
    }
    vector<st> a,b,c;
    for(int i=1;i<=n;i++)
    {
        if(ar[i].x==0&&ar[i].y==0)continue;
        if(ar[i].x>0)
        {
            ar[i].val=atan(ar[i].x,ar[i].y);
            a.push_back(ar[i]);
        }
        else if(ar[i].x<0)
        {
            ar[i].val=atan(ar[i].x,ar[i].y);
            b.push_back(ar[i]);
        }
        else
        {
            c.push_back(ar[i]);
        }
    }
    if(a.empty()&&b.empty()&&c.empty())
    {
        cout<<"0\n";
        return;
    }
    if(!c.empty())sort(c.begin(),c.end(),s2);
    if(!a.empty())sort(a.begin(),a.end(),s);
    if(!b.empty())sort(b.begin(),b.end(),s);
    if(!c.empty()&&c.back().y>0)
    {
        a.push_back(c.back());
    }
    if(!c.empty()&&c[0].y<0)
    {
        b.push_back(c[0]);
    }
    if(a.empty())
    {
        cout<<"2\n";
        cout<<"-1 100000000000000000\n0 -1\n";
        return;
    }
    if(b.empty())
    {
        cout<<"2\n";
        cout<<"1 -100000000000000000\n0 1\n";
        return;
    }
    if(a.back().x!=0)
    {
        if(b[0].x!=0)
        {
            if(a.back().val<b[0].val)
            {
                int g=gcd(abs(a.back().x),abs(a.back().y));
                a.back().x/=g;
                a.back().y/=g;
                cout<<"2\n";
                cout<<a.back().x<<' '<<a.back().y<<'\n';
                a[0]=a.back();
                int mult=(1e17)/abs(a[0].x);
                if(a[0].y!=0)
                {
                    mult=min(mult,(int)((1e17)/abs(a[0].y)));
                }
                cout<<-a[0].x*mult-1<<' '<<-a[0].y*mult<<'\n';
                return;
            }
        }
    }
    if(b.back().x!=0)
    {
        if(a[0].x!=0)
        {
            if(b.back().val<a[0].val)
            {
                int g=gcd(abs(b.back().x),abs(b.back().y));
                b.back().x/=g;
                b.back().y/=g;
                cout<<"2\n";
                cout<<b.back().x<<' '<<b.back().y<<'\n';
                b[0]=b.back();
                int mult=(1e17)/abs(b[0].x);
                if(b[0].y!=0)
                {
                    mult=min(mult,(int)((1e17)/abs(b[0].y)));
                }
                cout<<-b[0].x*mult+1<<' '<<-b[0].y*mult<<'\n';
                return;
            }
        }
    }
    cout<<"3\n1 1\n1 -1\n-1 0\n";
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;cin>>T;
    while(T--)solve();
}