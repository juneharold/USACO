/*
m-step process를 한 번 실행 했을때 각 칸이 어디로 가는지 알아낼 것.
그럼 functional graph를 만들 수 있다.
한 싸이클이 완성되는데 몇번 필요? --> 모든 싸이클의 최소공배수...
그렇게 되면 k%최소공배수 실행.
*/
#include <iostream>
#include <algorithm>
using namespace std;

int n, m, k;
pair <int, int> seq[105]={};
int arr[100005]={};

int main()
{
    cin >> n >> m >> k;
    for (int i=1; i<=n; i++) arr[i]=i;
    for (int i=0; i<m; m++) {
        int a, b; cin >> a >> b;
        seq[i].first=a;
        seq[i].second=b;
    }
    cout << seq[0].first;
    for (int i=0; i<m; m++) {
        int from=seq[i].first, to=seq[i].second;
        reverse(&arr[from], &arr[to+1]);
    }
    for (int i=1; i<=n; i++) cout << arr[i];
}
