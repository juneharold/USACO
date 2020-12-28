// 단어 공부 
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
        if (a <= 90)
        {
            alphabet[a-65] += 1;
        }
        else
        {
            alphabet[a-97] += 1;
        }
    }
    // output
    int max = 0, max_index=-2; // ascii code 63==? --> -2+65
    for (int j=0; j<26; j++)
    {
        if (alphabet[j]>max)
        {
            max = alphabet[j];
            max_index = j;
        }
        else if (alphabet[j]==max)
        {
            max_index=-2;
        }
    }
    printf("%c", max_index+65);
}
