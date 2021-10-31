#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

const int MAX=1e5+5;
int N, seq[MAX], seq2[MAX], cows[MAX], fw[MAX]={}, L[MAX]={}, R[MAX]={};
map<int, int> compress;

int query (int p) {
    int ret=0;
    while (p!=0) {
        ret+=fw[p];
        p-=(p&-p);
    }
    return ret;
}

void update(int p, int v) {
    while (p<=N) {
        fw[p]+=v;
        p+=(p&-p);
    }
}

int main()
{
    cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> seq[i];
        seq2[i]=seq[i];
    }

    // 크기 압축
    sort(&seq2[1], &seq2[N+1]);
    for (int i=1; i<=N; i++) {
        compress[seq2[i]]=i;
    }
    for (int i=1; i<=N; i++) {
        cows[i]=compress[seq[i]];
    }

    //펜윅트리 이용
    for (int i=1; i<=N; i++) {
        L[i]=query(N)-query(cows[i]);
        update(cows[i], 1);
    }
    fill(&fw[0], &fw[MAX], 0);

    for (int i=N; i>=1; i--) {
        R[i]=query(N)-query(cows[i]);
        update(cows[i], 1);
    }

    int ans=0;
    for (int i=1; i<=N; i++) {
        int larger=max(R[i], L[i]), smaller=min(R[i], L[i]);
        if (larger>2*smaller) ans++;
    }

    cout << ans;
}
