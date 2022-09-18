#include <iostream>
using namespace std;

int a[205]={};

int main()
{
    int N, M; cin >> N >> M;
    fill(a, a+201, -1);
    for (int i=0; i<M; i++) {
        int t, cur, type; cin >> t >> cur >> type;
        if (type) { //종료
            if (a[cur]==-1) {cout << "NO"; exit(0);}
            if (t-a[cur]<60) {cout << "NO"; exit(0);}
            a[cur]=-1;
        }
        else { //시작
            if (a[cur]!=-1) {cout << "NO"; exit(0);}
            a[cur]=t;
        }
    }
    for (int i=1; i<=N; i++) if (a[i]!=-1) {cout << "NO"; exit(0);}
    cout << "YES";
}
