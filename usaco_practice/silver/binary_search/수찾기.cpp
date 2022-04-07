#include <iostream>
#include <algorithm>
using namespace std;

long long numbers[100005]={};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N; cin >> N;
    for (int i=0; i<N; i++) cin >> numbers[i];
    sort(numbers, numbers+N);
    int M; cin >> M;
    for (int i=0; i<M; i++)
    {
        int target;
        cin >> target;
        int lowbound=lower_bound(&numbers[0], &numbers[N], target)-&numbers[0];
        if (lowbound<N && numbers[lowbound]==target) cout << 1 << "\n";
        else cout << 0 << "\n";
    }
}
