/*
strictly ascending and descending.
*/
#include <iostream>
#include <algorithm>
using namespace std;

int a[200005]={};

int main()
{
    int N; cin >> N;
    for (int i=1; i<=N; i++) cin >> a[i];
    int cnt=0;
    for (int i=1; i<=N-1; i++) {
        if (a[i]<a[i+1]) {
            if (cnt) {
                cout << "NO";
                return 0;
            }
        }
        if (a[i]>a[i+1]) {
            cnt++;
        }
    }
    cout << "YES";
}
