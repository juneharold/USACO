#include <iostream>
#include <string>
using namespace std;

int char_to_num[125]={};
string words[55];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, K, ans=0, idx=0;
    cin >> N >> K;
    for (int i=0; i<N; i++) cin >> words[i];

    for (int i=97; i<123; i++) {
        if (i=='a' || i=='n' || i=='t' || i=='i' || i=='c') continue;
        char_to_num[i]=idx;
        idx++;
    }

    for (int i=0; i<(1<<21); i++) {
        int cnt=0;
        for (int j=0; j<21; j++) {
            if (i&(1<<j)) cnt++;
        }

        if (cnt>K-5 || cnt<K-5) continue;

        cnt=0;
        for (int j=0; j<N; j++) {
            bool possible=true;
            for (auto x: words[j]) {
                if (x=='a' || x=='n' || x=='t' || x=='i' || x=='c') continue;
                if (!(i&(1<<char_to_num[x]))) possible=false;
            }

            if (possible) cnt++;
        }

        ans=max(ans, cnt);
    }

    cout << ans;
}
