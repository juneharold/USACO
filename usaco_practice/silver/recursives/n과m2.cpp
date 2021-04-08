#include <iostream>
#include <algorithm>
using namespace std;

int arr[10]={};
int check[10]={};
int n, m;

void per(int cur)
{
    if (cur==m)
    {
        int checker=1;
        for (int i=0; i<m-1; i++)
        {
            if (arr[i]>arr[i+1]) checker=0;
        }
        if (checker==1) {
            for (int i=0; i<m; i++) cout << arr[i] << " ";
            cout << "\n";
        }
        return;
    }
    for (int i=1; i<=n; i++) {
        if (check[i]==0) {
            arr[cur]=i;
            check[i]=1;
            per(cur+1);
            check[i]=0;
            arr[cur]=0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    per(0);
}
