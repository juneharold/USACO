// 유학 금지
# include <cstdio>
# include <iostream>
# include <string>
using namespace std;

int main()
{
    string word;
    cin >> word;
    int size = word.size();
    for (int t=0; t<size; t++)
    {
        for (int i=0; i<word.size(); i++)
        {
            for (int k=0; k<9; k++)
            {
                if (word[i] == "CAMBRIDGE"[k])
                {
                    word.erase(i, 1);
                }
            }
        }
    }
    cout << word;
}
