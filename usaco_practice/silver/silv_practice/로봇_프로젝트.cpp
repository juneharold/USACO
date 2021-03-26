#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int blocks[1000000]={};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (unsigned int x; cin >> x;)
    {
        int length=x*(1e7);
        int n; cin >> n;
        for (int i=0; i<n; i++) cin >> blocks[i];
        sort(blocks, blocks+n);
        pair <int, int> ans (0, 0);
        for (int i=0; i<n-1; i++)
        {
            int block1=blocks[i];
            int find=length-block1;
            if (find<0) continue;
            int lb = lower_bound(&blocks[i], &blocks[n], find) - &blocks[0];
            int ub = upper_bound(&blocks[i], &blocks[n], find) - &blocks[0];
            if (lb>=n or lb==ub or ub-1==i) continue;
            int block2=blocks[ub-1];
            if (block1+block2==length)
            {
                if (block2>=block1)
                {
                    if (block2-block1>=ans.second-ans.first)
                    {
                        ans.second=block2;
                        ans.first=block1;
                    }
                }
                else
                {
                    if (block1-block2>=ans.second-ans.first)
                    {
                        ans.second=block1;
                        ans.first=block2;
                    }
                }
            }
        }
        if (ans.first==0 or ans.second==0) cout << "danger" << "\n";
        else cout << "yes " << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

/*
1
4
9999998
1
2
9999999
1
4
5000000
10999998
5000000
10999999
2


*/
