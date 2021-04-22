/*
m-step process를 한 번 실행 했을때 각 칸이 어디로 가는지 알아낼 것.
그럼 functional graph를 만들 수 있다.
한 싸이클이 완성되는데 몇번 필요? --> 모든 싸이클의 최소공배수...
그렇게 되면 k%최소공배수 실행.
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, k;
pair <int, int> seq[105]={};
int arr[100005]={};
int graph[100005]={};

int visit[100005]={};
int cnt_node=0;
vector <int> nodes;

void cycle(int cur)
{
    visit[cur]=1;
    cnt_node++;
    int next=graph[cur];
    if (visit[next]==0) cycle(next);
}

// Recursive function to return gcd of a and b
int gcd(int a,  int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

// Function to return LCM of two numbers
int lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}

int main()
{
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    for (int i=1; i<=n; i++) arr[i]=i;
    for (int i=0; i<m; i++) {
        int a, b; cin >> a >> b;
        seq[i].first=a;
        seq[i].second=b;
    }
    for (int i=0; i<m; i++) {
        int from=seq[i].first, to=seq[i].second;
        reverse(&arr[from], &arr[to+1]);
    }
    // create functional graph
    for (int i=1; i<=n; i++) {
        graph[arr[i]]=i;
    }
    //cycle에 있는 node의 갯수, 모든 node는 싸이클에 포함되어 있음
    for (int i=1; i<=n; i++) {
        if (visit[i]==0) cycle(i);
        nodes.push_back(cnt_node);
        cnt_node=0;
    }
    // 최소공배수 구하기
    int LCM=1;
    for (int i=0; i<nodes.size(); i++) {
        if (nodes[i]==0) continue;
        LCM=lcm(nodes[i], LCM);
    }
    for (int i=1; i<=n; i++) arr[i]=i;
    if (LCM>=k) {
        for (int i=0; i<k%LCM; i++) {
            for (int j=0; j<m; j++) {
                int from=seq[j].first, to=seq[j].second;
                reverse(&arr[from], &arr[to+1]);
            }
        }
    }
    else
    {
        for (int i=0; i<k; i++) {
            for (int j=0; j<m; j++) {
                int from=seq[j].first, to=seq[j].second;
                reverse(&arr[from], &arr[to+1]);
            }
        }
    }
    for (int i=1; i<=n; i++) cout << arr[i] << "\n";
    return 0;
}
