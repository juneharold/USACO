#include <iostream>
#include <set>
using namespace std;

int N, D, ans[1005];
set<int> s;

int main()
{
    cin >> N >> D;
    for (int i=1; i<=N; i++) {
        int a; cin >> a;
        int pos, st=*s.begin();

        if (s.empty()) {
            s.insert(a);
            pos=a;
        }
        else if (a<=st-D) {
            s.insert(a);
            pos=a;
        }
        else {
            for (auto it=s.begin(); it!=s.end(); it++) {
                auto bef=it, aft=it;
                int start, end;
                aft++;
                if (aft==s.end()) start=(*bef)+D, end=1e9;
                else start=(*bef)+D, end=(*aft)-D;

                if (start>=a && start<=end) {
                    pos=start;
                    break;
                }
                else if (start<=a && a<=end) {
                    pos=a;
                    break;
                }
            }
            s.insert(pos);
        }

        ans[i]=pos;
    }

    for (int i=1; i<=N; i++) cout << ans[i] << " ";
}
