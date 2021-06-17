#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int arr[55][55]={};

int main()
{
    int n, m; cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            char a; cin >> a;
            if (a=='X') arr[i][j]=1;
            else arr[i][j]=0;
        }
    }
    
}
