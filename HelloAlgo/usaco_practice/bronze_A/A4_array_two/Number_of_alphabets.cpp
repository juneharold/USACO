// 알파벳 개수 
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
    for (int i=0; i<input.size(); i++)
    {
        int a = input[i];
        alphabet[a-97] += 1;
    }
    // output
    for (int j=0; j<26; j++)
    {
        printf("%d ", alphabet[j]);
    }
}
