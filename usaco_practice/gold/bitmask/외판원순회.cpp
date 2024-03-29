#include <iostream>
#include <algorithm>
using namespace std;
// 비트마스킹 + DP
const int IMPOSSIBLE = 1987654321;
int N, W[16][16];
// dp[k][state] : k번째 마을, state: 방문했던 도시들을 2진법으로 표시.
int dp[17][1<<16];

int TSP(int current, int visited){
	int &ret = dp[current][visited];
	if(ret != -1)
		return ret;
	// 모든 마을 방문했는가
	if(visited == (1<<N)-1){
		// current -> 0 이동 가능한지
		if(W[current][0] != 0)
			return W[current][0];
		// 가능하지 않으면
		return IMPOSSIBLE;
	}
	ret = IMPOSSIBLE;
	for (int i = 0; i < N; ++i){
		// 방문했거나 || current -> i 로 길이 없거나
		if(visited & (1<<i) || W[current][i] == 0)
			continue;
		ret = min(ret, TSP(i, visited|(1<<i)) + W[current][i]);
	}
	return ret;
}

int main ()
{
	ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; ++i){
    	for (int j = 0; j < N; ++j) cin >> W[i][j];
    }
    fill(&dp[0][0], &dp[16][1<<16], -1);
    cout << TSP(0,1) << '\n';

    return 0;
}
