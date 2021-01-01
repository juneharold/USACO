#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

/* First method
int main()
{
    int A, B, C;
    cin >> A >> B >> C;
    int enter[3]={}, leave[3]={};
    for (int i=0; i<6; i++)
    {
        if (i%2==0)
        {
            cin >> enter[i/2];
        }
        else
        {
            cin >> leave[i/2];
        }
    }
    sort(enter, enter+3);
    sort(leave, leave+3);
    //calculating price
    int c_time=max(0, leave[0]-enter[2]);
    int b_time=max(0, leave[1]-enter[1]-c_time);
    int a_time=max(0, leave[2]-enter[0]-c_time-b_time);
    //
    int ans = 3*c_time*C + 2*b_time*B + 1*a_time*A;
    cout << ans << endl;
}
*/

/* Second try
int main()
{
    int A, B, C;
    cin >> A >> B >> C;
    int p1, q1, p2, q2, p3, q3; // p is enter, q is leave
    cin >> p1 >> q1 >> p2 >> q2 >> p3 >> q3;
    // making array
    int enter[3] = {p1, p2, p3};
    int leave[3] = {q1, q2, q3};
    sort(enter, enter+3);
    sort(leave, leave+3);
    int min_enter = enter[0];
    int max_enter = enter[2];
    int min_leave = leave[0];
    int max_leave = leave[2];
    // 3개가 주차된 시간 범위 
    int three_time = max(0, min_leave-max_enter); //has to be larger than 0
    // 2개가 주차된 시간 범위 
    int two_time_1 = max(0, min(q1, q2)-max(p1, p2));
    int two_time_2 = max(0, min(q2, q3)-max(p2, p3));
    int two_time_3 = max(0, min(q3, q1)-max(p3, p1));
    // 1개가 주차된 시간 범위 
    int one_time_1 = q1-p1;
    int one_time_2 = q2-p2;
    int one_time_3 = q3-p3;
    //total time
    int total_time = max_leave - min_enter;
    // calculating...
    int price=0;
    if (total_time>0)
    {
        price += 3*three_time*C;
        total_time -= three_time;
    }
    if (total_time>0)
    {
        price += 2*two_time_1*B;
        total_time -= two_time_1;
    }
    if (total_time>0)
    {
        price += 2*two_time_2*B;
        total_time -= two_time_2;
    }
    if (total_time>0)
    {
        price += 2*two_time_3*B;
        total_time -= two_time_3;
    }
    while (total_time>0)
    {
        price += 1*A;
        total_time -= 1;
    }
    cout << price << endl;
}
*/

int main()
{
    int A, B, C;
    cin >> A >> B >> C;
    int p1, q1;
    int p2, q2;
    int p3, q3; // p is enter, q is leave
    cin >> p1 >> q1 >> p2 >> q2 >> p3 >> q3;
    // make all three cases 
    
}

