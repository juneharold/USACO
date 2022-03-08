#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
#define ll long long
#define f first
#define s second

int f[100005]={}, last[10005]={}, cur[10005]={};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while (T--) {
        int M, N, K; cin >> M >> N >> K;
        for (int i=1; i<=N; i++) {
            cin >> f[i];
            last[f[i]]=i;
        }
        int a=1, b=K, sz=0;

        deque<int> d1, d2;
        for (int idx=1; idx<=N; idx++) {
            //파일 목록 내리기
            while (last[a]<idx && b<M) {
                a++;
                b++;
                sz-=cur[b];
                cur[b]=0;
            }
            // 공간이 하나 생기게 하기
            while (sz>=K) {
                if (cur[d2.front()]==0) {
                    d2.pop_front();
                    //cout << "three-1\n";
                }
                else if (cur[d2.front()]>=1){
                    cur[d2.front()]--;
                    d1.push_back(d2.front());
                    d2.pop_front();
                    sz--;
                }
            }

            if (a>f[idx] || f[idx]>b) {
                cur[f[idx]]++;
                sz++;
                d2.push_back(f[idx]);
                //cout << "two\n";
            }
        }

        a--; b--;
        while (b<M) {
            a++;
            b++;
            sz-=cur[b];
            cur[b]=0;
            while (sz<K && !d1.empty()) {
                int x=d1.back(); d1.pop_back();
                if (a<=x && x<=b) continue;
                else {
                    d2.push_front(x);
                    sz++;
                    cur[x]++;
                }
            }
        }

        if (d1.empty() && sz==0) cout << "YES\n";
        else cout << "NO\n";

        fill(&cur[0], &cur[M+1], 0);
    }
}

/*
1
5 5 1
1 2 3 4 5

1
5 5 1
1 2 3 5 4

1
5 5 1
1 2 4 5 3

1
5 5 2
1 2 4 5 3

1
3 10 2
1 3 2 1 3 2 1 3 2 1

1
3 10 1
1 3 2 1 3 2 1 3 2 1

*/
