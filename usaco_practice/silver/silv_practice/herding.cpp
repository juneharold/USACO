#include <iostream>
#include <algorithm>
using namespace std;

int arr[100005]={};

int main()
{
    int n; cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n);
    int ans_max=max((arr[n-1]-arr[1])-(n-3), (arr[n-2]-arr[0])-(n-3))-1;
    cout << ans_max;
    // two pointer
    
}

/*
4
7
4
9
3
*/
