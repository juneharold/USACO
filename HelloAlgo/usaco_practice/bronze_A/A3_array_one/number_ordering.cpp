// 수 정렬하기 
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int a[N];
    for (int i=0; i<N; i++){
        scanf("%d", &a[i]);
    }
    sort(a, a+N);
    for (int i=0; i<N; i++){
        printf("%d\n", a[i]);
    }
}
