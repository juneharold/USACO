#include <iostream>
#include <algorithm>
using namespace std;

int hays[1000005]={};
int modified[1000005]={};

int main()
{
    int N, K;
    cin >> N >> K;
    for (int i=0; i<K; i++) {
        int start, end;
        cin >> start >> end;
        hays[start]+=1;
        hays[end+1]-=1;
    }
    int sum=0;
    for (int i=1; i<=N; i++)
    {
        sum+=hays[i];
        modified[i]=sum;
    }
    sort (modified+1, modified+N+1);
    cout << modified[N/2+1];
}
