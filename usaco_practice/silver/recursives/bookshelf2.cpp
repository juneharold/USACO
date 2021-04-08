#include <iostream>
using namespace std;

int arr[25]={};
int n, b;
int closest=1e9;
int heights[25]={};

void per(int cur)
{
    if (cur==n)
    {
        int sum=0;
        for (int i=0; i<n; i++)
        {
            if (arr[i]==2) sum+=heights[i];
            if (sum>=b and sum<closest) closest=sum;
        }
        return;
    }
    for (int i=1; i<=2; i++) {
        arr[cur]=i;
        per(cur+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> b;
    for (int i=0; i<n; i++) cin >> heights[i];
    per(0);
    cout << closest-b;
}
