#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

pair <int, int> field[2001][2001]={}; // first is time passed, second is mowed (0, 1)

int main()
{
    //freopen("mowing.in", "r", stdin);
    //freopen("mowing.out", "w", stdout);
    int N;
    cin >> N;
    //start at 1000, 1000
    int cur_x=1000, cur_y=1000;
    int time=0;
    int min_X=1000;
    for (int i=0; i<N; i++)
    {
        char dir;
        int steps;
        cin >> dir >> steps;
        for (int j=0; j<steps; j++)
        {
            if (field[cur_x][cur_y].second==1)
                {
                    int timediff=time-field[cur_x][cur_y].first;
                    if (timediff<min_X)
                    {
                        min_X = timediff;
                    }
                }
            if (dir=='N')
            {
                field[cur_x][cur_y].second = 1;
                field[cur_x][cur_y].first = time;
                cur_y += 1;
                time += 1;
            }
            else if (dir=='E')
            {
                field[cur_x][cur_y].second = 1;
                field[cur_x][cur_y].first = time;
                cur_x += 1;
                time += 1;
            }
            else if (dir=='S')
            {
                field[cur_x][cur_y].second = 1;
                field[cur_x][cur_y].first = time;
                cur_y -= 1;
                time += 1;
            }
            else if (dir=='W')
            {
                field[cur_x][cur_y].second = 1;
                field[cur_x][cur_y].first = time;
                cur_x -= 1;
                time += 1;
            }
        }
    }
    if (min_X==1000)
    {
        cout << "-1" << "\n";
    }
    else
    {
        cout << min_X << "\n";
    }
}
