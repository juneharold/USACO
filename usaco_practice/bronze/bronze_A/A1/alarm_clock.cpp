// 알람 시계
#include <iostream>
using namespace std;

int main()
{
    int H, M; cin >> H >> M;
    int min=(M+15)%60;
    if (M>=45) cout << H << " " << min;
    else if (M<45 and H==0) cout << 23 << " " << min;
    else cout << H-1 << " " << min;
}
