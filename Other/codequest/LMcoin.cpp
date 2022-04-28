#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#define ll long long

int main()
{
    int N; cin >> N;
    for (int t=0; t<N; t++) {
        string s[11];
        for (int i=1; i<=10; i++) cin >> s[i];
        ll time[11];
        for (int i=1; i<=10; i++) cin >> time[i];

        double hash[11]={};
        for (int i=1; i<=10; i++) {
            ll vn=0;
            for (int j=0; j<s[i].size(); j++) vn+=s[i][j]-96;
            hash[i]=(time[i]+vn+i+hash[i-1])*50/147;
        }

        cout << "answer:";
        ll ans=round(hash[10]);
        cout << ans << "\n";
    }
}

/*
2
pepperoni veggie ham peppers cheese olives mushroom chicken beef bacon
2704191000 2704191030 2704191100 2704191130 2704191200 2704191230
2704191300 2704191330 2704191400 2704191430
candy candy salad chips pretzel icecream apple fries cookie sandwich
2602201200 2602201300 2702201200 2702201300 2802201200 2802201300
2902201200 2902201300 0103201200 0103201300
*/
