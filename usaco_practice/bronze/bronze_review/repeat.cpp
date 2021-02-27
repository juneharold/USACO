#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input;
    cin >> input;
    int len=input.size();
    int K=0;
    for (int i=0; i<len-1; i++)
    {
        int letter=input[i], letter2=input[i+1];
        if (letter2<=letter)
        {
            K+=1;
        }
        else if(letter2>=letter and i==len-1)
        {
            K+=1;
        }
    }
    cout << K+1;
}
