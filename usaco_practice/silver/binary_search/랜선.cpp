#include <iostream>
using namespace std;

int LAN[10005]={};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int K, N; // N은 필요한 개수 
    cin >> K >> N;
    for (int i=0; i<K; i++) cin >> LAN[i];
    long long high = 2*1024*1024*1024-1, low=0;
    while (low<high)
    {
        long long mid=(low+high)/2+1;
        long long number=0;
        for (int i=0; i<K; i++)
        {
            number+=LAN[i]/mid;
        }
        if (number<N) high=mid-1;
        else low=mid;
    }
    cout << low;
}
