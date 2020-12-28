// JOI와 IOI
# include <iostream>
# include <string>
using namespace std;

int main()
{
    string input;
    cin >> input;
    int joi=0, ioi=0;
    for (int i; i<input.size(); i++)
    {
        if (input[i]=='J' && input[i+1]=='O' && input[i+2]=='I')
        {
            joi += 1;
        }
        else if (input[i]=='I' && input[i+1]=='O' && input[i+2]=='I')
        {
            ioi += 1;
        }
    }
    cout << joi << endl;
    cout << ioi << endl;
}
