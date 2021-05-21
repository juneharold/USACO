#include <iostream>
#include <algorithm>
using namespace std;

int arr[100005]={};

int main()
{
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
    int n; cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n);
    int ans_max=max((arr[n-1]-arr[1])-(n-3), (arr[n-2]-arr[0])-(n-3))-1;
    // two pointer
    int ans_min=1e9;
    int right=0, left=0; //arr의 index를 의미.
    while (true) {
        // arr[right]-arr[left]+1 가 n보다 같거나 작고-dist, 그 두 점 사이에 몇개의소들이
        // 있는지-between
        // 그러면, n-(between+2) 를 ans_min과 비교.
        int dist=arr[right]-arr[left]+1;
        int between=right-left-1;
        if (dist<=n and right==n) break;
        else if (dist<=n) {
            right++;
            ans_min=min(n-(between+2), ans_min);
        }
        else {
            left++;
        }
    }
    //exception...
    if ((arr[n-2]-arr[0]==n-2 and arr[n-1]-arr[n-2]>2) or (arr[n-1]-arr[1]==n-2 and arr[1]-arr[0]>2)) {
        ans_min=2;
    }
    cout << ans_min << "\n" << ans_max;
    return 0;
}

/*
5
8
7
6
5
10

4
1
5
6
7

4
1
2
8
9

5
1
2
5
8
9

6
1
4
7
11
16
13
*/
