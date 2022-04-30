#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <map>
#include <set>
using namespace std;
#define f first
#define s second
#define ll long long
#define db double

map<string, int> customer[1000];

int main()
{
    //ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while (T--) {
        map<string, db> p;
        map<string, int> q;
        int N, M; cin >> N >> M;
        for (int i=0; i<N; i++) {
            int x; cin >> x;
            string name; cin >> name;
            db price; cin >> price;
            p[name]=price;
            q[name]=x;
        }

        for (int i=0; i<M; i++) {
            int id; cin >> id;
            string s; cin >> s;
            if (s=="ADD") {
                string item; cin >> item;
                int x; cin >> x;
                if (q[item]<x+customer[id][item]) {
                    cout << "Not enough " << item << " for customer " << id << "\n";
                }
                else {
                    customer[id][item]+=x;
                    cout << "Added " << x << " " << item << " to customer " << id << "'s cart\n";
                }
            }
            else if (s=="REMOVE") {
                string item; cin >> item;
                int x; cin >> x;
                if (customer[id][item]>=x) {
                    customer[id][item]-=x;
                    cout << "Removed " << x << " " << item << " from customer " << id << "'s cart\n";
                }
                else {
                    cout << "Customer " << id << " does not have that many " << item << "s\n";
                }
            }
            else if (s=="CHECKOUT") {
                double total=0;
                set<string> out;
                for (auto item: customer[id]) {
                    string name=item.f;
                    int x=item.s;
                    if (q[name]<x) out.insert(name);
                    else {
                        q[name]-=x;
                        total+=x*p[name];
                    }
                }
                for (auto item: out) cout << "Out of stock of " << item << "\n";
                cout << "Customer " << id << "'s total: $";
                printf("%.2lf", total);
                cout << "\n";
            }
        }

        for (auto item: q) {
            if (item.s==0) continue;
            cout << item.f << " - " << item.s << "\n";
        }

        for (int i=1; i<=1000; i++) customer[i].clear();
    }
}
/*
1
3 8
2 Candy_Bar 1.50
3 Soda_Bottle 1.60
2 Cheese_Pack 2.50
1 ADD Candy_Bar 1
2 ADD Candy_Bar 2
1 ADD Soda_Bottle 3
1 REMOVE Soda_Bottle 1
2 CHECKOUT
1 CHECKOUT
3 ADD Candy_Bar 1
3 ADD Cheese_Pack 2
*/
