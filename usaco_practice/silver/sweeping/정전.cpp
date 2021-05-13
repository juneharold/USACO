#include <iostream>
#include <algorithm>
using namespace std;

int light[200000]={};

int main()
{
    int n, l; cin >> n >> l;
    for (int i=0; i<n; i++) {
        cin >> light[i];
    }
    sort(light, light+n);
    int ans=0, end=light[0]+l;
    int until=-1e9;
    for (int i=1; i<n; i++) {
        if (light[i]-l<until) {
            ans+=end-until;
            until=end;
        }
        else if (light[i]-l<end) {
            ans+=end-(light[i]-l);
            until=end;
        }
        end=light[i]+l;
    }
    cout << ans;
}

/*
6 3
-6 -2 1 3 8 15

2 3
-1 0
*/
