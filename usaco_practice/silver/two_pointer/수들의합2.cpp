#include <iostream>
using namespace std;

int main()
{
    int n, m; cin >> n >> m;
    int arr[100005]={};
    for (int i=0; i<n; i++) cin >> arr[i];
    int left=0, right=0;
    int sum=0, tally=0;
    while (true) {
        if (sum<=m and right==n) {
            break;
        }
        else if (sum<=m) {
            right++;
            sum+=arr[right-1];
        }
        else {
            left++;
            sum-=arr[left-1];
        }
        if (sum==m) tally++;
    }
    cout << tally;
}
