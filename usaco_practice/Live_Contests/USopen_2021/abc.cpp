#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    for (int t=0; t<T; t++)
    {
        int N; cin >> N;
        int num[10]={};
        for (int i=0; i<N; i++) cin >> num[i];
        sort(num, num+N);
        int counter=0;
        for (int x=0; x<4; x++) { // x is either a, b, c, or a+b
            for (int y=x; y<x+4; y++) { // y is either b, c, a+b, b+c, or c+a
                for (int z=y; z<7; z++) { // z is either c, a+b, b+c, c+a, or a+b+c
                    int checker=0;
                    int X=num[x], Y=num[y], Z=num[z];
                    for (int i=0; i<N; i++) {
                        if (num[i]==X or num[i]==Y or num[i]==Z) checker++;
                        else if (num[i]==X+Y or num[i]==Y+Z or num[i]==Z+X) checker++;
                        else if (num[i]==X+Y+Z) checker++;
                    }
                    if (checker==N) counter++;
                }
            }
        }
        cout << counter << "\n";
    }
}
