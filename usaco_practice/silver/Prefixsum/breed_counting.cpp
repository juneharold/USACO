#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int PFScow1[1000005]={};
int PFScow2[1000005]={};
int PFScow3[1000005]={};

int main()
{
    //freopen("bcount.in", "r", stdin);
    //freopen("bcount.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, Q;
    cin >> N >> Q;
    int cow1=0, cow2=0, cow3=0;
    for (int i=1; i<=N; i++)
    {
        int a;
        cin >> a;
        if (a==1)
        {
            cow1+=1;
        }
        else if (a==2)
        {
            cow2+=1;
        }
        else if (a==3)
        {
            cow3+=1;
        }
        PFScow1[i]=cow1;
        PFScow2[i]=cow2;
        PFScow3[i]=cow3;
    }
    // now count
    for (int i=0; i<Q; i++)
    {
        int start, end;
        cin >> start >> end;
        cout << PFScow1[end]-PFScow1[start-1] << " ";
        cout << PFScow2[end]-PFScow2[start-1] << " ";
        cout << PFScow3[end]-PFScow3[start-1] << "\n";
    }
}
