#include <iostream>
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    int per[n];
    for (int p=0; p<n; p++)
    {
        int q;
        cin >> q;
        per[p] = q;
        //printf("%d", q);
    }
    int apt[m];
    for (int i=0; i<m; i++)
    {
        int t;
        cin >> t;
        apt[i] = t;
    }
    sort(per, per+n);
    sort(apt, apt+m);
    int ans=0;
    // going through per
    int pindex = 0;
    int aindex = 0;
    while (pindex<=n)
    {
        // going through apt
        for (int v=0; v<m; v++)
        {
            if (per[pindex]-k<=apt[v] && per[pindex]+k>=apt[v])
            {
                ans += 1;
                break;
            }
        }
    }
    cout << ans << endl;
}