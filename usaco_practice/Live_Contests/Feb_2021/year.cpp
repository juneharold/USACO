#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX_N=100000;
int N, K;
int ancestor[MAX_N]={};

bool large_first (int a, int b) {
    return a>b;
}

int main()
{
    cin >> N >> K;
    for (int i=0; i<N; i++) cin >> ancestor[i];
    sort(ancestor, ancestor+N);
    int end=0;
    while (end<ancestor[N-1]) {
        end+=12;
    }

    vector <int> intervals;
    intervals.push_back((ancestor[0]/12)*12);

    int prev=ancestor[0];
    for (int i=1; i<N; i++) {
        if (prev/12==ancestor[i]/12) {
            intervals.push_back(0);
        }
        else {
            int a=ancestor[i]/12;
            int b=(prev+12)/12;
            int c=a*12;
            int d=b*12;
            //cout << a << " " << b << " " << c << " " << d << "\n";
            intervals.push_back(abs(c-d));
        }
        prev=ancestor[i];
    }
    sort(intervals.begin(), intervals.end(), large_first);

    K--;
    for (auto x: intervals) {
        if (K==0) break;
        else{
            end-=x;
            K--;
        }
    }
    cout << end;
    return 0;
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
