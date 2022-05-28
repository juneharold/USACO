#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int cnt=0;
    for (int a=0; a<2; a++) {
        for (int b=0; b<2; b++) {
            for (int c=0; c<2; c++) {
                for (int d=0; d<2; d++) {
                    int e=(b&c);
                    int f=(a|e);
                    int res=(f^(1-d));
                    if (res==1) cnt++;
                }
            }
        }
    }
    cout << cnt;
}
