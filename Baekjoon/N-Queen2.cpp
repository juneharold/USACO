#include<iostream>
#include <algorithm>
using namespace std;

bool check(vector<int> a) {
    for (int i=0; i<a.size(); i++) {
        for (int j=0; j<i; j++) {
            if (abs(i-j)==abs(a[i]-a[j])) return false;
        }
    }
    return true;
}

int main()
{
    vector<int> yes, no;
    for (int N=4; N<=103; N++) {
        vector<int> v;
        int i=1;
        while (i<=N) {
            v.push_back(i);
            i+=2;
        }
        i=2;
        while (i<=N) {
            v.push_back(i);
            i+=2;
        }
        if (check(v)) {
            yes.push_back(N);
        }
        else {
            no.push_back(N);
        }
    }
    for (int x: yes) cout << x << "\n";
    cout << yes.size();
}