#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    pair <int, int> coor[100000]={};
    for (int i=0; i<N; i++)
    {
        cin >> coor[i].first >> coor[i].second;
    }
    // find distances and compare
    int max_diff=0, index=-1; //index is the one we skip
    for (int j=0; j<=N-3; j++)
    {
        int x1 = coor[j].first, y1 = coor[j].second;
        int x2 = coor[j+1].first, y2 = coor[j+1].second; //this is the one we skip
        int x3 = coor[j+2].first, y3 = coor[j+2].second;
        // distances
        int wo_skip=abs(x2-x1)+abs(y2-y1)+abs(x3-x2)+abs(y3-y2);
        int w_skip=abs(x3-x1)+abs(y3-y1);
        // the difference
        int diff = wo_skip-w_skip;
        if (diff>max_diff)
        {
            max_diff = diff;
            index = j+1;
        }
    }
    // skipping index
    int total_dis=0;
    for (int k=0; k<N-1; k++)
    {
        int cur_x=coor[k].first, cur_y=coor[k].second, next_x=coor[k+1].first, next_y=coor[k+1].second;
        int nowdis=abs(next_x-cur_x)+abs(next_y-cur_y);
        total_dis += nowdis;
    }
    cout << total_dis - max_diff << "\n";
}

