#include <iostream>
using namespace std;

long long rem[1000005]={};

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
        sum += a;
        rem[i]=sum%M;
    }
    long long counter=0;
    long long ans=0;
    cout << ans;
}

/*
5 3
1 2 3 1 2 

4 5
2 4 1 2
*/

