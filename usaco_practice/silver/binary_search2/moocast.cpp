#include <iostream>
using namespace std;

pair <int, int> coordinates[1005];

int main()
{
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N; cin >> N;
    for (int i=0; i<N; i++) cin >> coordinates[i].first >> coordinates[i].second;
    long long max_dist=0;
    for (int i=0; i<N; i++)
    {
        int x=coordinates[i].first, y=coordinates[i].second;
        long long min_dist=1e9;
        for (int j=0; j<N; j++)
        {
            if (i!=j)
            {
                long long dist=(abs(x-coordinates[j].first))*(abs(x-coordinates[j].first)) + (abs(y-coordinates[j].second))*(abs(y-coordinates[j].second));
                if (dist<min_dist) min_dist=dist;
            }
        }
        if (min_dist>max_dist) max_dist=min_dist;
    }
    cout << max_dist;
}
