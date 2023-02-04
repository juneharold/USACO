#include <iostream>
#include <string>
#include <vector>
using namespace std;

int l[200005]={}, r[200005]={};

int main()
{
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string s; cin >> s;
        int check[26]={}, cnt=0;
        for (int i=0; i<n; i++) {
            if (check[s[i]-'a']==0) {
                cnt++;
                check[s[i]-'a']=1;
            }
            l[i]=cnt;
        }
        fill(&check[0], &check[26], 0);
        cnt=0;
        for (int i=n-1; i>=0; i--) {
            if (check[s[i]-'a']==0) {
                cnt++;
                check[s[i]-'a']=1;
            }
            r[i]=cnt;
        }

        int ans=0;
        for (int i=0; i<n-1; i++) {
            ans=max(ans, l[i]+r[i+1]);
        }
        cout << ans << "\n";

        for (int i=0; i<=n+1; i++) {
            l[i]=0; r[i]=0;
        }
    }
}