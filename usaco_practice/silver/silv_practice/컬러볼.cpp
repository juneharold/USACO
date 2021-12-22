#include <iostream>
#include <algorithm>
using namespace std;
#define f first
#define s second

const int MAX=2e5+5;
int N, ans[MAX], color[MAX], sz[2005];
pair<pair<int, int>, int> ball[MAX]; //sz, color, input position

int main()
{
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> ball[i].f.s >> ball[i].f.f;
        ball[i].s=i;
    }

    sort(ball, ball+N);

    int sum=0, j=0;
    for (int i=0; i<N; i++) {

        while (ball[j].f.f<ball[i].f.f) {
            sum+=ball[j].f.f;
            color[ball[j].f.s]+=ball[j].f.f;
            j++;
        }

        ans[ball[i].s]=sum-color[ball[i].f.s];
    }

    for (int i=0; i<N; i++) cout << ans[i] << "\n";
}

/*
6
1 10
3 15
1 3
4 8
2 10
4 10
*/
