#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;
const int sqrmax=650;

int A[400005]={}, N, Q, K;
priority_queue<int> pq1[sqrmax], pq2[sqrmax];

void empty_pq1(int idx) {
    while (!pq1[idx].empty()) {
        pq1[idx].pop();
    }
}

int query(int S, int T, int P) {
    if (T<S) {
        int res=query(S, N-1, P);
        return query(0, T, res);
    }
    // start
    for (int i=(S/K)*K; i/K==S/K; i++) {
        pq2[i/K].push(-A[i]);
        A[i]=-pq2[i/K].top();
        pq2[i/K].pop();
    }
    int cur=P;
    for (int i=S; i<=min(T, (S/K)*K+K-1); i++) {
        if (A[i]>cur) swap(cur, A[i]);
    }
    empty_pq1(S/K);
    for (int i=(S/K)*K; i/K==S/K; i++) pq1[S/K].push(A[i]);
    // middle
    for (int idx=S/K+1; idx<T/K; idx++) {
        pq2[idx].push(-cur);
        pq1[idx].push(cur);
        cur=pq1[idx].top();
        pq1[idx].pop();
    }
    // end
    if (S/K!=T/K) {
        for (int i=(T/K)*K; i/K==T/K; i++) {
            pq2[i/K].push(-A[i]);
            A[i]=-pq2[i/K].top();
            pq2[i/K].pop();
        }
        for (int i=max((T/K)*K, (S/K)*K+K); i<=T; i++) {
            if (A[i]>cur) swap(cur, A[i]);
        }
        empty_pq1(T/K);
        for (int i=(T/K)*K; i/K==T/K; i++) pq1[T/K].push(A[i]);
    }
    return cur;
}

void init() {
    for (int i=0; i<N; i++) {
        pq1[i/K].push(A[i]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> Q;
    for (int i=0; i<N; i++) cin >> A[i];
    K=sqrt(N);
    init();
    int S, T, P; 
    while (Q--) {
        cin >> S >> T >> P;
        S--, T--;
        cout << query(S, T, P) << "\n";
    } 
}