// Block Game
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int alphabet[26]={}; //index 0==a, 1==b, -97
    for (int i=0; i<N; i++)
    {
        string front, back;
        cin >> front >> back;
        int f_alph[26]={}, b_alph[26]={};
        for (int f=0; f<front.size(); f++)
        {
            int A = front[f];
            f_alph[A-97] += 1;
        }
        for (int b=0; b<back.size(); b++)
        {
            int B = back[b];
            b_alph[B-97] += 1;
        }
        // going over the alphabets..
        for (int alph=0; alph<26; alph++)
        {
            if (b_alph[alph]>=f_alph[alph])
            {
                alphabet[alph] += b_alph[alph];
            }
            else
            {
                alphabet[alph] += f_alph[alph];
            }
        }
    }
    // going over alphabet
    for (int k=0; k<26; k++)
    {
        cout << alphabet[k] << endl;
    }
}
