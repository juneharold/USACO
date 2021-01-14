#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);
    int N, B;
    cin >> N >> B;
    pair <int, int> prr[100]; // first is x, second is y
    for (int i=0; i<N; i++)
    {
        cin >> prr[i].first >> prr[i].second;
    }
    // sort prr
    sort(&prr[0], &prr[N]);
    // brute force?
    int min_M=100;
    if (B>100)
    {
        int indexA=-1;
        for (int a=1; a<=1000000; a=prr[indexA].first+1) // x=a
        {
            int indexB=-1;
            for (int b=1; b<=1000000; b=prr[indexB].second+1) //y=b
            {
                int left_up=0, left_down=0, right_up=0, right_down=0; // count how many in each box
                for (int j=0; j<N; j++)
                {
                    int x=prr[j].first, y=prr[j].second;
                    if (x<a and y<b)
                    {
                    left_down += 1;
                    }
                    else if (x>a and y<b)
                    {
                    right_down +=1;
                    }
                    else if (x<a and y>b)
                    {
                    left_up += 1;
                    }
                    else if (x>a and y>b)
                    {
                        right_up += 1;
                    }
                }
                // find M;
                int boxes[4] = {left_up, left_down, right_up, right_down};
                sort(boxes, boxes+4);
                int M=boxes[3];
                if (M<min_M)
                {
                    min_M = M;
                }
                indexB += 1;
            }
            indexA += 1;
        }
    }
    else
    {
        for (int a=1; a<50; a++) // x=a
        {
            for (int b=1; b<50; b++) //y=b
            {
                int left_up=0, left_down=0, right_up=0, right_down=0; // count how many in each box
                for (int j=0; j<N; j++)
                {
                    int x=prr[j].first, y=prr[j].second;
                    if (x<a*2 and y<b*2)
                    {
                        left_down += 1;
                    }
                    else if (x>a*2 and y<b*2)
                    {
                        right_down +=1;
                    }
                    else if (x<a*2 and y>b*2)
                    {
                        left_up += 1;
                    }
                    else if (x>a*2 and y>b*2)
                    {
                        right_up += 1;
                    }
                }
                // find M;
                int boxes[4] = {left_up, left_down, right_up, right_down};
                sort(boxes, boxes+4);
                int M=boxes[3];
                if (M<min_M)
                {
                    min_M = M;
                }
            }
        }
    }
    cout << min_M << "\n";
    return 0;
}
