#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <iomanip>
#include <bitset>
#include <numeric>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

void solve() {
    int N; cin >> N;
    vector<pii> p(N);
    for (int i=0; i<N; i++) cin >> p[i].fs >> p[i].sc;

    int ans=N+1, cnt=0;

    sort(p.begin(), p.end());
    for (int i=0; i<N; i++) {
        for (int j=i+1; j<N; j++) {
            int x1=p[i].fs, x2=p[j].fs, y1=p[i].sc, y2=p[j].sc, len=x2-x1;
            set<int> s;
            for (int k=0; k<N; k++) if (x1<=p[k].fs && p[k].fs<=x2) s.insert(p[k].sc);
            vector<int> y;
            for (int temp: s) y.push_back(temp);

            int lo=max(y1, y2)-len, hi=min(y1, y2);
            if (lo>hi) continue;
            int l=0, r=-1;
            while (l<y.size() && lo>=y[l]+1) l++; 
			while (r+1<y.size() && lo>=y[r+1]-len) r++; 
            
            while (true) {
                ans++;
                int yl=min(y1, y2), yr=max(y1, y2);
				if (l<=r) yl=min(yl, y[l]), yr=max(yr,y[r]);
				cnt+=(yr-yl==len);
				int bottom=(l<y.size() ? y[l]+1 : 1e9);  
				int top=(r+1<y.size() ? y[r+1]-len : 1e9);
				int dy=min(bottom, top); 
				if (dy>hi) break;
				l+=(bottom==dy);
				r+=(top==dy);
            }
            //cout << ans-N-1 << ' ';
        }
        //cout << endl;
    }
    
    for (int i=0; i<N; i++) swap(p[i].fs, p[i].sc);
    sort(p.begin(), p.end());
    for (int i=0; i<N; i++) {
        for (int j=i+1; j<N; j++) {
            int x1=p[i].fs, x2=p[j].fs, y1=p[i].sc, y2=p[j].sc, len=x2-x1;
            set<int> s;
            for (int k=0; k<N; k++) if (x1<=p[k].fs && p[k].fs<=x2) s.insert(p[k].sc);
            vector<int> y;
            for (int temp: s) y.push_back(temp);

            int lo=max(y1, y2)-len, hi=min(y1, y2);
            if (lo>hi) continue;
            int l=0, r=-1;
            while (l<y.size() && lo>=y[l]+1) l++; 
			while (r+1<y.size() && lo>=y[r+1]-len) r++; 
            
            while (true) {
                ans++;
                int yl=min(y1, y2), yr=max(y1, y2);
				if (l<=r) yl=min(yl, y[l]), yr=max(yr,y[r]);
				cnt+=(yr-yl==len);
				int bottom=(l<y.size() ? y[l]+1 : 1e9);  
				int top=(r+1<y.size() ? y[r+1]-len : 1e9);
				int dy=min(bottom, top); 
				if (dy>hi) break;
				l+=(bottom==dy);
				r+=(top==dy);
            }
            //cout << ans-N-1 << ' ';
        }
        //cout << endl;
    }
    cout << ans-cnt/2 << "\n";
}
/*
when sliding square from left to right, new cows are added/removed. 
- make sure square always contains two cows that decided the size 
- overlap occurs once if x[i]-x[j]==y[i]-y[j]. Count these pairs and subtract. 
*/

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; //cin >> T;
    while (T--) {
        solve();
    }
}
