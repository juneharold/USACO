#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    string cowphabet;
    cin >> cowphabet;
    string target;
    cin >> target;
    int len=target.size();
    int K=0;
    int let1=0, let2=0;
    for (int i=0; i<len-1; i++)
    {
        char letter1=target[i], letter2=target[i+1];
        for (int j=0; j<26; j++)
        {
            if (cowphabet[j]==letter1)
            {
                let1=j;
            }
            if (cowphabet[j]==letter2)
            {
                let2=j;
            }
        }
        if (let2<=let1)
        {
            K+=1;
        }
        else if(let2>=let1 and i==len-1)
        {
            K+=1;
        }
    }
    cout << K+1;
}


/*
abcdefghijklmnopqrstuvwxyz
mood
*/
