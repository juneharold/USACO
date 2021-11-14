#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
#define f first
#define s second

const int MAX=2e5+5;
int n, cnt, ans[MAX]={};
struct customer {
    int a, b, q;
};
customer ppl[MAX];
multiset<pair<int, int>> rooms;
bool cmp(customer A, customer B) {return A.a<B.a;}

int main()
{
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> ppl[i].a >> ppl[i].b;
        ppl[i].q=i;
    }
    sort(&ppl[0], &ppl[n], cmp);

    int room_cnt=0;
    for (int i=0; i<n; i++) {
        if (rooms.empty()) {
            room_cnt++;
            rooms.insert({ppl[i].b, room_cnt});
            ans[ppl[i].q]=room_cnt;
        }
        else {
            auto it=rooms.begin();
            if ((*it).f<ppl[i].a) {
                rooms.insert({ppl[i].b, (*it).s});
                ans[ppl[i].q]=(*it).s;
                rooms.erase(it);
            }
            else {
                room_cnt++;
                rooms.insert({ppl[i].b, room_cnt});
                ans[ppl[i].q]=room_cnt;
            }
        }

        cnt=max(cnt, (int)rooms.size());
    }

    cout << cnt << "\n";
    for (int i=0; i<n; i++) cout << ans[i] << " ";

}
