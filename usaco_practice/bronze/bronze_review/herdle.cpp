#include <iostream>
using namespace std;

int main()
{
    char ans[9], guess[9];
    for (int i=0; i<9; i++) cin >> ans[i];
    for (int i=0; i<9; i++) cin >> guess[i];

    int green=0, cnt[26][2]={};
    for (int i=0; i<9; i++) {
        if (ans[i]==guess[i]) green++;
    }

    for (int i=0; i<9; i++) {
        if (ans[i]!=guess[i]) cnt[ans[i]-'A'][0]++; //count letters in X excluding green ones
        /*
        letter X in guess. if X is not green, and there is an X which does not correspond to a green in ans,
        this is yellow +1
        make sure that the number of yellows by X does not exceed number of X in ans that is not green.
        */
        for (int j=0; j<9; j++) {
            if (guess[i]!=ans[i] && guess[i]==ans[j] && ans[j]!=guess[j]) {
                cnt[guess[i]-'A'][1]++;
                break;
            }
        }
    }

    int yellow=0;
    for (int i=0; i<26; i++) {
        yellow+=min(cnt[i][1], cnt[i][0]);
    }

    cout << green << "\n" << yellow;
}

/*
AAA
CBA
AAA
AAA
ABC
AAA
*/
