#include <iostream>
#include <algorithm>
using namespace std;

int k;
int weights[15]={};
int ans[13*200000]={};
int arr[15]={};

void make_weight(int cur)
{
    if (cur==k)
    {
        int product=0;
        for (int i=0; i<k; i++)
        {
            if (arr[i]==2) product-=weights[i];
            if (arr[i]==3) product+=weights[i];
        }
        if (product>0) ans[product]=1;
        return;
    }
    for (int i=1; i<=3; i++) { //1이면 안 넣기, 2면 왼쪽에 그릇과 함께, 3이면 오른쪽
        arr[cur]=i;
        make_weight(cur+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> k;
    int S=0;
    for (int i=0; i<k; i++)
    {
        cin >> weights[i];
        S+=weights[i];
    }
    make_weight(0);
    int counter=0;
    for (int i=1; i<=S; i++)
    {
        if (ans[i]==0) counter++;
    }
    cout << counter;
}
