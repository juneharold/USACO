// KMP는 왜 KMP일까?
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string long_form;
    cin >> long_form;
    for (int i=0; i<long_form.size(); i++)
    {
        if (i==0)
        {
            cout << long_form[0];
        }
        if (long_form[i]=='-')
        {
            cout << long_form[i+1];
        }
    }
}
