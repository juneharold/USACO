#include <iostream>
using namespace std;

int arr[8]={};
int k=0;

void permutation(int cur, int n)
{
    if (cur==n)
    {
        for (int i=0; i<n; i++) cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    for (int i=1; i<=n; i++)
    {
        int check=1;
        for (int j=0; j<cur; j++) if (arr[j]==i) check=0;
        if (check==0) continue;
        arr[cur]=i;
        permutation(cur+1, n);
    }
}

int main()
{
    int n; cin >> n;
    permutation(0, n);
}
