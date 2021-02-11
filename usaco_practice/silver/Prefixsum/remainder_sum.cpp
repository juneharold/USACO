#include <iostream>
using namespace std;

long long pfs[10000005]={};
long long ans=0;
long long combination[1001]={};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    long long sum=0;
    for (int i=1; i<=N; i++)
    {
        int a; 
        cin >> a;
        pfs[i]=(pfs[i-1]+a)%M;
        if (pfs[i]==0)
        {
            ans += 1;
        }
        combination[pfs[i]]+=1;
    }
    for (int i=0; i<1001; i++)
    {
        ans += (combination[i]*(combination[i]-1))/2;
    }
    cout << ans << "\n";
}

/*
5 3
1 2 3 1 2 

4 5
2 4 1 2
*/

