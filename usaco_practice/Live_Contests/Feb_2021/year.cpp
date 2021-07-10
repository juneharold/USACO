#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int ancestor[100005]={};

int main()
{
    int N, K; cin >> N >> K;
    for (int i=0; i<N; i++) cin >> ancestor[i];
    sort(ancestor, ancestor+N);
    int point=0;
    while (point<ancestor[N-1]) {
        point+=12;
    }
    int end=point;
    int range[100000]={};
    for (int i=0; i<N; i++) {
        range[ancestor[i]/12]+=1;
    }
    int subtract[100000]={};
    int index=0;
    int subt=0;
    for (int i=0; i<(end/12+1); i++) {
        if (range[i]==0) {
            subt+=12;
        }
        else {
            subtract[index]=subt;
            index++;
            subt=0;
        }
    }
    sort(subtract, subtract+index);
    int min;
    if (index<=K) min=0;
    else min=index-K-1;
    for (int i=index-1; i>=min; i--) {
        end-=subtract[i];
    }
    cout << end;
}


/*
5 3
101
85
100
46
95

5 3
101
85
46
6
11
*/
