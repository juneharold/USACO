#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int N, K, M=0, berry[1005];

int main()
{
    freopen("berries.in", "r", stdin);
    freopen("berries.out", "w", stdout);
    cin >> N >> K;
    for (int i=1; i<=N; i++) {
        cin >> berry[i];
        M=max(M, berry[i]);
    }

    int ans=0;
    for (int b=1; b<=M; b++) {
        int cnt=0, temp=0;
        multiset<int> left;
        for (int i=1; i<=1000; i++) left.insert(0);

        for (int i=1; i<=N; i++) {
            int buckets=berry[i]/b;
            left.insert(berry[i]%b);
            cnt+=buckets;
        }

        if (cnt<K/2) {
            while (cnt<K/2) {
                cnt++;
                left.erase(--left.end());
            }
            while (cnt<K) {
                cnt++;
                temp+=*--left.end();
                left.erase(--left.end());
            }
        }
        else if (cnt>=K/2 && cnt<K) {
            temp+=(cnt-K/2)*b;
            while (cnt<K) {
                cnt++;
                temp+=*--left.end();
                left.erase(--left.end());
            }
        }
        else {
            temp=b*K/2;
        }
        ans=max(ans, temp);
    }
    cout << ans;
}


/*
2 4
6 6

8 4
6 9 10 1 3 10 4 1
*/
