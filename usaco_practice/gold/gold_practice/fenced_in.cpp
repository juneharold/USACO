#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX_N=2005;
int A, B, N, M, p[MAX_N*MAX_N]={};
vector<int> ver, hor;
vector<pair<int, int>> vdiff, hdiff;

int Find(int x) {
    if (p[x]==x) return x;
    else return p[x]=Find(p[x]);
}
void Union (int a, int b) {
    a=Find(a);
    b=Find(b);
    if (a==b) return;
    p[b]=a;
}


int main()
{
    cin >> A >> B >> N >> M;
    for (int i=0; i<N; i++) {
        int a; cin >> a;
        ver.push_back(a);
    }
    for (int i=0; i<M; i++) {
        int b; cin >> b;
        hor.push_back(b);
    }
    ver.push_back(0); ver.push_back(A);
    hor.push_back(0); hor.push_back(B);

    sort(ver.begin(), ver.end());
    sort(hor.begin(), hor.end());

    for (int i=0; i<ver.size()-1; i++) vdiff.push_back({ver[i+1]-ver[i], i+1});
    for (int i=0; i<hor.size()-1; i++) hdiff.push_back({hor[i+1]-hor[i], i+1});

    sort(vdiff.begin(), vdiff.end());
    sort(hdiff.begin(), hdiff.end());

    for (int i=1; i<=(M+1)*(N+1); i++) p[i]=i;

    for (int i=0; i<vdiff.size(); i++) {
        for (int j=0; j<hdiff.size(); j++) {

        }
    }

}
