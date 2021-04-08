#include <iostream>
#include <algorithm>
using namespace std;

int arr[105][105]={};
int visit[105][105]={};

int mxx=1, mnn=201;

int dx[4]={0, 1, 0, -1};
int dy[4]={1, 0, -1, 0};

void dfs(int X, int Y, int MID)
{
    visit[Y][X]=1;
    if (MID==2) {
        cout << X << " " << Y << "\n";
    }
    if (arr[Y][X]>mxx) mxx=arr[Y][X];
    if (arr[Y][X]<mnn) mnn=arr[Y][X];
    for (int i=0; i<4; i++) {
        int nextX=X+dx[i], nextY=Y+dy[i];
        if (nextX<0 or nextY<0) continue;

        if (arr[nextY][nextX]>=mxx and arr[nextY][nextX]-mnn>MID) continue;
        else if (arr[nextY][nextX]<=mnn and mxx-arr[nextY][nextX]>MID) continue;

        if (visit[nextY][nextX]==0 and arr[nextY][nextX]!=0) dfs(nextX, nextY, MID);
    }
}

int main()
{
    int n; cin >> n;
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) {
        int a; cin >> a;
        arr[i][j]=a+1;
    }
    int low=0, high=200;
    while(low<high)
    {
        int mid=(low+high)/2;
        dfs(0, 0, mid);
        cout << mid << " " << visit[n-1][n-1] << "\n";
        if (visit[n-1][n-1]==1) high=mid;
        else low=mid+1;
        fill(&visit[0][0], &visit[105][105], 0);
        mxx=1; mnn=201;
    }
    cout << low;
}

/*
3
0 0 2
0 2 0
2 0 0
*/
/*
1) 최대 혹은 최소인지 확인,
2) 최대 최소 차가 mid이하면 이동 (dfs사용)
3) 만약 끝까지 갈 수 있으면 high=mid
4) 끝까지 갈 수 없으면 low=mid+1
*/
