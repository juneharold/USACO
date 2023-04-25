#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int A[30]={}, B[30]={};

int main()
{
    int T; cin >> T;
    while (T--) {
        int n, k; cin >> n >> k;
        string a, b; cin >> a >> b;
        for (int i=0; i<n; i++) {
            A[(int)(a[i]-'a')]++;
            B[(int)(b[i]-'a')]++;
        }

        bool ans=true;
        int cnt=A[0];
        for (int i=0; i<26; i++) {
            if (cnt<B[i]) {
                ans=false;
                break;
            }
            int leftover=cnt-B[i];
            if (leftover%k!=0) {
                ans=false;
                break;
            }
            cnt=A[i+1]+leftover;
        }

        if (ans) cout << "Yes\n";
        else cout << "No\n";

        fill(&A[0], &A[26], 0);
        fill(&B[0], &B[26], 0);
    }
}
