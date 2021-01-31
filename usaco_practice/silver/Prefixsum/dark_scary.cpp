#include <iostream> 
using namespace std;

int picture[1005][1005]={};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int R, C, Q;
    cin >> R >> C >> Q;
    for (int i=1; i<=R; i++)
    {
        for (int j=1; j<=C; j++)
        {
            int a;
            cin >> a;
            picture[i][j]=picture[i][j-1] + picture[i-1][j] - picture[i-1][j-1] + a;
        }
    }
    for (int i=0; i<Q; i++)
    {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        int ans=(picture[r2][c2] - picture[r2][c1-1] - picture[r1-1][c2] + picture[r1-1][c1-1])/((r2-r1+1)*(c2-c1+1));
        cout << ans << "\n";
    }
}




