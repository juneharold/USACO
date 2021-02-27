#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> graph[100005];
int numcows[100005]={};

int main()
{
    int N; cin >> N;
    for (int i=0; i<N-1; i++)
    {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

}