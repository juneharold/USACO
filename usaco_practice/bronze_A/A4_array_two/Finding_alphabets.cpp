// 알파벳 찾기 
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int alphabet[26]={};
    string input;
    cin >> input;
    // filling out alphabet array
    for (int i=1; i<=input.size(); i++)
    {
        int a = input[i-1];
        if (alphabet[a-97]==0)
        {
            alphabet[a-97] = i;
        }
    }
    // output
    for (int j=0; j<26; j++)
    {
        if (alphabet[j]==0)
        {
            printf("%d ", -1);
        }
        else
        {
            printf("%d ", alphabet[j]-1);
        }
    }
}
