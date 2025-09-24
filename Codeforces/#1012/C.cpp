#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

void next_seat(pii &p) {
    if (p.sc==0) {
        swap(p.fs, p.sc);
        p.sc++;
    }
    else {
        p.sc--;
        p.fs++;
    }
    while (p.fs%3==0 || p.sc%3==0) {
        if (p.sc==0) {
            swap(p.fs, p.sc);
            p.sc++;
        }
        else {
            p.sc--;
            p.fs++;
        }
    }
}
void next_table(pii &p) {
    if (p.sc==0) {
        swap(p.fs, p.sc);
        p.sc++;
    }
    else {
        p.sc--;
        p.fs++;
    }
}

vector<pair<int, pii>> seats, tables;

set<pii> taken;

void solve() {
    int n; cin >> n;
    int idx1=0, idx2=0;
    for (int i=0; i<n; i++) {
        int a; cin >> a;
        if (a==1) {
            while (taken.find(seats[idx1].sc)!=taken.end()) {
                idx1++;
            }
            cout << seats[idx1].sc.fs << ' ' << seats[idx1].sc.sc << endl;
            taken.insert(seats[idx1].sc);
        }
        else {
            pii table=tables[idx2].sc;
            while (true) {
                //cout << 3*table.fs+1 << ' ' << 3*table.sc+1 << "\n";
                table=tables[idx2].sc;
                
                bool do_next=false;
                pii temp={3*table.fs+1, 3*table.sc+1};
                if (taken.find(temp)!=taken.end()) do_next=true;
                temp={3*table.fs+2, 3*table.sc+1};
                if (taken.find(temp)!=taken.end()) do_next=true;
                temp={3*table.fs+1, 3*table.sc+2};
                if (taken.find(temp)!=taken.end()) do_next=true;
                temp={3*table.fs+2, 3*table.sc+2};
                if (taken.find(temp)!=taken.end()) do_next=true;
                
                if (do_next) idx2++;
                else break;
            }
            cout << 3*table.fs+1 << ' ' << 3*table.sc+1 << endl;
            taken.insert({3*table.fs+1, 3*table.sc+1});
        }
    }
    taken.clear();
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    pii seat={0, 0}, table={0, 0};
    for (int i=1; i<=100000; i++) {
        next_seat(seat);
        int dist=seat.fs+seat.sc;
        if (seat.fs%3==2 && seat.sc%3==2) dist+=2;
        seats.push_back({dist, seat});

        dist=table.fs*3+table.sc*3+2;
        tables.push_back({dist, table});
        next_table(table);
    }
    sort(seats.begin(), seats.end());
    sort(tables.begin(), tables.end());

    //for (auto x: seats) cout << x.sc.fs << ' ' << x.sc.sc << endl;
    //for (auto x: tables) cout << x.sc.fs << ' ' << x.sc.sc << endl;

    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
