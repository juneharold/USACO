#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

long long pfs[100005]={};
map<long long, long long> cnt;

int main()
{
    long long N, X; cin >> N >> X;
    for (long long i=1; i<=N; i++) {
        long long a; cin >> a;
        if (a>=X) pfs[i]=pfs[i-1]+1;
        else pfs[i]=pfs[i-1]-1;
    }
    for (int i=1; i<=N; i++) cout << pfs[i] << " ";
    cout << endl;

    long long low=0, high=0, ans=0;

    cnt[0]++;
    if (pfs[1]>pfs[0]) low++;
    else high++;

    for (long long i=1; i<=N; i++) {
       //pfs[i]-pfs[j]>=0 j는 0 포함.
       if (pfs[i]>pfs[i-1]) {
           low+=cnt[pfs[i]];
           high-=cnt[pfs[i]];
       }
       else {
           low-=cnt[pfs[i]];
           high+=cnt[pfs[i]];
       }
       cout << low << "\n";
       ans+=low;
       cnt[pfs[i]]++; 
   }

   cout << ans;
   return 0;
}

/*
8 6
10
5
6
2
1
1
10
10
*/
