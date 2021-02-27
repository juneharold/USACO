// 색종이 (2)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int spaces[101][101] = {}; // use 2d array to imitate the coordinate plane. 
    for (int i=1; i<=N; i++)
    {
        int x, y, width, height;
        cin >> x >> y >> width >> height;
        for (int h=0; h<height; h++)
        {
            for (int w=0; w<width; w++)
            spaces[(y+h)][x+w] = i;
        }
    }
    /* printing out the 2d array
    for (int a=0; a<101; a++)
        {
            for (int b=0; b<101; b++)
            {
                if (b==100)
                {
                    cout << spaces[a][b] << endl;
                }
                else
                {
                    cout << spaces[a][b];
                }
            }
        }
    */
    for (int j=1; j<=N; j++)
    {
        int counter = 0;
        for (int a=0; a<101; a++)
        {
            for (int b=0; b<101; b++)
            {
                if (spaces[a][b]==j)
                {
                    counter += 1;
                }
            }
        }
        cout << counter << endl;
    }
}
