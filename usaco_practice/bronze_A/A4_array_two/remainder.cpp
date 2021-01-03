#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int remainder[10]={};
    for (int i=0; i<10; i++)
    {
        int num_in;
        cin >> num_in;
        remainder[i] = num_in%42;
    }
    // check for diff values
    int diff_values=1;
    sort(remainder, remainder+10);
    for (int j=0; j<9; j++)
    {
        if (remainder[j] != remainder[j+1])
        {
            diff_values += 1;
        }
    }
    cout << diff_values << endl;
}
