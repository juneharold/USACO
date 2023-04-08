#include <iostream>
using namespace std;

int arr[100000]={};

int main()
{
    int N; cin >> N;
    for (int i=2; i<=N; i++) arr[i]=i;

    for (int i=2; i<=N; i++) {
        if (arr[i]!=0) {
            int from=i*i;
            for (int j=from; j<=N; j+=i) arr[j]=0;
        }
    }

    for (int i=2; i<=N; i++) if(arr[i]!=0) cout << i << "\n";
}
