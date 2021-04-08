#include <iostream>
using namespace std;

int arr[25]={};
int c, b;
int closest=0;
int calories[25]={};

void per(int cur)
{
    if (cur==b)
    {
        int sum=0;
        for (int i=0; i<b; i++)
        {
            if (arr[i]==2) sum+=calories[i];
            if (sum<=c and sum>closest) closest=sum;
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
    cin >> c >> b;
    for (int i=0; i<b; i++) cin >> calories[i];
    per(0);
    cout << closest;
    return 0;
}
