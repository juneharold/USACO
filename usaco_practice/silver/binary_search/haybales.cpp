#include <iostream>
#include <algorithm>
using namespace std;

int haybales[100005]={};

int main()
{
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, Q;
    cin >> N >> Q;
    for (int i=0; i<N; i++) cin >> haybales[i];
    sort(haybales, haybales+N);
    for (int i=0; i<Q; i++)
    {
        int start, end; 
        cin >> start >> end;
        int low = lower_bound(&haybales[0], &haybales[N], start)-&haybales[0];
        int high = upper_bound(&haybales[0], &haybales[N], end)-&haybales[0];
        cout << high-low << "\n";
    }
}

