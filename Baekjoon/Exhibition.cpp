/*
sort by value 
 - pick smallest frame possible
 - or give up picture 

- pick smallest frame --> give up x frames before
- give up picutre --> give up 1 picutre

can move a set of pictures to the right (because frame size increase from left to right)
in the end, pick the ones that give up least number of frames ???

sort by size and match frames 
dp[i] = maximum number of pictures exhibited with largest value i 

!!!!!!!!!!!!
start from largest frame and largest value
if the picture can go inside the frame then put it 
!!!!!!!!!!!!
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define fs first
#define sc second

pair<int, int> pic[100005];
int frames[100005]={};

int main()
{
    int N, M; cin >> N >> M;
    for (int i=1; i<=N; i++) cin >> pic[i].sc >> pic[i].fs;
    for (int i=1; i<=M; i++) cin >> frames[i];
    sort(&pic[1], &pic[N+1]);
    sort(&frames[1], &frames[M+1]);

    int ans=0, idx=M;
    for (int i=N; i>=1; i--) {
        if (idx==0) break;
        if (pic[i].sc<=frames[idx]) {
            ans++;
            idx--;
        }
    }
    cout << ans;
}