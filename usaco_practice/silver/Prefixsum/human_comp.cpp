#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int pfs[27][200005]={};
int abc[27]={};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string S;
    cin >> S;
    int length=S.size();
    for (int i=1; i<=length; i++)
    {
        char letter = S[i-1];
        int LET=letter-'a';
        abc[LET]+=1;
        for (int j=0; j<26; j++)
        {
            pfs[j][i]=abc[j];
        }
    }
    int q;
    cin >> q;
    for (int i=0; i<q; i++)
    {
        char find;
        cin >> find;
        int l, r;
        cin >> l >> r;
        int IND=find-'a';
        cout << pfs[IND][r+1]-pfs[IND][l] << "\n";
    }
}

/*
seungjaehwang
4
a 0 5
a 0 6
a 6 10
a 7 10
*/

