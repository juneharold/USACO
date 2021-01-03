// OX 퀴즈
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int N;
    cin >> N;
    for (int test_case=0; test_case<N; test_case++)
    {
        string pattern;
        cin >> pattern;
        int results=0, point=1;
        for (int i=0; i<pattern.size(); i++)
        {
            if (pattern[i]=='O')
            {
                results += point;
                point += 1;
            }
            else
            {
                point = 1;
            }
        }
        cout << results << endl;
    }
}
