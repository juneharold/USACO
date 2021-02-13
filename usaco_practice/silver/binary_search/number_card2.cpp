#include <iostream>
#include <algorithm>
using namespace std;

long long have[1000000]={};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N; 
    cin >> N;
    for (int i=0; i<N; i++) cin >> have[i];
    sort(have, have+N);
    int M;
    cin >> M;
    for (int i=0; i<M; i++)
    {
        int target;
        cin >> target;
        int low=lower_bound(&have[0], &have[N], target)-&have[0];
        int high=upper_bound(&have[0], &have[N], target)-&have[0];
        cout << high-low << " ";
    }
}
