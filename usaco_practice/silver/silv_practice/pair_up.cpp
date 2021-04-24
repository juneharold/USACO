#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

pair <int, int> ynx[100005];
vector <int> num;

int main()
{
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);
    int n; cin >> n;
    int numcow=0;
    for (int i=0; i<n; i++) {
        cin >> ynx[i].second >>  ynx[i].first;
        numcow+=ynx[i].second;
    }
    sort(ynx, ynx+n); //시간에 따라 오름차순 정리
    for (int i=0; i<n; i++) {
        //cout << i << " " << ynx[i].second << "\n";
    }
    int start=0, end=0;
    for (int i=0; i<n; i++) {
        /*
        ynx[i].first+ynx[n-1-j].first
        앞에서부터 second 합이 뒤에서부터과 겹치면
        */
        
    }
    //for (int i=0; i<num.size(); i++) cout << num[i] << "\n";
    int large=0;
    for (int i=0; i<num.size(); i++) if (num[i]>large) large=num[i];
    cout << large;
}
